set(HEADER_FILES
	Entity.h
	ProjectApp.h
)

set(SOURCE_FILES
	Entity.cpp
	main.cpp
	ProjectApp.cpp
)

add_executable(Project ${HEADER_FILES} ${SOURCE_FILES})

include_directories(../Engine)

target_link_libraries(Project Engine)

file(COPY Assets DESTINATION ${PROJECT_BINARY_DIR}/Project)
file(COPY Assets DESTINATION ${PROJECT_BINARY_DIR}/Debug)
file(COPY Assets DESTINATION ${PROJECT_BINARY_DIR}/Release)