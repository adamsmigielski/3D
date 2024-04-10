# Add source directory

set(sources object/object.hpp object/object.cpp object/object.cmake)
target_sources("utilities" PRIVATE ${sources} )
source_group("object" FILES ${sources} )
