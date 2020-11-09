
cmake_minimum_required(VERSION 2.8.8)

project(liblangserver)

include(ExternalProject)
find_package(Java REQUIRED)
include(UseJava)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_JAVA_COMPILE_FLAGS "-source" "1.8" "-target" "1.8")


if (NOT PACKAGES_DIR)
  set(PACKAGES_DIR ${CMAKE_SOURCE_DIR}/packages)
endif()


ExternalProject_Add(GOOGLETEST
	PREFIX googletest
	SOURCE_DIR "${PACKAGES_DIR}/googletest"
    CMAKE_CACHE_ARGS
    -DCMAKE_INSTALL_PREFIX:PATH=${CMAKE_BINARY_DIR}/googletest
	)
	
include_directories(
	${PACKAGES_DIR}/json/include
	)
	
set(CompilerFlags
        CMAKE_CXX_FLAGS
        CMAKE_CXX_FLAGS_DEBUG
        CMAKE_CXX_FLAGS_RELEASE
        CMAKE_C_FLAGS
        CMAKE_C_FLAGS_DEBUG
        CMAKE_C_FLAGS_RELEASE
        )
foreach(CompilerFlag ${CompilerFlags})
  string(REPLACE "/MD" "/MT" ${CompilerFlag} "${${CompilerFlag}}")
endforeach()
	
file(GLOB LIBLANGSERVER_SRCS src/*.cpp src/*.h)
	
add_library(liblangserver  ${LIBLANGSERVER_SRCS})

install(TARGETS liblangserver
  DESTINATION lib
  EXPORT liblangserver-targets)

file(GLOB liblangserver_headers src/*.h)
install(FILES ${liblangservers_headers}
  DESTINATION "include/liblangserver")
	
# TODO: make conditional on developing the package
if (NOT WIN32)
  enable_testing()
  add_subdirectory(tests)
endif()


