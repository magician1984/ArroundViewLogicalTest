#ifndef AVM_VIEW_MODE
#define AVM_VIEW_MODE

#include <cstdint>

enum class AvmViewMode_e : uint8_t {
    kNone  = 0,
    kFree  = 1,
    kRear  = 2,
    kFront = 3,
    kLeft  = 4,
    kRight = 5,
    kAll   = 6
};

#endif /* AVM_VIEW_MODE */
