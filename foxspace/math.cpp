#include <foxspace/math.hpp>
#include <foxspace/time.hpp>
#include <random>
#include <stdexcept>

uint32_t Fox::get_randomNumber(uint32_t maxNum) {
    // fixes random number from 0 to 0
    if (maxNum == 0)
        return 0;

    // make the generator ready
    std::mt19937_64 generator(get_timepoint());

    // return generated number
    return generator() % ++maxNum;
}
uint32_t Fox::is_prime(uint32_t number) {
    // defining the two three numbers so they can be skipped in the next step
    if (number == 0 || number == 1)
        return false;
    // defining the 2 as it would otherwise be returned as even (as it's the
    // only even prime)
    else if (number == 2)
        return true;
    // sorting out all numbers that are even
    else if (number % 2 == 0)
        return false;

    // taking the square root to speed up the calculation and place the result
    // into another variable to save more time (seems like c++ calculates the
    // sqrt on every loop otherwise)
    uint16_t root = sqrt(number);
    for (uint16_t i = 3; i <= root; i += 2) {
        // result of 0 means its not a prime = it can be devised through another
        // number except 0 and himself
        if (number % i == 0) {
            return false;
        }
    }
    return true;
}

uint64_t Fox::prime_sum(uint32_t max_number) {
    // cover the first two numbers
    if (max_number == 0 || max_number == 1)
        return 0;

    // start with value 2
    uint64_t sum = 2;
    // tests every second number to be a prime (the skiped number is always a
    // divisor of 2)
    for (uint32_t i = 3; i <= max_number; i += 2) {
        // testPrime returns true, if the given number is a Prime
        if (is_prime(i)) {
            sum = sum + i;
        }
    }
    return sum;
}
