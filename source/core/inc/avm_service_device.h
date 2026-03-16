#ifndef AVM_SERVICE_DEVICE
#define AVM_SERVICE_DEVICE

#include <cstdint>
#include <vector>

template <typename T>
struct AvmServiceDevice_t {
    uint32_t id;
    uint32_t fps;
    uint32_t width;
    uint32_t height;
    T extensionData;
};

template <typename T>
using AvmServiceDeviceList_t = std::vector<AvmServiceDevice_t<T>>;

#endif /* AVM_SERVICE_DEVICE */
