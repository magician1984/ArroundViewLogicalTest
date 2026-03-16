#ifndef AVM_STATES
#define AVM_STATES

#include "avm_error.h"
#include "avm_view_mode.h"

enum class AvmStateType_e : uint8_t {
    AVM_STATE_NONE,
    AVM_STATE_READY,
    AVM_STATE_RUNNING,
    AVM_STATE_ERROR
};

struct AvmStateNone_t {
    uint64_t timestamp;
};

struct AvmStateReady_t {
    uint64_t timestamp;
};

struct AvmStateRunning_t {
    uint64_t timestamp;
    AvmViewMode_e view_mode;
    bool stitch;
    bool pgl;
    bool transparent_enable;
    uint32_t transparent_level;
};

struct AvmStateError_t {
    uint64_t timestamp;
    uint32_t error_code;
};

struct AvmState_t {
    AvmStateType_e type;
    union {
        AvmStateNone_t none;
        AvmStateReady_t ready;
        AvmStateRunning_t running;
        AvmStateError_t error;
    } state;
};

#endif /* AVM_STATES */
