#include <iostream>

using std::cin;
using std::cout;
using std::size_t;

bool hasConsecotiveOnes(const unsigned int &n){

    unsigned int mask = 1;

    while(mask <= n){

        if(n & mask && n & (mask << 1)) return true;
        mask <<= 1;

    }

    return false;

}

void printSpecifiedNumbers(const unsigned int &numberOfBits, const unsigned int &n = 1){

    if(n == 1 << numberOfBits) return;
    if(!hasConsecotiveOnes(n)) cout << n << ' ';
    printSpecifiedNumbers(numberOfBits, n + 1);

}

int main(){

    unsigned int numberOfBits;
    cin >> numberOfBits;

    printSpecifiedNumbers(numberOfBits);
    cout << '\n';

}