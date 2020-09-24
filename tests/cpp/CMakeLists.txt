
cmake_minimum_required(VERSION 2.8.8)

file(GLOB TEST_SRCS *.cpp *.h)

link_directories(${CMAKE_BINARY_DIR}/googletest/lib)

add_executable(liblangserver_testmain ${TEST_SRCS})
target_include_directories(liblangserver_testmain PRIVATE
	${CMAKE_BINARY_DIR}/googletest/include)
target_link_libraries(liblangserver_testmain gtest gtest_main pthread)

add_test(
	NAME unit
	COMMAND ${CMAKE_BINARY_DIR}/tests/cpp/liblangserver_testmain)

#include(${PACKAGES_DIR}/googletest)

