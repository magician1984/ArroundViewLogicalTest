#ifndef AVM_ERROR
#define AVM_ERROR

#include <cstdint>

enum class AvmError_e : uint8_t {
    AVM_ERROR_NONE,
    AVM_ERROR_CAMERA_FAILURE,
    AVM_ERROR_MODEL_FAILURE
};

#endif /* AVM_ERROR */
