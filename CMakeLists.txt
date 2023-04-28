
cmake_minimum_required(VERSION 3.11)

project(liblangserver)

include(ExternalProject)
#find_package(Java REQUIRED)
#include(UseJava)


if (NOT PACKAGES_DIR)
  set(PACKAGES_DIR ${CMAKE_SOURCE_DIR}/packages)
endif()

if (WIN32)
  set(PYTHON ${PACKAGES_DIR}/python/Scripts/python.exe)
else()
  set(PYTHON ${PACKAGES_DIR}/python/bin/python)
endif()

execute_process(COMMAND ${PYTHON} -m ivpm share cmake OUTPUT_VARIABLE IVPM_CMAKE_PATH)
list(APPEND CMAKE_MODULE_PATH ${IVPM_CMAKE_PATH})
message("IVPM_CMAKE_PATH: ${IVPM_CMAKE_PATH} ${CMAKE_MODULE_PATH}")

include(ivpm)

Ivpm_AddPythonExtProject(debug-mgr debug_mgr)

set(CMAKE_CXX_STANDARD 11)
#set(CMAKE_JAVA_COMPILE_FLAGS "-source" "1.8" "-target" "1.8")

include_directories(
	${PACKAGES_DIR}/json/include
	)

ExternalProject_Add(JRPC
    PREFIX jrpc 
    SOURCE_DIR "${PACKAGES_DIR}/libjson-rpc" 
    CMAKE_CACHE_ARGS 
    -DCMAKE_INSTALL_PREFIX:PATH=${CMAKE_BINARY_DIR}/jrpc
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
	
# file(GLOB LIBLANGSERVER_SRCS src/*.cpp src/*.h)
	
# add_library(liblangserver  ${LIBLANGSERVER_SRCS})

# target_include_directories(liblangserver PRIVATE
#     ${CMAKE_CURRENT_SOURCE_DIR}/src 
#     ${CMAKE_CURRENT_SOURCE_DIR}/src/include
# ) 
add_subdirectory(src)

# install(TARGETS liblangserver
#   DESTINATION lib
#   EXPORT liblangserver-targets)

# file(GLOB liblangserver_headers src/*.h)
# install(FILES ${liblangservers_headers}
#   DESTINATION "include/liblangserver")
	
# TODO: make conditional on developing the package
if (NOT WIN32)
#  enable_testing()
#  add_subdirectory(tests)
endif()


