cmake_minimum_required(VERSION 3.0.0)
project(misc VERSION 0.1.0)

include(CTest)
enable_testing()
include_directories(include)

set(SOURCES 
    main.cpp
    include/dmfmisc.hpp
    include/dmfmisc/string.hpp
    include/dmfmisc/logger.hpp
)

add_executable(misc ${SOURCES})

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
