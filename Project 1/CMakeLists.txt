cmake_minimum_required(VERSION 3.6)
project(Project_1)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES main.cpp Graph.cpp Gui.cpp Simple_window.cpp Window.cpp fltk.h Point.h)
find_package(FLTK REQUIRED NO_MODULE)
include_directories(${FLTK_INCLUDE_DIRS})
add_executable(Project_1 ${SOURCE_FILES})
target_link_libraries(Project_1 fltk fltk_images)