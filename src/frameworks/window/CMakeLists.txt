set(common_sources  
    pch.hpp
    #test.cpp
    window.cpp
    window.hpp
)

set(win64_sources
    win64/PCH.hpp
    win64/Window_class_register.cpp
    win64/Window_class_register.hpp
    win64/window.cpp
    win64/window.hpp
    win64/Dll.hpp
    win64/manager.cpp
)

set(pch PRIVATE win64/pch.hpp)

set(sources ${common_sources} ${win64_sources})

ADD_LIBRARY(window
    ${sources}
)

source_group("common" FILES ${common_sources} )
source_group("win64" FILES ${win64_sources} )

target_precompile_headers(window ${pch})


set_property(TARGET window PROPERTY FOLDER src/frameworks)
set_property(TARGET window PROPERTY CXX_STANDARD 20)
