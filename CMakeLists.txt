cmake_minimum_required(VERSION 3.28)
project(realm)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)

add_subdirectory(${CMAKE_SOURCE_DIR}/vendor/SDL)
add_subdirectory(${CMAKE_SOURCE_DIR}/vendor/my-dear-logger)
add_subdirectory(${CMAKE_SOURCE_DIR}/engine)
add_subdirectory(${CMAKE_SOURCE_DIR}/src)