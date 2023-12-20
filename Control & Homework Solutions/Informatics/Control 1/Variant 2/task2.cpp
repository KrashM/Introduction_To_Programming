#include <iostream>
#include <cmath>

bool IsPrime(unsigned const number){

    if(number < 2) return false;

    for(unsigned i = 2; i <= std::sqrt(number); ++i)
        if(number % i == 0)
            return false;
    return true;

}

bool HasTwoDifferentPrimeFactors(unsigned const number){

    for(unsigned i = 0; i < number; ++i)
        if(i != number - i && IsPrime(i) && IsPrime(number - i))
            return true;
    return false;

}

int main(){

    unsigned n, counter = 0, number = 2;
    std::cin >> n;

    if(n > 100'000'000){

        std::cout << "Wrong input\n";
        return -1;

    }
    
    for(unsigned i = 0; i * i < n; ++i)
        if(HasTwoDifferentPrimeFactors(i * i))
            std::cout << i * i << '\n';

    return 0;

}