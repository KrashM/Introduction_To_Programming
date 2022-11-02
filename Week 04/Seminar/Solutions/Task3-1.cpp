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

bool isPrefix(unsigned int n, unsigned int m){

    unsigned int digitsN = numberOfDigits(n), digitsM = numberOfDigits(m),
                powN = pow(10, digitsN - 1), powM = pow(10, digitsM - 1);

    while(powM != 0){

        if(n / powN % 10 != m / powM % 10) return false;
        powN /= 10;
        powM /= 10;

    }

    return true;

}

int main(){

    unsigned int n, m;
    std::cin >> n >> m;

    std::cout << std::boolalpha << isPrefix(n, m) << '\n';

}