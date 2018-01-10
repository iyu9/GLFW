# NOT WORK
cmake_minimum_required(VERSION 2.6)
project(GLFW CXX)

find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)

add_executable(RunApp main.cpp)
find_library(OpenGL_LIBRARY OpenGL)

target_link_libraries(RunApp ${OpenGL_LIBRARIES} ${GLUT_LIBRARIES})
