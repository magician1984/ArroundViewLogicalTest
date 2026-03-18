#include <avm_service.h>

AvmService::AvmService(AvmServiceConfigure_t configure) : configure_(configure) {}

AvmService::~AvmService() {}

auto AvmService::GetConfigure() -> AvmServiceConfigure_t {
    return configure_;
}

auto AvmService::GetLifecycle() -> AvmServiceLifecycle_e {
    return currentLifecycle_;
}

auto AvmService::GetPreviousLifecycle() -> AvmServiceLifecycle_e {
    return previousLifecycle_;
}
