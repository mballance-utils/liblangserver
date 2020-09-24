
cmake_minimum_required(VERSION 2.8.8)

include(ExternalProject)

project(liblangserver)

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
	
add_subdirectory(tests/cpp)

