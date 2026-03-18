#ifndef AVM_SERVICE_LIFECYCLE
#define AVM_SERVICE_LIFECYCLE

#include <cstdint>

/***
 * Lifecycle flow:
 *  None -> Initializing -> Initialized -> Starting -> Started -> Stopping -> Initialized ->
 *  Releasing -> Released
 */

enum class AvmServiceLifecycle_e : uint8_t {
    kNone = 0,
    kInitializing,
    kInitialized,
    kStarting,
    kStarted,
    kStopping,
    kReleasing,
    kReleased,
    kError
};

struct AvmServiceLifecycleResult_t {
    AvmServiceLifecycle_e current;
    AvmServiceLifecycle_e next;
    bool isSucceed;
};

#endif /* AVM_SERVICE_LIFECYCLE */
