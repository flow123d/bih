cmake_minimum_required(VERSION 2.8.12)
project(cmake_example)

include_directories(src)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")


add_library(bih_tree SHARED src/bih_tree.cc)

# targets for test executables
add_executable(test_bih_tree src/test_bih_tree.cc)
target_link_libraries(test_bih_tree  bih_tree)
