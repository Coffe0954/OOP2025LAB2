cmake_minimum_required(VERSION 3.10)
project(FourClass)

set(CMAKE_CXX_STANDARD 14)

add_executable(four_example main.cpp Four.cpp)

find_package(GTest)
if(GTest_FOUND)
    add_executable(four_tests test_four.cpp Four.cpp)
    target_link_libraries(four_tests GTest::GTest GTest::Main)
else()
    message(WARNING "Google Test not found - tests will not be built")
endif()