#include <foxspace/math.hpp>
#include <foxspace/time.hpp>
#include <random>
#include <stdexcept>

unsigned int Fox::get_randomNumber(unsigned int maxNum) {
    // fixes random number from 0 to 0
    if (maxNum == 0)
        return 0;

    unsigned int randomNumber = 0;
    unsigned int iteration = 0;

    // make the generator ready
    std::mt19937_64 generator(get_timepoint());

    do {
        // generate number
        randomNumber = generator() % (maxNum + 1);

        // fixes endless loop if no good random number was generated
        if (iteration > 3000)
            throw "Couldn't get a good random number in Fox::randomNumber() after 50 tries.";
        iteration++;

    } while (randomNumber == 0);

    // throws a runtime_error if the generated number is bigger than expected
    if (randomNumber > maxNum)
        throw "randomNumber in Fox::randomNumber() is higher than expected";

    return randomNumber - 1;
}
unsigned int Fox::is_prime(unsigned int number) {
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
    // cover the first two numbers
    if (max_number == 0 || max_number == 1)
        return 0;

    // start with value 2
    unsigned int sum = 2;
    // tests every second number to be a prime (the skiped number is always a
    // divisor of 2)
    for (unsigned int i = 3; i <= max_number; i += 2) {
        // testPrime returns true, if the given number is a Prime
        if (is_prime(i)) {
            sum = sum + i;
        }
    }
    return sum;
}
