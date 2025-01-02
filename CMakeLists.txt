cmake_minimum_required(VERSION 3.10)
project(pikachu VERSION 1.0)

file(GLOB_RECURSE SRC_FILES "src/*.cpp")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/Debug)
add_executable(pikachu ${SRC_FILES})

target_include_directories(pikachu PUBLIC scr)
target_link_libraries(pikachu winmm)