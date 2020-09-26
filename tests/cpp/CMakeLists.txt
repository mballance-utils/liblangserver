
cmake_minimum_required(VERSION 2.8.8)

file(GLOB TEST_SRCS *.cpp *.h)

link_directories(
	${CMAKE_BINARY_DIR}/googletest/lib
	${CMAKE_BINARY_DIR}/liblangserver)

add_executable(liblangserver_testmain ${TEST_SRCS})
target_include_directories(liblangserver_testmain PRIVATE
	${CMAKE_BINARY_DIR}/googletest/include
	${CMAKE_CURRENT_SOURCE_DIR}/../../src)
target_link_libraries(liblangserver_testmain 
	gtest 
	gtest_main 
	liblangserver
	pthread)

add_test(
	NAME unit
	COMMAND ${CMAKE_BINARY_DIR}/tests/cpp/liblangserver_testmain)

#include(${PACKAGES_DIR}/googletest)

