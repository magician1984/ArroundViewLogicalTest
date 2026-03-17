#ifndef AVM_SERVICE
#define AVM_SERVICE

#include <avm_common.h>
#include <any>
#include <cstdint>
#include <type_traits>

#include "avm_service_device.h"
#include "avm_service_lifecycle.h"
#include "avm_service_result.h"

struct AvmServiceConfigure_t {
    AvmServiceDeviceList_t deviceList;
    std::any extensionData;
    virtual ~AvmServiceConfigure_t() = default;
};

struct AvmServiceCanvas_t {
    std::any canvas;
    virtual ~AvmServiceCanvas_t() = default;
};

struct AvmServicePreviewParems_t {
    AvmViewMode_e view_mode;
    bool stitch;
    bool pgl;
    bool transparent_enable;
    uint32_t transparent_level;
    virtual ~AvmServicePreviewParems_t() = default;
};

class AvmService {
   public:
    explicit AvmService(AvmServiceConfigure_t configure) : configure_(configure) {}
    ~AvmService() = default;

    virtual auto Init() -> AvmServiceResult_t                           = 0;
    virtual auto Release() -> AvmServiceResult_t                        = 0;
    virtual auto Start(AvmServiceCanvas_t canvas) -> AvmServiceResult_t = 0;
    virtual auto Stop() -> AvmServiceResult_t                           = 0;

    virtual auto UpdatePreviewParams(AvmServicePreviewParems_t params) -> AvmServiceResult_t = 0;
    virtual auto GetCameraDeviceInfoList() -> AvmServiceResult_t                             = 0;

   protected:
    auto GetConfigure() -> AvmServiceConfigure_t { return configure_; }
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
    AvmServiceConfigure_t configure_;
    AvmServiceLifecycle_e currentLifecycle_;
    AvmServiceLifecycle_e previousLifecycle_;
};

#endif /* AVM_SERVICE */
