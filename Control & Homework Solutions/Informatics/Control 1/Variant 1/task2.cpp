#include <iostream>
#include <cmath>

bool IsPrime(unsigned const number){

    for(unsigned i = 2; i <= std::sqrt(number); ++i)
        if(number % i == 0)
            return false;
    return true;

}

int main(){

    unsigned n, counter = 0, number = 2;
    std::cin >> n;
    
    while(counter < n){

        if(IsPrime(number) && IsPrime(number + 2)){

            std::cout << number << ' ' << number + 2 << '\n';
            counter++;

        }

        number++;

    }

    return 0;

}