"""serve/test_incremental_ids.py - STRATA_SERVE_INCREMENTAL_IDS=1: a GEN line whose ids come in part from a recent
line's text is, byte for byte, the line a full render, a full tokenize and a full join give.

    python -m unittest serve.test_incremental_ids -v
    STRATA_TOKENIZER=<pack>/tokenizer python -m unittest serve.test_incremental_ids -v   (the pack's own tokenizer
        and chat template as well; skipped without one)
"""
from __future__ import annotations

import copy
import hashlib
import io
import json
import os
import queue
import random
import sys
import tempfile
import threading
import unittest
from contextlib import redirect_stdout
from pathlib import Path
from types import SimpleNamespace
from unittest import mock

ROOT = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(ROOT))
sys.path.insert(0, str(ROOT / "tools"))
import serve.server as server  # noqa: E402
from serve import responses as responses_api  # noqa: E402
from serve.frontend import ChatTemplate  # noqa: E402
from serve.server import ByteTokenizer, IdText, MockEngine, Service, StrataEngine  # noqa: E402


def full_line(ids) -> str:
    return ",".join(str(int(t)) for t in ids)       # the GEN line's ids as StrataEngine has always written them


def small(keep: int = 4, near: int = IdText.NEAR):
    """An IdText that keeps lines from 8 ids on, so the tests' short prompts take the incremental path."""
    return type("SmallIdText", (IdText,), {"MIN": 8, "NEAR": near})(keep)


def first_difference(a, b) -> int:
    return next((i for i, (x, y) in enumerate(zip(a, b)) if x != y), min(len(a), len(b)))


def an_id(rng) -> int:
    return rng.randrange(10 ** rng.randint(1, 6)) % 248320     # 1 to 6 digits, as a vocabulary of 248,320 has


class ThinkTokenizer(ByteTokenizer):
    """ByteTokenizer whose <think> / </think> are specials matched even without parse_special (type 4), as in the
    Qwen vocabulary."""
    SPECIALS = ByteTokenizer.SPECIALS + ["<think>", "</think>"]
    ALWAYS = ("<think>", "</think>")


def pack():
    """The pack's tokenizer and chat template (STRATA_TOKENIZER=<pack>/tokenizer), loaded as main() loads them."""
    d = Path(os.environ.get("STRATA_TOKENIZER") or "/nonexistent")
    if not (d / "vocab.json").exists():
        return None
    import strata_tokenizer as ST
    vocab = json.loads((d / "vocab.json").read_text(encoding="utf-8"))
    tokens = [None] * len(vocab)
    for t, i in vocab.items():
        tokens[i] = t
    merges = (d / "merges.txt").read_text(encoding="utf-8").split("\n")
    types = json.loads((d / "token_type.json").read_text())
    tcfg = json.loads((d / "tokenizer.json").read_text(encoding="utf-8"))
    tok = ST.Tokenizer(tokens, merges, types, tcfg.get("pre") or "qwen35", tcfg.get("special_ids") or None)
    tpl = d / "chat_template.jinja"
    return tok, ChatTemplate(tpl if tpl.exists() else ROOT / "serve/chat_template.jinja")


_PACK = None


def the_pack():
    global _PACK
    if _PACK is None:
        _PACK = pack() or False
    return _PACK or None


class Lines(unittest.TestCase):
    def test_shared_is_the_common_start(self):
        rng = random.Random(3)
        for near in (0, 1, 3, 64):
            cls = type("Near", (IdText,), {"NEAR": near})
            for _ in range(3000):
                a = [rng.randrange(4) for _ in range(rng.randrange(0, 200))]
                b = a[:rng.randrange(len(a) + 1)] + [rng.randrange(4) for _ in range(rng.randrange(0, 50))]
                if b and rng.random() < 0.3:
                    b[rng.randrange(len(b))] = rng.randrange(4)
                with self.subTest(near=near, a=a, b=b):
                    self.assertEqual(cls.shared(a, b), first_difference(a, b))

    def test_every_line_is_a_full_join(self):
        """Interleaved conversations whose lines grow, end in another merge of their last ids, are edited, cut back,
        sent again, continued with generated ids or replaced: every line is the full join of its ids."""
        rng = random.Random(11)
        for near in (0, 2, 64):
            cache = small(keep=3, near=near)
            convs: list[list[int]] = [[] for _ in range(5)]
            reused = 0
            for step in range(4000):
                c = rng.randrange(len(convs))
                ids, r = convs[c], rng.random()
                if r < 0.4 or not ids:                                  # the next turn
                    ids = ids + [an_id(rng) for _ in range(rng.randint(1, 40))]
                elif r < 0.55:                                          # the last ids merge with the new text
                    ids = ids[:-rng.randint(1, 3)] + [an_id(rng) for _ in range(rng.randint(1, 20))]
                elif r < 0.65:                                          # an earlier message edited
                    k = rng.randrange(len(ids))
                    ids = ids[:k] + [an_id(rng)] + ids[k + 1:]
                elif r < 0.75:                                          # a shorter conversation
                    ids = ids[:rng.randrange(len(ids) + 1)]
                elif r < 0.85:                                          # the same line again (a retry)
                    pass
                elif r < 0.95:                                          # a request continued with its output
                    ids = ids + [an_id(rng) for _ in range(rng.randint(1, 8))]
                else:                                                   # another conversation in its place
                    ids = []
                convs[c] = ids
                text, n = cache.text(ids if rng.random() < 0.8 else tuple(ids))
                with self.subTest(near=near, step=step):
                    self.assertEqual(text, full_line(ids))
                    self.assertTrue(n == 0 or cache.MIN <= n <= len(ids))
                reused += n > 0
            self.assertGreater(reused, 1500)
            self.assertLessEqual(len(cache.entries), 3)

    def test_short_lines_are_formatted_in_full_and_not_kept(self):
        cache = IdText()
        ids = list(range(248000, 248000 + IdText.MIN - 1))
        self.assertEqual(cache.text(ids), (full_line(ids), 0))
        self.assertEqual(cache.entries, [])

    def test_the_callers_list_may_change_after_the_send(self):
        cache = small()
        ids = list(range(1000, 1100))
        cache.text(ids)
        ids[50] = 5                                 # the caller's list, changed in place after it was sent
        ids.append(7)
        self.assertEqual(cache.text(ids), (full_line(ids), 50))

    def test_a_merge_across_the_old_end(self):
        """The text grew but its last ids did not stay: "hello wor" + "ld" is not the ids of "hello wor" + more."""
        got = the_pack()
        if got is None:
            self.skipTest("no pack tokenizer (STRATA_TOKENIZER)")
        tok = got[0]
        head = "<|im_start|>user\n" + "a long question about the code, line by line " * 600
        old = tok.encode(head + "hello wor", parse_special=True)
        new = tok.encode(head + "hello world and more", parse_special=True)
        self.assertNotEqual(new[:len(old)], old)
        cache = IdText()
        cache.text(old)
        line, n = cache.text(new)
        self.assertEqual(line, full_line(new))
        self.assertEqual(n, first_difference(old, new))
        self.assertLess(n, len(old))


class FakeVision:
    """An image encoder: each picture is a few rows of embeddings (how many depends on the picture)."""

    def __init__(self, d):
        self.dir = Path(d)

    def encode(self, source):
        p = self.dir / (hashlib.sha256(source.encode()).hexdigest()[:32] + ".sve")
        p.write_bytes(b"rows")
        return p, 1 + sum(map(ord, source)) % 5


QUOTED = ["</think>", "<think>", "<|im_end|>", "<|im_start|>", "<tool_call>", "<|image_pad|>", "<|vision_start|>",
          "<|im_sta", "</thi"]
WORDS = ["hello ", "world", " wor", "ld", "é你 ", "def f(x):\n", "    return x\n", "\n\n", " ", "123", "4.5", "->",
         "tool ", "x" * 9, "  ", "\t"]
TOOLS = [{"type": "function", "function": {"name": f"tool_{i}", "description": "does a thing " * 3,
          "parameters": {"type": "object", "properties": {"path": {"type": "string"}, "n": {"type": "integer"}},
                         "required": ["path"]}}} for i in range(3)]


def words(rng, k=10) -> str:
    return "".join(rng.choice(QUOTED if rng.random() < 0.15 else WORDS) for _ in range(rng.randint(1, k)))


class Served(unittest.TestCase):
    """The server's own path (Service.prepare: the template, #537's literals, #567's incremental tokenize, a forced
    call, pictures) feeding one IdText, against a full render, a full tokenize and a full join each time."""

    def services(self, tok, template, vision_dir):
        def one():
            return Service(MockEngine(tok, "ok", max_context=1 << 22), tok, template, vision=FakeVision(vision_dir))
        svc, ref = one(), one()
        ref.prompts = None                                  # the reference: a full encode every time
        self.assertIsNotNone(svc.prompts)
        return svc, ref

    def check(self, svc, ref, cache, msgs, tools, kw, force, out_ids, tag):
        got, _, _ = svc.prepare(copy.deepcopy(msgs), tools, dict(kw), 64, force=force)
        want, _, _ = ref.prepare(copy.deepcopy(msgs), tools, dict(kw), 64, force=force)
        for s in (svc, ref):
            if s.embeddings.path is not None:
                Path(s.embeddings.path).unlink(missing_ok=True)
        line, n = cache.text(got)
        with self.subTest(tag):
            self.assertEqual(line, full_line(want))
        if out_ids:                                         # the request continued with its output (a batch slot)
            more = got + out_ids
            with self.subTest(tag + " continued"):
                self.assertEqual(cache.text(more)[0], full_line(more))
        return n

    def chat_conversations(self, tok, template, seed, convs=40, turns=8):
        rng = random.Random(seed)
        reused = lines = 0
        with tempfile.TemporaryDirectory() as d:
            svc, ref = self.services(tok, template, d)
            cache = small(keep=3)
            for conv in range(convs):
                svc.effort_end = ref.effort_end = rng.random() < 0.5     # #458: the three-render path
                tools = TOOLS if rng.random() < 0.5 else None
                msgs = [{"role": "system", "content": words(rng)}] if rng.random() < 0.7 else []
                msgs.append({"role": "user", "content": words(rng, 30)})
                for turn in range(turns):
                    kw = {}
                    if rng.random() < 0.25:
                        kw["enable_thinking"] = False
                    elif rng.random() < 0.2:
                        kw["reasoning_effort"] = rng.choice(["low", "medium"])
                    if rng.random() < 0.3:
                        kw["preserve_thinking"] = rng.random() < 0.5    # earlier turns' reasoning kept or dropped
                    force = "<tool_call>\n<function=tool_1>\n" if tools and kw.get("enable_thinking") is False \
                        and rng.random() < 0.3 else None
                    out = [an_id(rng) % 256 for _ in range(rng.randint(1, 6))] if rng.random() < 0.3 else None
                    n = self.check(svc, ref, cache, msgs, tools, kw, force, out, f"seed {seed} conv {conv} turn {turn}")
                    reused += n > 0
                    lines += 1
                    # the reply, as the client sends it back next turn
                    reply = {"role": "assistant", "content": words(rng, 20) if rng.random() < 0.8 else ""}
                    if rng.random() < 0.5:
                        reply["reasoning_content"] = words(rng, 20)
                    calls = rng.randint(1, 3) if tools and rng.random() < 0.4 else 0
                    if calls:
                        reply["tool_calls"] = [{"type": "function", "function": {
                            "name": f"tool_{rng.randrange(3)}",
                            "arguments": {"path": words(rng, 3), "n": rng.randrange(100)}}} for _ in range(calls)]
                    msgs.append(reply)
                    for _ in range(calls):
                        content = words(rng, 30)
                        if rng.random() < 0.15:                 # a picture a tool returned
                            content = [{"type": "text", "text": content}, {"type": "image", "source": words(rng, 2)}]
                        msgs.append({"role": "tool", "content": content})
                    user = words(rng, 30)
                    if rng.random() < 0.15:                     # a picture in the user's turn
                        user = [{"type": "image", "source": words(rng, 2)}, {"type": "text", "text": user}]
                    msgs.append({"role": "user", "content": user})
                    r = rng.random()
                    if r < 0.08 and msgs[0]["role"] == "system":   # a new system prompt
                        msgs[0] = {"role": "system", "content": words(rng)}
                    elif r < 0.16:                              # an earlier message edited by the client
                        m = rng.choice([m for m in msgs if isinstance(m.get("content"), str)])
                        m["content"] = m["content"] + rng.choice(WORDS) if rng.random() < 0.5 else words(rng)
                    elif r < 0.2 and len(msgs) > 3:             # a shorter conversation
                        msgs = msgs[:rng.randrange(2, len(msgs))]
                        if msgs[-1]["role"] != "user":
                            msgs.append({"role": "user", "content": words(rng)})
        return reused, lines

    def test_chat_conversations_byte_tokenizer(self):
        reused, lines = self.chat_conversations(ThinkTokenizer(), ChatTemplate(ROOT / "serve/chat_template.jinja"), 567)
        self.assertGreater(reused, lines // 2)

    def test_chat_conversations_pack_tokenizer(self):
        got = the_pack()
        if got is None:
            self.skipTest("no pack tokenizer (STRATA_TOKENIZER)")
        reused, lines = self.chat_conversations(got[0], got[1], 1189, convs=30)
        self.assertGreater(reused, lines // 2)

    def responses_conversations(self, tok, template, seed, convs=30, turns=6):
        """/v1/responses: input items through responses.py's conversion, then the same prepare()."""
        rng = random.Random(seed)
        reused = lines = 0
        tools = [{"type": "function", "name": f"tool_{i}", "description": "does a thing",
                  "parameters": {"type": "object", "properties": {"path": {"type": "string"}}}} for i in range(3)]
        with tempfile.TemporaryDirectory() as d:
            svc, ref = self.services(tok, template, d)
            cache = small(keep=3)
            for conv in range(convs):
                req = {"instructions": words(rng), "input": [{"type": "message", "role": "user", "content": words(rng, 30)}],
                       "tools": tools if rng.random() < 0.6 else []}
                for turn in range(turns):
                    req["reasoning"] = {"effort": rng.choice([None, "none", "low", "medium", "high"])}
                    msgs = responses_api.input_messages(copy.deepcopy(req))
                    shown, _, _ = responses_api.request_tools(req)
                    kw = responses_api.template_kwargs(req, {})
                    n = self.check(svc, ref, cache, msgs, shown, kw, None, None, f"seed {seed} conv {conv} turn {turn}")
                    reused += n > 0
                    lines += 1
                    items = req["input"]
                    if rng.random() < 0.5:
                        items.append({"type": "reasoning", "content": [{"type": "reasoning_text", "text": words(rng, 20)}]})
                    if req["tools"] and rng.random() < 0.5:
                        for k in range(rng.randint(1, 2)):
                            items.append({"type": "function_call", "name": f"tool_{rng.randrange(3)}", "call_id": f"c{turn}{k}",
                                          "arguments": json.dumps({"path": words(rng, 3)})})
                        for k in range(rng.randint(1, 2)):
                            items.append({"type": "function_call_output", "call_id": f"c{turn}{k}", "output": words(rng, 20)})
                    else:
                        items.append({"type": "message", "role": "assistant", "content": words(rng, 20)})
                    items.append({"type": "message", "role": "user", "content": words(rng, 20)})
                    if rng.random() < 0.1:
                        req["instructions"] = words(rng)            # new instructions: the system prompt changes
        return reused, lines

    def test_responses_conversations_byte_tokenizer(self):
        reused, lines = self.responses_conversations(ThinkTokenizer(), ChatTemplate(ROOT / "serve/chat_template.jinja"), 924)
        self.assertGreater(reused, lines // 2)

    def test_responses_conversations_pack_tokenizer(self):
        got = the_pack()
        if got is None:
            self.skipTest("no pack tokenizer (STRATA_TOKENIZER)")
        reused, lines = self.responses_conversations(got[0], got[1], 2228, convs=20)
        self.assertGreater(reused, lines // 2)


class EngineLine(unittest.TestCase):
    """What StrataEngine writes to the engine's stdin: the same bytes with the switch off and on."""

    def written(self, prompts, on: bool) -> tuple[str, str]:
        engine = StrataEngine.__new__(StrataEngine)
        engine.proc = SimpleNamespace(stdin=io.StringIO(), poll=lambda: None)
        engine.lines = queue.Queue()
        engine.can_stop = False
        engine.max_context = 262144
        out = io.StringIO()
        with mock.patch.object(server, "INCREMENTAL_IDS", on), mock.patch.object(IdText, "MIN", 8), \
                redirect_stdout(out):
            for ids, sampling in prompts:
                engine.lines.put("T 7")
                engine.lines.put("DONE 1 %d 0 1 stop 0 0 0" % len(ids))
                self.assertEqual(list(engine.generate(ids, 16, sampling, threading.Event())), [7])
        return engine.proc.stdin.getvalue(), out.getvalue()

    def test_the_same_bytes_with_the_switch_on(self):
        rng = random.Random(5)
        ids = [an_id(rng) for _ in range(50)]
        prompts = [(ids, {}), (ids + [1, 2, 3], {"temperature": 0.7, "seed": 3}), (ids[:-1] + [9, 9], {}),
                   (ids[:20], {}), (list(reversed(ids)), {}), (ids + [1, 2, 3, 4], {"top_k": 20})]
        off, said_off = self.written(prompts, False)
        on, said_on = self.written(prompts, True)
        self.assertEqual(on, off)
        self.assertEqual(off.count("\n"), len(prompts))
        self.assertEqual(said_off, "")
        self.assertIn("[strata] GEN line: 50 of 53 ids from a recent line's text", said_on)


if __name__ == "__main__":
    unittest.main()
