include_directories(${CMAKE_HOME_DIRECTORY})

add_executable(output EXCLUDE_FROM_ALL output.cpp)
target_link_libraries(output shared)

add_executable(input EXCLUDE_FROM_ALL input.cpp)
target_link_libraries(input shared)

add_executable(fstream EXCLUDE_FROM_ALL fstream.cpp)
target_link_libraries(fstream shared)

add_custom_target(examples DEPENDS output input)
