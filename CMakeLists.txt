cmake_minimum_required(VERSION 3.20)

project(NodeRenderingLibrary
    VERSION 0.1.0
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

find_package(PkgConfig REQUIRED)
pkg_check_modules(SDL3 REQUIRED IMPORTED_TARGET sdl3)

# =========================
# Node Rendering Library
# =========================

file(GLOB_RECURSE NRL_SOURCES
    CONFIGURE_DEPENDS
    "${PROJECT_SOURCE_DIR}/src/*.cpp"
    "${PROJECT_SOURCE_DIR}/include/*.hpp"
)

add_library(nrl ${NRL_SOURCES})

target_include_directories(nrl
    PUBLIC
        ${PROJECT_SOURCE_DIR}/include
)

target_link_libraries(nrl
    PUBLIC
        PkgConfig::SDL3
)

# =========================
# Example
# =========================

file(GLOB_RECURSE EXAMPLE_SOURCES
    CONFIGURE_DEPENDS
    "${PROJECT_SOURCE_DIR}/examples/*.cpp"
)

add_executable(nrl_example ${EXAMPLE_SOURCES})

target_link_libraries(nrl_example
    PRIVATE
        nrl
)