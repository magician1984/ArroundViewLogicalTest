#ifndef AVM_ERROR
#define AVM_ERROR

#include <cstdint>

enum class AvmError_e : uint8_t { kNone = 0, kCameraFailure = 1, kModelFailure = 2 };

#endif /* AVM_ERROR */
