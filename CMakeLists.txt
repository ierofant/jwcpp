project(jwcpp CXX)
cmake_minimum_required(VERSION 2.8)

set(VERSION 0.9)

add_definitions(-std=c++11)

set(PKGCONFIG ${CMAKE_BINARY_DIR}/${PROJECT_NAME}.pc)
set(FINDCMAKE ${CMAKE_BINARY_DIR}/FindJWCpp.cmake)
configure_file(config/pkgconfig.pc.in ${PKGCONFIG} @ONLY)

file(GLOB HEADER ${PROJECT_NAME}/*.hpp)
file(GLOB SOURCE ${PROJECT_NAME}/*.cpp)

add_library(shared SHARED ${SOURCE})
add_library(static STATIC ${SOURCE})
set_target_properties(shared static PROPERTIES 
			OUTPUT_NAME	${PROJECT_NAME}
			VERSION		${VERSION}
			PUBLIC_HEADER	"${HEADER}")

install(TARGETS shared static 
	    LIBRARY		DESTINATION lib
	    ARCHIVE		DESTINATION lib
	    PUBLIC_HEADER	DESTINATION include/${PROJECT_NAME})
install(FILES ${PKGCONFIG} DESTINATION lib/pkgconfig) 
install(FILES ${FINDCMAKE} DESTINATION ${CMAKE_ROOT}/Modules OPTIONAL)

add_subdirectory(examples)
