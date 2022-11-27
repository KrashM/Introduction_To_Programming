#include <iostream>

bool isInfix(unsigned int n, unsigned int m){

    unsigned int powTen = 1;
    n /= 10;

    while(n >= 10){

        if(n % 10 != m / powTen % 10) powTen = 1;
        powTen *= 10;
        n /= 10;
        if(powTen > m) return true;

    }

    return false;

}

int main(){

    unsigned int n, m;
    std::cin >> n >> m;

    std::cout << std::boolalpha << isInfix(n, m) << '\n';

}