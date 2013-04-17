project(jwcpp CXX)
cmake_minimum_required(VERSION 2.8)

add_definitions(-std=c++11)

file(GLOB SOURCE ${PROJECT_NAME}/*.cpp)

add_library(shared SHARED ${SOURCE})
add_library(static STATIC ${SOURCE})
set_target_properties(shared static PROPERTIES OUTPUT_NAME ${PROJECT_NAME})

add_subdirectory(examples)
