cmake_minimum_required(VERSION 3.16)
project(foxspace
        VERSION 1.0.0
        DESCRIPTION "FoxSpace - Yet another C++ library for making developer's life easier."
        HOMEPAGE_URL "https://github.com/MCWertGaming/foxspace"
        LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED true)

option(FOXSPACE_BUILD_EXAMPLES "Enables building of examples" ON)
option(FOXSPACE_ENABLE_TESTING "Enables building of unit testing targets" ON)

add_subdirectory(fox)

if (FOXSPACE_ENABLE_TESTING)
    # enable unit testing
    enable_testing()
    # add tests
    add_subdirectory(tests)
    # add dependencies, currently only gtest
    add_subdirectory(dependencies)
endif(FOXSPACE_ENABLE_TESTING)
