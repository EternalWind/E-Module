PROJECT(E-Module)
cmake_minimum_required(VERSION 2.8)

set(CMAKE_CONFIGURATION_TYPES "Debug;Release" CACHE STRING "" FORCE)
if(NOT CMAKE_BUILD_TYPE)
	set(CMAKE_BUILD_TYPE Debug CACHE STRING "Choose the type of build(Debug or Release)" FORCE)
endif()

set(BUILD_STATIC FALSE CACHE BOOL "TRUE to build static libraries (mind LGPL3 implications), FALSE to build shared libraries (preferred)")

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)

include_directories(${PROJECT_SOURCE_DIR}/src)

aux_source_directory(src main_CPP)

file(GLOB_RECURSE main_H src/*.h)

if(BUILD_STATIC)
    set(BUILD_MODE STATIC)
else()
    set(BUILD_MODE SHARED)
endif()

add_library(E-Module ${BUILD_MODE}
    ${main_CPP} ${main_H}
)
