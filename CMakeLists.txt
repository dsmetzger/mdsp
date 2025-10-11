cmake_minimum_required(VERSION 3.16)

project(mdsp_plot_lib VERSION 1.0.0 LANGUAGES CXX)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add Qt library subdirectory
add_subdirectory(lib/mdsp/qt)


add_executable(demo_qt src/demo_qt.cpp)
target_link_libraries(demo_qt mdsp_plot_qt_lib)

