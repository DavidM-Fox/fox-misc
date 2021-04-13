cmake_minimum_required(VERSION 3.0.0)

find_package(Catch2 CONFIG REQUIRED)


set(TESTS
    main.cpp
    test_00.cpp
    test_01.cpp
)

include_directories("${CMAKE_CURRENT_SOURCE}/dev/inc")
include_directories("${CMAKE_CURRENT_SOURCE}/dev/lib")

add_executable(foxmisc_test ${TESTS})
target_link_libraries(foxmisc_test PUBLIC Catch2::Catch2 foxmisc)

include(CTest)
include(Catch)
catch_discover_tests(foxmisc_test)