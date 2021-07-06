# A list of all unit testing source files
set(test_sources math_test.cpp time_test.cpp)

# combines all tests into one executable
add_executable(foxspace-tests ${test_sources})
target_link_libraries(foxspace-tests foxspace gtest gtest_main)

# add unit testing executable to CTest configuration
add_test(NAME foxspace-tests COMMAND foxspace-tests)
