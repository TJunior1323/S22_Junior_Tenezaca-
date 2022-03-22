set(HEADER_FILES 
	Engine.h
	EngineApp.h
	EngineUtil.h
	GameWindow.h
	WindowImplementation.h
	specificGLFW/GlfwWindow.h
	)

set(SOURCE_FILES 
	EngineApp.cpp
	GameWindow.cpp
	specificGLFW/GlfwWindow.cpp
	)

add_library(Engine SHARED ${HEADER_FILES} ${SOURCE_FILES})

add_definitions(-DENGINE_LIB)
add_definitions(-DENGINE_DEBUG)

include_directories(../glfw/include)
include_directories(../Engine)

target_precompile_headers(Engine PRIVATE pch.h)

target_link_libraries(Engine glfw)