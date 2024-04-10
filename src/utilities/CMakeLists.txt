ADD_LIBRARY(utilities
    pch.hpp
    pch.cpp
    utilities.cpp)

INCLUDE(object/object.cmake)

target_include_directories(utilities PRIVATE .)

add_dependencies(3D utilities)


