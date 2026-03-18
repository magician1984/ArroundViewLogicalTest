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
    explicit AvmService(AvmServiceConfigure_t configure);
    ~AvmService();

    auto Init() -> AvmServiceResult_t;
    auto Release() -> AvmServiceResult_t;
    auto Start(AvmServiceCanvas_t canvas) -> AvmServiceResult_t;
    auto Stop() -> AvmServiceResult_t;

    virtual auto UpdatePreviewParams(AvmServicePreviewParems_t params) -> AvmServiceResult_t = 0;
    virtual auto GetCameraDeviceInfoList() -> AvmServiceResult_t                             = 0;

   protected:
    auto GetConfigure() -> AvmServiceConfigure_t;
    auto GetLifecycle() -> AvmServiceLifecycle_e;
    auto GetPreviousLifecycle() -> AvmServiceLifecycle_e;

    virtual auto OnChangeLifecycle(AvmServiceLifecycle_e from, AvmServiceLifecycle_e to)
        -> bool                                                                            = 0;
    virtual auto OnNone(AvmServiceLifecycle_e from) -> AvmServiceLifecycleResult_t         = 0;
    virtual auto OnInitializing(AvmServiceLifecycle_e from) -> AvmServiceLifecycleResult_t = 0;
    virtual auto OnInitialized(AvmServiceLifecycle_e from) -> AvmServiceLifecycleResult_t  = 0;
    virtual auto OnStarting(AvmServiceLifecycle_e from) -> AvmServiceLifecycleResult_t     = 0;
    virtual auto OnStarted(AvmServiceLifecycle_e from) -> AvmServiceLifecycleResult_t      = 0;
    virtual auto OnStopping(AvmServiceLifecycle_e from) -> AvmServiceLifecycleResult_t     = 0;
    virtual auto OnReleasing(AvmServiceLifecycle_e from) -> AvmServiceLifecycleResult_t    = 0;
    virtual auto OnReleased(AvmServiceLifecycle_e from) -> AvmServiceLifecycleResult_t     = 0;
    virtual auto OnError(AvmServiceLifecycle_e from) -> AvmServiceLifecycleResult_t        = 0;

   private:
    AvmServiceConfigure_t configure_;
    AvmServiceLifecycle_e currentLifecycle_;
    AvmServiceLifecycle_e previousLifecycle_;
};

#endif /* AVM_SERVICE */
