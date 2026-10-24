#pragma once

#include "strata/core/conversation_cache.hpp"
#include "strata/core/conversation_file.hpp"
#include "strata/core/layer.hpp"
#include "strata/core/session.hpp"

#include <string>

namespace strata::core {

// Caller synchronizes the device before saving, and after restoring all layers.
// include_index is false for the draft layer (its attention has no indexer).
size_t conversation_kv_bytes(const QsaState& state, const ModelGeometry& g, int64_t upto, bool include_index);
// A nonzero unchanged_tokens is valid only for storage retained from an image
// actually restored into this session, bounded by every subsequent rewrite.
// Equal token IDs alone do not establish that its K/V bytes are unchanged.
bool conversation_kv_save(ConversationKv& image, const QsaState& state, const ModelGeometry& g,
                          int64_t upto, bool include_index, std::string& error,
                          int64_t unchanged_tokens = 0, size_t* reused_bytes = nullptr);
bool conversation_kv_capture_bytes(const ConversationKv& image, const QsaState& state, const ModelGeometry& g,
                                   int64_t upto, bool include_index, size_t& bytes, std::string& error);
// No CUDA calls or destination writes. Used for whole-session prevalidation.
bool conversation_kv_validate(const ConversationKv& image, const QsaState& state, const ModelGeometry& g,
                              int64_t upto, bool include_index, std::string& error);
bool conversation_kv_restore(const ConversationKv& image, const QsaState& state, const ModelGeometry& g,
                             int64_t upto, bool include_index, std::string& error);
// conversation_kv_save(from) + conversation_kv_restore(to) without a host image, for two states of the same layout.
// The copies are complete on return; the residency refresh is queued on the legacy stream like the restore's.
// `queued`: the copies are only queued on the private copy stream, the refresh is ordered after them on the device,
// and the caller synchronizes the device before it reads or writes either state.
bool conversation_kv_copy(const QsaState& from, const QsaState& to, const ModelGeometry& g,
                          int64_t upto, bool include_index, std::string& error, bool queued = false);
// The first `upto` tokens of an image captured at `captured` tokens: the leading bytes of each buffer (cells come
// first in the identity layout, as conversation_kv_save takes them), the image untouched.  Cells and indexer rows
// past `upto` in the restored pages hold the image's later tokens until a request writes them, as after a whole
// restore followed by a rewind to a checkpoint.
bool conversation_kv_restore_prefix(const ConversationKv& image, const QsaState& state, const ModelGeometry& g,
                                    int64_t captured, int64_t upto, bool include_index, std::string& error);
// Diagnostic read-back after a synchronized restore. Uses 64 KiB of stack
// workspace, compares authoritative bytes and resident draft-ring pages, and
// fingerprints the authoritative payload only. Never changes model state.
bool conversation_kv_verify(const ConversationKv& image, const QsaState& state, const ModelGeometry& g,
                            int64_t upto, bool include_index, uint64_t& fingerprint, std::string& error);
// Disk save without a host copy: the layer's authoritative K/V as a streamed source (same bytes and metadata as
// conversation_kv_save).  Caller synchronizes the device first and keeps the state untouched while it is read.
bool conversation_kv_source(SessionKvSource& source, const QsaState& state, const ModelGeometry& g,
                            int64_t upto, bool include_index, std::string& error);
// The bytes of each K/V part (k, v, k_scale, v_scale, pooled) a snapshot of `upto` tokens holds: no state read.
bool conversation_kv_part_sizes(const QsaState& state, const ModelGeometry& g, int64_t upto, bool include_index,
                                std::array<uint64_t, 5>& sizes, std::string& error);
// Disk sessions: the read limits this session can ever restore - its geometry and layer range, at most
// min(max_tokens, its cells) tokens, `max_checkpoints` checkpoints, the exact running-state sizes and the K/V part
// sizes at that many tokens - so session_file_read refuses an oversized or foreign file before it allocates.
bool conversation_session_read_limits(SessionReadLimits& limits, const SessionState& session, const ModelGeometry& g,
                                      const QsaState& draft, uint64_t max_tokens, uint64_t max_checkpoints,
                                      std::string& error);

struct ConversationStateSizes {
    size_t gdn = 0, ple = 0, tail = 0, dead = 0, block_pos = 0;
};
/// Whole-model sizes: `gdn` covers every GDN layer, the indexer sizes are per QSA layer.
bool conversation_state_sizes(const ModelGeometry& g, ConversationStateSizes& sizes, std::string& error);
/// The same for one session's layer carve (#216): `gdn` covers its `gdn_alloc` rows; the per-QSA-layer sizes
/// apply to each owned state [qsa_ord0, qsa_ord0 + qsa_alloc).  Rejects an inconsistent carve.  Checkpoints,
/// snapshots and their validation all use this: a session saves and restores only the state it owns.
bool conversation_session_sizes(const ModelGeometry& g, const SessionState& session, ConversationStateSizes& sizes,
                                std::string& error);
bool conversation_checkpoint_validate(const ConversationCheckpoint& checkpoint, const SessionState& session,
                                      const ModelGeometry& g, std::string& error);
bool conversation_checkpoint_save(ConversationCheckpoint& checkpoint, const SessionState& session,
                                  const ModelGeometry& g, std::string& error);
bool conversation_checkpoint_restore(const ConversationCheckpoint& checkpoint, SessionState& session,
                                     const ModelGeometry& g, std::string& error);
// conversation_checkpoint_save(from) + conversation_checkpoint_restore(to) of `ids` without a host image, for two
// sessions carved alike on the same device; the caller synchronizes the device before (as for the restore).
// `queued`: the copies are only queued (the private copy stream), and the caller synchronizes the device after too.
bool conversation_checkpoint_copy(const SessionState& from, SessionState& to, const std::vector<int32_t>& ids,
                                  const ModelGeometry& g, std::string& error, bool queued = false);

// STRATA_CKPT_ASYNC (generate.cpp): a checkpoint's running state copied out through one contiguous host image (a
// pinned staging buffer) on the caller's stream, then into the checkpoint's vectors.  The image holds the parts
// conversation_checkpoint_save copies, at the offsets below: first the ones a verify window's run writes (the PLE
// history, the indexer tails, dead keys and block positions), last the GDN rows, which only a commit or a one-token
// window writes.  Each part starts on a 256-byte boundary.
struct ConversationCheckpointLayout {
    size_t layers = 0;                                   ///< the session's own QSA layers
    size_t gdn = 0, ple = 0, tail = 0, dead = 0, block_pos = 0;   ///< bytes: gdn and ple whole, the rest per layer
    size_t ple_at = 0, tails_at = 0, dead_at = 0, block_pos_at = 0, gdn_at = 0, bytes = 0;
};
/// The image of a checkpoint of `tokens` tokens of this session (the checks conversation_checkpoint_save makes).
bool conversation_checkpoint_layout(const SessionState& session, const ModelGeometry& g, size_t tokens,
                                    ConversationCheckpointLayout& layout, std::string& error);
/// Queues the copies of the running state into `staging` (layout.bytes) on `stream`: the small parts, then
/// `small_done` is recorded, then the GDN rows.  Nothing waits.  The caller has synchronized the device, records its
/// own event for the GDN rows after this, and keeps every writer of the state behind the copies: a window's run
/// behind `small_done`, a commit or a one-token window behind the GDN rows.
bool conversation_checkpoint_queue(void* staging, const ConversationCheckpointLayout& layout, const SessionState& session,
                                   cudaStream_t stream, cudaEvent_t small_done, std::string& error);
/// Host only, no CUDA call: sizes the checkpoint's vectors as conversation_checkpoint_save does (a pooled checkpoint's
/// already are: nothing is filled) and copies in the small parts of a staging image the queue's copies have filled,
/// or with `gdn_rows` the GDN rows.  Every byte of each part's vector is overwritten.
void conversation_checkpoint_unstage(ConversationCheckpoint& checkpoint, const void* staging,
                                     const ConversationCheckpointLayout& layout, bool gdn_rows);

struct ConversationView {
    const std::vector<int32_t>& ids;
    const std::vector<ConversationImageKey>& images;
    const std::vector<ConversationCheckpoint>& checkpoints;
    bool cvec;
};
bool conversation_snapshot_bytes(const ConversationView& view, const SessionState& session,
                                 const ModelGeometry& g, const QsaState& draft, size_t& bytes, std::string& error);
bool conversation_snapshot_capture_bytes(const ConversationKvReuse& reuse, const ConversationView& view,
                                         const SessionState& session, const ModelGeometry& g,
                                         const QsaState& draft, size_t& bytes, std::string& error);
// The capture estimate includes retained capacity and transient segment directories;
// only estimate - reuse.bytes() requires additional physical RAM. Capture consumes
// the uniquely owned reusable buffers, including on failure.
// Caller admits the estimate before invoking capture. Allocation failures propagate
// to the RAM policy; the active session is never modified by capture.
bool conversation_snapshot_save(SavedConversation& image, const ConversationView& view,
                                const SessionState& session, const ModelGeometry& g,
                                const QsaState& draft, std::string& error,
                                ConversationKvReuse reuse = {}, size_t* reused_bytes = nullptr);
// Disk save without capturing the K/V on the host: `meta` gets everything but the K/V (running state copied,
// checkpoints as given by the view), `sources` one streamed source per QSA layer then the draft.  Caller has
// synchronized and must not run the session until the file is written.
bool conversation_snapshot_sources(SavedConversation& meta, std::vector<SessionKvSource>& sources,
                                   const ConversationView& view, const SessionState& session,
                                   const ModelGeometry& g, const QsaState& draft, std::string& error);
bool conversation_snapshot_validate(const SavedConversation& image, const SessionState& session,
                                    const ModelGeometry& g, const QsaState& draft, std::string& error);
enum class ConversationRestore { restored, invalid, transfer_failed };
// Invalid images are rejected before any CUDA call/write. Transfer failure may
// leave partial state: caller MUST NOT continue inference from that session.
ConversationRestore conversation_snapshot_restore(const SavedConversation& image, SessionState& session,
                                                   const ModelGeometry& g, const QsaState& draft,
                                                   std::string& error);
// The K/V of the image's first `upto` tokens (main layers and the draft layer), not its running state: the caller
// mounts a checkpoint taken at `upto`.  For a checkpoint of a parked conversation that a new conversation starts
// with, while the parked one stays where it is (ConversationCache::borrows).  Same failure contract as above.
ConversationRestore conversation_snapshot_restore_prefix(const SavedConversation& image, int64_t upto,
                                                          SessionState& session, const ModelGeometry& g,
                                                          const QsaState& draft, std::string& error);

// The same with `draft == nullptr`: an image WITHOUT the draft layer's K/V (kv holds the session's own QSA layers
// only).  A layer split's later stages park this way; the draft ring is saved once, with the first stage's image.
// An image is validated and restored with the same kind of call it was saved with (a K/V layer count mismatch is
// rejected as invalid).
bool conversation_snapshot_bytes(const ConversationView& view, const SessionState& session, const ModelGeometry& g,
                                 const QsaState* draft, size_t& bytes, std::string& error);
bool conversation_snapshot_capture_bytes(const ConversationKvReuse& reuse, const ConversationView& view,
                                         const SessionState& session, const ModelGeometry& g, const QsaState* draft,
                                         size_t& bytes, std::string& error);
bool conversation_snapshot_save(SavedConversation& image, const ConversationView& view, const SessionState& session,
                                const ModelGeometry& g, const QsaState* draft, std::string& error,
                                ConversationKvReuse reuse = {}, size_t* reused_bytes = nullptr);
bool conversation_snapshot_validate(const SavedConversation& image, const SessionState& session,
                                    const ModelGeometry& g, const QsaState* draft, std::string& error);
ConversationRestore conversation_snapshot_restore(const SavedConversation& image, SessionState& session,
                                                   const ModelGeometry& g, const QsaState* draft, std::string& error);
ConversationRestore conversation_snapshot_restore_prefix(const SavedConversation& image, int64_t upto,
                                                          SessionState& session, const ModelGeometry& g,
                                                          const QsaState* draft, std::string& error);

} // namespace strata::core
