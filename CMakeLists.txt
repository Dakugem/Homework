cmake_minimum_required(VERSION 3.10)

project(filesystemlibproject VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SOURCE_LIB src/fsyslib.cpp include/fsyslib.h)
set(SOURCE_EXE src/main.cpp)

add_library(filesystemlib STATIC ${SOURCE_LIB})
add_executable(main ${SOURCE_EXE})

target_include_directories(filesystemlib PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_link_libraries(main filesystemlib)	