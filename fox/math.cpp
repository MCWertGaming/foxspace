#include <fox/math.hpp>
#include <fox/time.hpp>
#include <random>
#include <stdexcept>

unsigned int Fox::get_randomNumber(unsigned int maxNum) {
    unsigned int randomNumber;
    do {
        // make the generator ready
        std::mt19937_64 generator(get_timepoint());
        // generate number
        randomNumber = generator() % (maxNum + 1);
    } while (randomNumber == 0);

    // throws a runtime_error if the generated number is bigger than expected
    if (randomNumber > maxNum)
        throw "randomNumber in Fox::randomNumber() is higher than expected";

    return randomNumber - 1;
}
unsigned int Fox::is_prime(unsigned int number) {
    // taking the square root to speed up the calculation and place the result
    // into another variable to save more time (seems like c++ calculates the
    // sqrt on every loop otherwise)
    double root = sqrt((double)number);
    for (int i = 3; i <= root; i += 2) {
        // result of 0 means its not a prime = it can be devised through another
        // number except 0 and himself
        if (number % i == 0) {
            return false;
        }
    }
    return true;
}

unsigned int Fox::prime_sum(unsigned int max_number) {
    // start with value 2
    unsigned int sum = 2;
    for (unsigned long long i = 1; i < max_number; i += 2) {
        // testPrime returns true, if the given number is a Prime
        if (is_prime(i)) {
            sum = sum + i;
        }
    }
    return sum;
}
