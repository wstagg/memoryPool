cmake_minimum_required(VERSION 3.30)

project(MemoryPool)
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_FLAGS "-std=c++2a -Wall -Wextra -Werror -Wpedantic")

include(CTest)

# FetchContent to load and build googletest
include(FetchContent)

FetchContent_Declare(
        googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG main
)

#set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(Tests main.cpp)

target_link_libraries(Tests GTest::gtest_main)

include(GoogleTest)
gtest_discover_tests(Tests)