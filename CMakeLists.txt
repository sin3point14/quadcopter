cmake_minimum_required (VERSION 3.5)

project(
    quadcopter
    LANGUAGES CXX C
    VERSION 1.0
)

set_property(GLOBAL PROPERTY USE_FOLDERS ON)
set(CMAKE_CXX_STANDARD 17)

set(QUADCOPTER_INCLUDES CACHE INTERNAL "")

add_subdirectory(vendor)
add_subdirectory(src)
