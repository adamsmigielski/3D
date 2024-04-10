SET (PLATFORM "win64")
INCLUDE_DIRECTORIES(src/platform/${PLATFORM})

set(sources src/platform/${PLATFORM}/platform.hpp src/platform/platform.cmake)
target_sources("3D" PRIVATE ${sources} )
source_group("platform" FILES ${sources} )
