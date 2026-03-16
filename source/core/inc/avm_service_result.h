#ifndef AVM_SERVICE_RESULT
#define AVM_SERVICE_RESULT

#include <variant>
#include <vector>
#include "avm_error.h"
#include "avm_service_device.h"

struct AvmServiceResult_t {
    bool isSucceed;
    std::variant<AvmError_e, AvmServiceDeviceList_t> data;
};

#endif /* AVM_SERVICE_RESULT */
