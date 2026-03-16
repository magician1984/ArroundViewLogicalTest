#ifndef AVM_SERVICE
#define AVM_SERVICE

#include <avm_common.h>
#include <cstdint>
#include <type_traits>

#include "avm_service_device.h"
#include "avm_service_lifecycle.h"
#include "avm_service_result.h"

template <typename T>
struct AvmServiceConfigure_t {
        virtual ~AvmServiceConfigure_t() = default;
};

struct AvmServiceStartParams_t {
    virtual ~AvmServiceStartParams_t() = default;
};

struct AvmServicePreviewParems_t {};

template <typename T, typename P>
class AvmService {
    static_assert(std::is_base_of_v<AvmServiceConfigure_t, T>,
                  "T must be derived from AvmServiceConfigure");
    static_assert(std::is_base_of_v<AvmServiceStartParams_t, P>,
                  "P must be derived from avm_service_start_params");

   public:
    explicit AvmService(T configure) : configure_(configure) {}
    ~AvmService() = default;

    virtual auto Init() -> AvmServiceResult_t          = 0;
    virtual auto Release() -> AvmServiceResult_t       = 0;
    virtual auto Start(P params) -> AvmServiceResult_t = 0;
    virtual auto Stop() -> AvmServiceResult_t          = 0;

    virtual auto UpdatePreviewParams(AvmServicePreviewParems_t params) -> AvmServiceResult_t = 0;
    virtual auto GetCameraDeviceInfoList() -> AvmServiceResult_t                             = 0;

   protected:
    auto GetConfigure() -> T { return configure_; }
    auto GetLifecycle() -> AvmServiceLifecycle_e { return currentLifecycle_; }
    auto GetPreviousLifecycle() -> AvmServiceLifecycle_e { return previousLifecycle_; }
    auto SetLifecycle(AvmServiceLifecycle_e lifecycle) -> bool {
        if (currentLifecycle_ == lifecycle) {
            return false;
        }
        previousLifecycle_ = currentLifecycle_;
        currentLifecycle_  = lifecycle;
        return true;
    }

   private:
    T configure_;
    AvmServiceLifecycle_e currentLifecycle_;
    AvmServiceLifecycle_e previousLifecycle_;
};

#endif /* AVM_SERVICE */
