#ifndef AVM_STATES
#define AVM_STATES

#include "avm_error.h"
#include "avm_view_mode.h"

#include <variant>

enum class AvmStateType_e : uint8_t { kNone = 0, kReady, kRunning, kError };

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
    std::variant<AvmStateNone_t, AvmStateReady_t, AvmStateRunning_t, AvmStateError_t> data;
};

#endif /* AVM_STATES */
