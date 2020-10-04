
cmake_minimum_required(VERSION 2.8.8)

project(liblangserver)

include(ExternalProject)
find_package(Java REQUIRED)
include(UseJava)

set(CMAKE_JAVA_COMPILE_FLAGS "-source" "1.8" "-target" "1.8")


if (NOT PACKAGES_DIR)
  set(PACKAGES_DIR ${CMAKE_SOURCE_DIR}/packages)
endif()

# TODO: make conditional on developing the package
enable_testing()

ExternalProject_Add(GOOGLETEST
	PREFIX googletest
	SOURCE_DIR "${PACKAGES_DIR}/googletest"
    CMAKE_CACHE_ARGS
    -DCMAKE_INSTALL_PREFIX:PATH=${CMAKE_BINARY_DIR}/googletest
	-DCMAKE_C_COMPILER:STRING=${CMAKE_C_COMPILER}
	-DCMAKE_CXX_COMPILER:STRING=${CMAKE_CXX_COMPILER}
	-DCMAKE_C_COMPILER_ID:STRING=${CMAKE_C_COMPILER_ID}
	-DCMAKE_CXX_COMPILER_ID:STRING=${CMAKE_CXX_COMPILER_ID}
	-DCMAKE_SYSTEM_NAME:STRING=${CMAKE_SYSTEM_NAME}
	)
	
include_directories(
	${PACKAGES_DIR}/json/include
	)
	
file(GLOB LIBLANGSERVER_SRCS src/*.cpp src/*.h)
	
add_library(liblangserver  ${LIBLANGSERVER_SRCS})

install(TARGETS liblangserver
  DESTINATION lib
  EXPORT liblangserver-targets)

file(GLOB liblangserver_headers src/*.h)
install(FILES ${liblangservers_headers}
  DESTINATION "include/liblangserver")
	
add_subdirectory(tests)


