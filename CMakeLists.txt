cmake_minimum_required(VERSION 3.3)
project(sqlite_cpp)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG "${CMAKE_SOURCE_DIR}/build/debug")

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR})

file(GLOB_RECURSE SOURCES src/*.cpp)

add_executable(sqlite_cpp ${SOURCES})
target_link_libraries(sqlite_cpp sqlite3)
target_include_directories(sqlite_cpp PRIVATE src)
