# Add source directory

set(sources src/CmakeLists.txt src/src.cmake)
target_sources("3D" PRIVATE ${sources} )
source_group("src" FILES ${sources} )