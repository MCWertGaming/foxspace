// testing of math.hpp of the foxspace library

#include <gtest/gtest.h>
#include <foxspace/math.hpp>

TEST(math_test, get_randomNumber) {
    EXPECT_EQ(Fox::get_randomNumber(0), 0);
    EXPECT_NO_THROW(Fox::get_randomNumber(1));
    EXPECT_NO_THROW(Fox::get_randomNumber(1));
    EXPECT_NO_THROW(Fox::get_randomNumber(1));
    EXPECT_NO_THROW(Fox::get_randomNumber(1));
    EXPECT_NO_THROW(Fox::get_randomNumber(1));
    EXPECT_NO_THROW(Fox::get_randomNumber(3));
    EXPECT_NO_THROW(Fox::get_randomNumber(3));
    EXPECT_NO_THROW(Fox::get_randomNumber(3));
    EXPECT_NO_THROW(Fox::get_randomNumber(3));
    EXPECT_NO_THROW(Fox::get_randomNumber(3));
    EXPECT_NO_THROW(Fox::get_randomNumber(3));
}
TEST(math_test, is_prime) {
    EXPECT_FALSE(Fox::is_prime(0));
    EXPECT_FALSE(Fox::is_prime(1));
    EXPECT_TRUE(Fox::is_prime(2));
    EXPECT_TRUE(Fox::is_prime(3));
    EXPECT_FALSE(Fox::is_prime(4));
    EXPECT_TRUE(Fox::is_prime(5));
    EXPECT_FALSE(Fox::is_prime(6));
    EXPECT_TRUE(Fox::is_prime(7));
    EXPECT_FALSE(Fox::is_prime(8));
    EXPECT_FALSE(Fox::is_prime(9));
    EXPECT_FALSE(Fox::is_prime(10));
    EXPECT_TRUE(Fox::is_prime(11));
    EXPECT_FALSE(Fox::is_prime(12));
    EXPECT_TRUE(Fox::is_prime(13));
    EXPECT_FALSE(Fox::is_prime(14));
    EXPECT_FALSE(Fox::is_prime(15));
    EXPECT_FALSE(Fox::is_prime(16));
    EXPECT_TRUE(Fox::is_prime(17));
    EXPECT_FALSE(Fox::is_prime(18));
    EXPECT_TRUE(Fox::is_prime(19));
    EXPECT_FALSE(Fox::is_prime(20));
    EXPECT_FALSE(Fox::is_prime(21));
    EXPECT_FALSE(Fox::is_prime(22));
    EXPECT_TRUE(Fox::is_prime(23));
    EXPECT_TRUE(Fox::is_prime(4019));
    EXPECT_TRUE(Fox::is_prime(7919));
    EXPECT_TRUE(Fox::is_prime(999331));
}
TEST(math_test, prime_sum) {
    EXPECT_EQ(Fox::prime_sum(0), 0);
    EXPECT_EQ(Fox::prime_sum(1), 0);
    EXPECT_EQ(Fox::prime_sum(2), 2);
    EXPECT_EQ(Fox::prime_sum(3), 5);
    EXPECT_EQ(Fox::prime_sum(4), 5);
    EXPECT_EQ(Fox::prime_sum(31), 160);
    EXPECT_EQ(Fox::prime_sum(10000000), 3574358836);
}
