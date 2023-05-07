#****************************************************************************
#* CMakeLists.txt
#****************************************************************************
cmake_minimum_required (VERSION 3.11)



link_directories(
	${CMAKE_BINARY_DIR}/jrpc/lib
	${CMAKE_BINARY_DIR}/jrpc/lib64
	)

file(GLOB langserver_SRC
	"*.h"
	"*.cpp")
add_library(langserver SHARED
	${langserver_SRC}
	)
    
target_include_directories(langserver PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}/include
    "${PACKAGES_DIR}/libjson-rpc/src/include"
    "${debug_mgr_INCDIR}"
    )

install(TARGETS langserver
    DESTINATION lib
    EXPORT langserver-targets)
add_dependencies(langserver JRPC)
    
set_target_properties(langserver PROPERTIES SKIP_BUILD_RPATH TRUE)

