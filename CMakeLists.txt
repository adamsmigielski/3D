CMAKE_MINIMUM_REQUIRED(VERSION 3.28)


PROJECT(3D)
add_custom_target(3D)

INCLUDE(src/platform/platform.cmake)
INCLUDE(src/src.cmake)
INCLUDE(src/frameworks/frameworks.cmake)

INCLUDE_DIRECTORIES(src)

ADD_SUBDIRECTORY(src)


