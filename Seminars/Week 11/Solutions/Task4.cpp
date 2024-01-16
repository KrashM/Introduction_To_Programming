#include <iostream>

bool HasConsecotiveOnes(unsigned const n){

    unsigned mask = 1;

    while(mask <= n){

        if(n & mask && n & (mask << 1)) return true;
        mask <<= 1;

    }

    return false;

}

void PrintSpecifiedNumbers(unsigned const numberOfBits, unsigned const n = 1){

    if(n == 1 << numberOfBits) return;
    if(!HasConsecotiveOnes(n)) std::cout << n << ' ';
    PrintSpecifiedNumbers(numberOfBits, n + 1);

}

int main(){

    unsigned numberOfBits;
    std::cin >> numberOfBits;

    PrintSpecifiedNumbers(numberOfBits);
    std::cout << '\n';

    return 0;

}