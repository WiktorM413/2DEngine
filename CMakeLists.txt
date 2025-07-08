cmake_minimum_required(VERSION 3.16)
project(2DEngine LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

file(GLOB_RECURSE SOURCES
    src/*.cpp
    src/*.h
)

add_executable(2DEngine ${SOURCES})

set(SFML_ROOT "${CMAKE_SOURCE_DIR}/third_party/SFML/install")

target_include_directories(2DEngine PRIVATE ${SFML_ROOT}/include)
link_directories(${SFML_ROOT}/lib)

target_link_libraries(2DEngine
    PRIVATE
        sfml-graphics
        sfml-window
        sfml-system
        pthread
)
