include_directories(${CMAKE_HOME_DIRECTORY})

add_executable(output EXCLUDE_FROM_ALL output.cpp)
target_link_libraries(output shared)

add_custom_target(examples DEPENDS output)
