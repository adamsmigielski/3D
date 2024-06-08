set(common_sources  
	pch.cpp
	pch.hpp
	test.cpp
	window.cpp
	window.hpp
)

set(win64_sources
	win64/PCH.hpp
	win64/Window_class_register.cpp
	win64/Window_class_register.hpp
	win64/Window_windows.cpp
	win64/Window_windows.hpp
	win64/Dll.hpp
	win64/Manager_windows.cpp
	win64/Manager_windows.hpp
	win64/PCH.cpp
)

set(sources ${common_sources} ${win64_sources})

ADD_LIBRARY(window
	${sources}
)

source_group("common" FILES ${common_sources} )
source_group("win64" FILES ${win64_sources} )


set_property(TARGET window PROPERTY FOLDER src/frameworks)
