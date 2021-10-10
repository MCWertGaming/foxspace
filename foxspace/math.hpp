#include <cstdint>

namespace Fox {
// returns a random number between 0 and the given one
uint32_t get_randomNumber(uint32_t);
// returns true if the given number is a prime
uint32_t is_prime(uint32_t);
// returns the summed prime numbers from 1 to the given one
uint64_t prime_sum(uint32_t);
}  // namespace Fox
