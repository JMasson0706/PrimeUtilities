# Prime Utilities in C++

This C++ program implements a set of number theory utilities related to prime numbers. It allows users to input an integer and:

- Generate all prime numbers less than the input using the **Sieve of Eratosthenes**.
- Check if the number is prime using the **Miller-Rabin primality test**.
- Return all **prime factors** (and the number itself).

## Features

- Efficient computation of all primes less than `n`.
- Probabilistic primality testing via the Miller-Rabin algorithm.
- Prime factor identification using precomputed primes.

## How It Works

1. **User Input**: Prompts for an integer `n`.
2. **Sieve of Eratosthenes**: Computes all primes `< n`.
3. **Miller-Rabin**: Tests if `n` is likely prime using `k=100` rounds.
4. **Prime Factors**: Finds all prime factors of `n` from the sieve (and includes `n` itself).
5. **Output**:
   - List of all primes less than `n`
   - Primality result (`prime` or `composite`)
   - Prime factors of `n`

## Example

```
Enter number: 
30
2 3 5 7 11 13 17 19 23 29 
composite
2 3 5 30 
```

## Files

- `main.cpp` – Main program source code

## Notes

- The Miller-Rabin test is probabilistic; using `k = 100` gives high confidence.
- The `primeFactors` function only checks divisibility by primes less than `n`, then appends `n` at the end.

## Compilation

To compile and run:

```bash
g++ -std=c++17 main.cpp -o prime_utils
./prime_utils
