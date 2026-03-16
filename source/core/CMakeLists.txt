add_library(avm_core INTERFACE)

target_include_directories(avm_core
    INTERFACE
    {CMAKE_CURRENT_SOURCE_DIR}/inc)

target_link_libraries(avm_core INTERFACE avm_common)