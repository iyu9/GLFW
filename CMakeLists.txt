### Pre Setting ###
cmake_minimum_required(VERSION 3.0)
project(GLFW CXX)

SET(CMAKE_CXX_FLAGS_RELEASE "-Wall -O2")
SET(CMAKE_BUILD_TYPE Release)

### Build Actions ###
find_package(OpenGL REQUIRED)
add_executable(RunApp main.cpp)

target_link_libraries(RunApp ${OpenGL_LIBRARIES})
