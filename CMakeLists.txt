cmake_minimum_required(VERSION 3.22.1)

project(Hufmman-copy)
file(GLOB_RECURSE SRC_FILES src/*.cpp)
add_executable(${PROJECT_NAME} main.cpp ${SRC_FILES})
target_include_directories(${PROJECT_NAME} PUBLIC include)

