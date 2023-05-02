
cmake_minimum_required(VERSION 2.8.8)

file(GLOB TEST_SRCS 
	"src/*.cpp" 
	"src/*.h")

link_directories(
	${CMAKE_BINARY_DIR}/gtest/lib
	${CMAKE_BINARY_DIR}/gtest/lib64
	${CMAKE_BINARY_DIR}/liblangserver
	${CMAKE_BINARY_DIR}/jrpc/lib
	${CMAKE_BINARY_DIR}/jrpc/lib64
    "${debug_mgr_LIBDIR}"
    )

#********************************************************************
#* GoogleTest unit tests
#********************************************************************
add_executable(test-lls ${TEST_SRCS})
add_dependencies(test-lls GOOGLETEST)

if (WIN32)
  list(APPEND LIBLANGSERVER_TESTMAIN_LIBS gtestd gtest_maind)	
else()
  list(APPEND LIBLANGSERVER_TESTMAIN_LIBS gtest gtest_main)	
endif()

list(APPEND LIBLANGSERVER_TESTMAIN_LIBS langserver json-rpc)	

if (WIN32)
  list(APPEND LIBLANGSERVER_TESTMAIN_LIBS ws2_32)	
else()
  list(APPEND LIBLANGSERVER_TESTMAIN_LIBS pthread)	
endif()

list(APPEND LIBLANGSERVER_TESTMAIN_LIBS langserver debug-mgr)	

target_include_directories(test-lls PRIVATE
	${CMAKE_BINARY_DIR}/gtest/include
#	${PACKAGES_DIR}/googletest/googletest/include
	${CMAKE_SOURCE_DIR}/src/include
    "${PACKAGES_DIR}/libjson-rpc/src/include"
    "${debug_mgr_INCDIR}"
    )
target_link_libraries(test-lls ${LIBLANGSERVER_TESTMAIN_LIBS})

#add_test(
#	NAME unit
#	COMMAND ${CMAKE_BINARY_DIR}/tests/liblangserver_testmain)


#********************************************************************
#* TestLangServer executable
#********************************************************************
# set(TEST_LANGSERVER_SRC
#   cpp/TestLangServer.cpp
#   cpp/TestLangServer.h
#   apps/testlangserver_main.cpp)

# add_executable(test-lls ${TEST_LANGSERVER_SRC})

# target_include_directories(testlangserver PRIVATE
# 	${CMAKE_CURRENT_SOURCE_DIR}/cpp
# 	${CMAKE_CURRENT_SOURCE_DIR}/../src)

# list(APPEND TESTLANGSERVER_LIBS liblangserver)	

# if (WIN32)
#   list(APPEND TESTLANGSERVER_LIBS ws2_32)
# else()
#   list(APPEND TESTLANGSERVER_LIBS pthread)
# endif()

# target_link_libraries(testlangserver ${TESTLANGSERVER_LIBS})

#********************************************************************
#* JUnit unit tests
#********************************************************************
if (WIN32 AND NOT CYGWIN)
  set(PS ";")
else (WIN32 AND NOT CYGWIN)
  set(PS ":")
endif(WIN32 AND NOT CYGWIN)

#file(GLOB_RECURSE JAVA_TEST_SRCS *.java)
#file(GLOB LSP4J_JARS ${PACKAGES_DIR}/lsp4j/plugins/*.jar)


#set(CMAKE_JAVA_INCLUDE_PATH 
#	${LSP4J_JARS} 
#	${CMAKE_CURRENT_SOURCE_DIR}/src/java)

#list(APPEND CLASSPATH_LIST ${LSP4J_JARS})
#list(APPEND CLASSPATH_LIST ${CMAKE_CURRENT_BINARY_DIR}/liblangserver_tests.jar)
#list(APPEND CLASSPATH_LIST ${PACKAGES_DIR}/junit.jar)
#list(APPEND CLASSPATH_LIST ${PACKAGES_DIR}/gson.jar)

#string(REPLACE ";" "${PS}" CLASSPATH "${CLASSPATH_LIST}")

#add_jar(liblangserver_tests ${JAVA_TEST_SRCS})

#add_test(
#	NAME junit
#	COMMAND ${Java_JAVA_EXECUTABLE} -classpath ${CLASSPATH}
#	org.liblangserver.tests.Test)
	
ExternalProject_Add(GOOGLETEST
	PREFIX googletest
	SOURCE_DIR "${PACKAGES_DIR}/gtest"
    CMAKE_CACHE_ARGS
    -DCMAKE_INSTALL_PREFIX:PATH=${CMAKE_BINARY_DIR}/gtest
	)

#include(${PACKAGES_DIR}/googletest)
