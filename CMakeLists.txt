cmake_minimum_required(VERSION 3.10)

project(AVM 
        VERSION 1.0.0 
        LANGUAGES CXX)

option(MOCK_DEVICE_ENABLE "Use Mock Device", ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

message(STATUS "Project Name: ${PROJECT_NAME}")
message(STATUS "Project Version: ${PROJECT_VERSION}")

add_subdirectory(source)