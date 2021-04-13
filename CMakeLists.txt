cmake_minimum_required(VERSION 3.0.0)
project(foxmisc VERSION 0.1.0 DESCRIPTION "A collection of miscellaneous methods/classes.")

# Library definition -----------------------------------
set(LIB_SOURCES src/fox-logger.cpp src/fox-string.cpp)

add_library(foxmisc STATIC ${LIB_SOURCES})

target_include_directories(foxmisc PRIVATE include)
target_include_directories(foxmisc PRIVATE src)

set(LIB_HEADERS
    include/fox-misc/fox-logger.hpp
    include/fox-misc/fox-string.hpp)
set_target_properties(foxmisc PROPERTIES VERSION ${PROJECT_VERSION})
set_target_properties(foxmisc PROPERTIES PUBLIC_HEADER "${LIB_HEADERS}")

set(CMAKE_INSTALL_PREFIX "${CMAKE_CURRENT_SOURCE}/dev/")
    
install(TARGETS foxmisc 
        LIBRARY DESTINATION lib
        PUBLIC_HEADER DESTINATION inc/fox-misc)

enable_testing()
add_subdirectory(test)