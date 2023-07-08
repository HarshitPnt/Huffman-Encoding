cmake_minimum_required(VERSION 3.22.1)

project(Hufmman-Encoding)
file(GLOB_RECURSE SRC_FILES src/*.cpp)
add_executable(encode encode.cpp ${SRC_FILES})
add_executable(decode decode.cpp ${SRC_FILES})
target_include_directories(encode PUBLIC include)
target_include_directories(decode PUBLIC include)


