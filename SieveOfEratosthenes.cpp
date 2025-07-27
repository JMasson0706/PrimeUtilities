#include <iostream>
#include <vector>
#include <cmath>
#include <random>


// Handles user input
const int getInt() 
{
    std::cout << "Enter number: \n";
    int num{};
    std::cin >> num;
    return num;
}

// 
int modPow(int base, int exp, int mod) {
    int result = 1;
    base %= mod;
    while (exp > 0) {
        if (exp % 2 == 1)
            result = static_cast<int>((1LL * result * base) % mod);
        base = static_cast<int>((1LL * base * base) % mod);
        exp /= 2;
    }
    return result;
}


// Sieve of Eratosthenes: calculates all primes up to n
std::vector<int> primesUnderN(int num) 
{
    std::vector<int> isPrime(num, 1);

    const int limit = static_cast<int>(std::sqrt(num));
    
    // marks all multiples of # as false
    for (int i{ 2 }; i < limit; ++i) 
    {
        if (isPrime[i] == 0) {
            continue;
        } else {
            for (int j{ i * i }; j < num; j += i)
            {
                isPrime[j] = 0;
            }
        }
    }
    
    std::vector<int> primes{};
    // Iterates through array marking all true indices as primes
    for (int i{ 1 }; i < num; ++i){
        if (isPrime[i] == 1) primes.push_back(i);
    }
    
    return primes;
}


// Miller-Rabin Test to determine whether a number is prime or not
bool millerRabinTest(int num, int k) {
    // Obvious prime tests
    if (num <=1) return false;
    if (num == 2) return true;
    if (num % 2 == 0) return false;

    int d{ num - 1 };
    int s{ 0 };

    while (d % 2 == 0) {
        d /= 2;
        s += 1;
    }

    std::random_device rd;  // a seed source for the random number engine
    std::mt19937 gen(rd()); // mersenne_twister_engine seeded with rd()
    std::uniform_int_distribution<> distrib(2, num - 2);


    // Miller-Rabin algorithm
    for (int i{ 0 }; i < k; ++i) {
        int a{ distrib(gen) };
        int x{ modPow(a, d, num) };
        if (x == 1 || x == num - 1) continue;

        bool witness = true;
        for (int r = 1; r < s; ++r) {
            x = modPow(x, 2, num);
            if (x == num - 1) {
                witness = false;
                break;
            }
        }
        if (witness) return false;
    }
    return true;

}

// Returns all prime factors of num (including num)
std::vector<int> primeFactors(int num, std::vector<int> primes)
{
    std::vector<int> primefacts{};
    for (int i{ 0 }; i < primes.size(); ++i) {
        if (num % primes[i] == 0) primefacts.push_back(primes[i]);
    }
    primefacts.push_back(num);
    return primefacts;
}


int main() 
{
    
	const int num{ getInt() };
    
    std::vector<int> primes{ primesUnderN(num) };
    std::vector<int> primeFactor{ primeFactors(num, primes) };
    
    //ouput primes 
    for (int p : primes) {
        std::cout << p << ' ';
    }
    
    std::cout << "\n";
    
    if (millerRabinTest(num, 100)) {
        std::cout << "prime\n";
    } else {
        std::cout << "composite\n";
    }
    
    for (int p : primeFactor) {
        std::cout << p << ' ';
    }
    std::cout << "\n";
    return 0;
    
}

