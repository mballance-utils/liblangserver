
cmake_minimum_required(VERSION 2.8.8)

file(GLOB TEST_SRCS 
	"cpp/*.cpp" 
	"cpp/*.h")

link_directories(
	${CMAKE_BINARY_DIR}/googletest/lib
	${CMAKE_BINARY_DIR}/liblangserver)

#********************************************************************
#* GoogleTest unit tests
#********************************************************************
add_executable(liblangserver_testmain ${TEST_SRCS})
add_dependencies(liblangserver_testmain GOOGLETEST)
target_include_directories(liblangserver_testmain PRIVATE
	${CMAKE_BINARY_DIR}/googletest/include
	${PACKAGES_DIR}/googletest/googletest/include
	${CMAKE_CURRENT_SOURCE_DIR}/../src)
target_link_libraries(liblangserver_testmain 
	gtest 
	gtest_main 
	liblangserver
	pthread)

add_test(
	NAME unit
	COMMAND ${CMAKE_BINARY_DIR}/tests/liblangserver_testmain)


#********************************************************************
#* TestLangServer executable
#********************************************************************
set(TEST_LANGSERVER_SRC
  cpp/TestLangServer.cpp
  cpp/TestLangServer.h
  apps/testlangserver_main.cpp)

add_executable(testlangserver ${TEST_LANGSERVER_SRC})

target_include_directories(testlangserver PRIVATE
	${CMAKE_CURRENT_SOURCE_DIR}/cpp
	${CMAKE_CURRENT_SOURCE_DIR}/../src)

target_link_libraries(testlangserver
	liblangserver
	pthread)

#********************************************************************
#* JUnit unit tests
#********************************************************************
if (WIN32 AND NOT CYGWIN)
  set(PS ";")
else (WIN32 AND NOT CYGWIN)
  set(PS ":")
endif(WIN32 AND NOT CYGWIN)

file(GLOB_RECURSE JAVA_TEST_SRCS *.java)
file(GLOB LSP4J_JARS ${PACKAGES_DIR}/lsp4j/plugins/*.jar)


set(CMAKE_JAVA_INCLUDE_PATH 
	${LSP4J_JARS} 
	${CMAKE_CURRENT_SOURCE_DIR}/src/java)

list(APPEND CLASSPATH_LIST ${LSP4J_JARS})
list(APPEND CLASSPATH_LIST ${CMAKE_CURRENT_BINARY_DIR}/liblangserver_tests.jar)
list(APPEND CLASSPATH_LIST ${PACKAGES_DIR}/junit.jar)
list(APPEND CLASSPATH_LIST ${PACKAGES_DIR}/gson.jar)

string(REPLACE ";" "${PS}" CLASSPATH "${CLASSPATH_LIST}")

add_jar(liblangserver_tests ${JAVA_TEST_SRCS})

add_test(
	NAME junit
	COMMAND ${Java_JAVA_EXECUTABLE} -classpath ${CLASSPATH}
	org.liblangserver.tests.Test)
	

#include(${PACKAGES_DIR}/googletest)
