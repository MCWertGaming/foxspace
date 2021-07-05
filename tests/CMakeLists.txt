# A list of all unit testing source files
set(test_sources math_test.cpp time_test.cpp)

# combines all tests into one executable
add_executable(foxspace-testing ${test_sources})
target_link_libraries(foxspace-testing foxspace gtest gtest_main)

# add unit testing executable to CTest configuration
add_test(NAME fospace-testing-target COMMAND foxspace-testing)
