#include <iostream>

unsigned Factorial(unsigned n){

    unsigned fact = 1;
    for(unsigned i = 2; i <= n; ++i) fact *= i;
    return fact;

}

int main(){

    unsigned N, count = 0;
    std::cin >> N;

    if(!N){

        std::cout << "Invalid input\n";
        return -1;

    }

    for(unsigned i = 1; Factorial(i) <= N; ++i) ++count;

    std::cout << count << '\n';

    return 0;

}