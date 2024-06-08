# Add source directory

set(sources src/frameworks/CmakeLists.txt src/frameworks/frameworks.cmake)
target_sources("3D" PRIVATE ${sources} )
source_group("frameworks" FILES ${sources} )