// testing of time.hpp of the foxspace library

#include <gtest/gtest.h>
#include <foxspace/time.hpp>

TEST(time_test, sleep_for) {
    EXPECT_NO_THROW(Fox::sleep_for(1));
}
TEST(time_test, get_timepoint) {
    EXPECT_NO_THROW(Fox::get_timepoint());
}

// TODO: add tests for the timer class
