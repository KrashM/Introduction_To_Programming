#include <iostream>

unsigned long long findFactorial(unsigned int n){

    unsigned long long ans = 1;
    for(unsigned int i = 2; i < n; i++) ans *= i;
    return ans;

}

int main(){

    unsigned int n;
    std::cin >> n;

    std::cout << findFactorial(n) << '\n';

}