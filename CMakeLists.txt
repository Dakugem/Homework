cmake_minimum_required(VERSION 3.10)

project(filesystemlib VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SOUCE_EXE src/main.cpp)
set(SOURCE_LIB src/fsyslib.cpp include/fsyslib.h)

add_executable(main ${SOURCE_EXE})
add_library(filesystemlib STATIC ${SOURCE_LIB})

target_link_libraries(main filesystemlib)	