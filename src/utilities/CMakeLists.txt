set(utilities_sources pch.hpp pch.cpp)
set(basic_sources basic/Log.hpp basic/Align.hpp basic/Assert.hpp basic/BreakToDebug.hpp basic/CallConvention.hpp basic/Log.cpp)
set(containers_sources containers/Singleton.hpp)
set(object_sources  object/Collection.hpp object/object.hpp object/object.cpp  object/Owner.hpp)


ADD_LIBRARY(utilities
    ${utilities_sources}
    ${basic_sources}
    ${containers_sources}
    ${object_sources})

source_group(utilities FILES ${utilities_sources} )
source_group(basic FILES ${basic_sources} )
source_group(containers FILES ${containers_sources} )
source_group(object FILES ${object_sources} )

set_property(TARGET utilities PROPERTY FOLDER src)
set_property(TARGET utilities PROPERTY CXX_STANDARD 20)
