### Pre Setting ###
cmake_minimum_required(VERSION 3.0)
project(GLFW CXX)

### Build Actions ###
//include_directories()
//link_directories()

find_package(OpenGL REQUIRED)
add_executable(RunApp main.cpp)

target_link_libraries(RunApp ${OpenGL_LIBRARIES})