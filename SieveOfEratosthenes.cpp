#include <iostream>
#include <vector>
#include <cmath>

// Handles user input
const int getInt() 
{
    std::cout << "Enter number: \n";
    int num{};
    std::cin >> num;
    return num;
}

std::vector<int> primesUnderN(int num) 
{
    int isPrime[num];
	
	for (int i{ 0 }; i < num; ++i) {
	    isPrime[i] = 1;
	}

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

int main() 
{
    
	const int num{ getInt() };
    
    std::vector<int> primes{ primesUnderN(num) };
    
    
    // ouput primes 
    for (int p : primes) {
        std::cout << p << ' ';
    }
    
    std::cout << "\n";
    return 0;
    
}

