cmake_minimum_required(VERSION 3.0.0)
project(foxmisc VERSION 0.1.0 DESCRIPTION "A collection of miscellaneous methods/classes.")


# Library sources/headers ------------------------------
set(LIB_SOURCES src/fox-logger.cpp src/fox-string.cpp)
set(LIB_HEADERS
    include/fox-misc/fox-logger.hpp
    include/fox-misc/fox-string.hpp)

# Library definition -----------------------------------
add_library(foxmisc STATIC ${LIB_SOURCES})
target_include_directories(foxmisc PRIVATE include)
target_include_directories(foxmisc PRIVATE src)
set_target_properties(foxmisc PROPERTIES VERSION ${PROJECT_VERSION})
set_target_properties(foxmisc PROPERTIES PUBLIC_HEADER "${LIB_HEADERS}")

# Library installation condition -----------------------
if(WIN32)
    set(CMAKE_INSTALL_PREFIX "${CMAKE_CURRENT_SOURCE}/dev/")
    install(TARGETS foxmisc 
            LIBRARY DESTINATION lib
            PUBLIC_HEADER DESTINATION inc/fox-misc)
else()
    include(GNUInstallDirs)
    install(TARGETS foxmisc 
            LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
            PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/fox-misc)
endif()

# enable_testing()
# add_subdirectory(test)