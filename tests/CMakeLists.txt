set(test_sources math_test.cpp time_test.cpp)

add_executable(foxspace-testing ${test_sources})
target_link_libraries(foxspace-testing foxspace gtest gtest_main)
