cmake_minimum_required(VERSION 3.15)
project(Logger)

set(CMAKE_CXX_STANDARD 14)
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread")



add_executable(Logger src/Log.cpp Header/Log.h src/Automated_test.cpp src/Manual_test.cpp)

#google test inclues
include_directories(lib/googletest/googletest/include)
include_directories(lib/googletest/googlemock/include)

target_link_libraries(Logger gtest gtest_main)


