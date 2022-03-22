add_library(Engine SHARED Engine.h EngineApp.h EngineUtil.h EngineApp.cpp)

add_definitions(-DENGINE_LIB)
add_definitions(-DENGINE_DEBUG)

target_precompile_headers(Engine PRIVATE pch.h)