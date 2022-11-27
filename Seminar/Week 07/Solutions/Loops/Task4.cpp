#include <iostream>

bool isSpecial(const unsigned int n){

    unsigned int powTen = 1, sum = 1;

    while(powTen <= n){

        sum *= (n / powTen) % 10;
        if(!sum) return false;
        powTen *= 10;

    }

    return sum && !(n % sum);

}

unsigned int findSpecials(const unsigned int a, const unsigned int b){

    unsigned int count = 0;
    for(unsigned int i = a; i <= b; i++) count += isSpecial(i);
    return count;

}

int main(){

    unsigned int a, b;
    std::cin >> a >> b;
    std::cout << findSpecials(a, b) << '\n';

}