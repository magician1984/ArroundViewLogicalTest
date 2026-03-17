#ifndef AVM_CAMERA_LOCATION
#define AVM_CAMERA_LOCATION

#include <cstdint>

enum class AvmCameraLocation : uint8_t {
    kInvalid = 0,
    kFront   = 1,
    kRear    = 2,
    kLeft    = 3,
    kRight   = 4
};

#endif /* AVM_CAMERA_LOCATION */
