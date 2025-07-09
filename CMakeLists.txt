
cmake_minimum_required(VERSION 3.16)
project(2DEngine LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

file(GLOB_RECURSE SOURCES
    src/*.cpp
    src/*.h
)

add_executable(2DEngine ${SOURCES})

# Paths
set(SFML_ROOT "${CMAKE_SOURCE_DIR}/third_party/SFML/install")

# Include directories (header-only libs like RapidJSON)
target_include_directories(2DEngine PRIVATE
    ${SFML_ROOT}/include
)

# Link directories (for shared SFML .so libs)
link_directories(${SFML_ROOT}/lib)

# Link SFML libraries
target_link_libraries(2DEngine
    PRIVATE
        sfml-graphics
        sfml-window
        sfml-system
        pthread
)
