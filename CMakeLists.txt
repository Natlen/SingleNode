cmake_minimum_required(VERSION 3.26)

set(TARGET_NAME "SingleNode")

set(COMPILER_ARGS 
    "/std:c++14"
)

add_compile_options( ${COMPILER_ARGS} )

file(GLOB TARGET_SOURCES
    "source/SingleNode.cpp"
)
set(TARGET_HEADERS
    "include/"
)

set(TARGET_DEPENDENCIES_HEADERS
    "dependencies/"
)

add_library( ${TARGET_NAME} 
    ${TARGET_SOURCES}
)
target_include_directories( ${TARGET_NAME}
    PUBLIC
        ${TARGET_HEADERS}
        ${TARGET_DEPENDENCIES_HEADERS}
)