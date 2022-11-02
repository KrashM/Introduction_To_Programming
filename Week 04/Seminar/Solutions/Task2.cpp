#include <iostream>

unsigned int pow(const unsigned int &n, const unsigned int &pow){

    unsigned int res = 1;
    for(unsigned int i = 0; i < pow; i++) res *= n;

    return res;

}

unsigned int numberOfDigits(const unsigned int &n){

    unsigned int copyN = n, digits = 0;
    while(copyN != 0){

        digits++;
        copyN /= 10;

    }

    return digits;

}

bool isPalindrome(const unsigned int &n){

    unsigned int digits = numberOfDigits(n), biggerPow = pow(10, digits - 1), smallerPow = 1;
    for(unsigned int i = 0; i < digits / 2; i++){

        if(n / biggerPow % 10 != n / smallerPow % 10) return false;
        biggerPow /= 10;
        smallerPow *= 10;

    }

    return true;

}

int main(){

    unsigned int n;
    std::cin >> n;

    std::cout << std::boolalpha << isPalindrome(n) << '\n';

}