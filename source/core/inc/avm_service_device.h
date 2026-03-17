#ifndef AVM_SERVICE_DEVICE
#define AVM_SERVICE_DEVICE

#define DEVICE_VALUE_NOT_SET 0xFFFFFFFF

#include <any>
#include <cstdint>
#include <vector>

struct AvmServiceDevice_t {
    uint32_t id     = DEVICE_VALUE_NOT_SET;
    uint32_t fps    = DEVICE_VALUE_NOT_SET;
    uint32_t width  = DEVICE_VALUE_NOT_SET;
    uint32_t height = DEVICE_VALUE_NOT_SET;
    std::any extensionData;
};

using AvmServiceDeviceList_t = std::vector<AvmServiceDevice_t>;

#endif /* AVM_SERVICE_DEVICE */
