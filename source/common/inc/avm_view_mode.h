#ifndef AVM_VIEW_MODE
#define AVM_VIEW_MODE

#include <cstdint>

enum class AvmViewMode_e : uint8_t {
    AVM_VIEW_MODE_NONE,
    AVM_VIEW_MODE_FREE,
    AVM_VIEW_MODE_REAR,
    AVM_VIEW_MODE_FRONT,
    AVM_VIEW_MODE_LEFT,
    AVM_VIEW_MODE_RIGHT,
    AVM_VIEW_MODE_ALL
};

#endif /* AVM_VIEW_MODE */
