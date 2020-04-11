cmake_minimum_required(VERSION 2.8.12)
project(huawei_graph)

## Compile as C++11, supported in ROS Kinetic and newer
add_compile_options(-std=c++11)

include_directories(include)

aux_source_directory(src SRC_FILES)

# kinematic test
add_executable(test ${SRC_FILES})