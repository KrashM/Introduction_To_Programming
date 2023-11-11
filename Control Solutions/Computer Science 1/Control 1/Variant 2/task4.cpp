#include <iostream>

unsigned Pow(unsigned n, unsigned power){

    unsigned result = 1;
    for(unsigned i = 1; i <= power; ++i) result *= n;
    return result;

}

int main(){

    unsigned N, K, count = 0;
    std::cin >> N >> K;

    if(!N){

        std::cout << "Invalid input\n";
        return -1;

    }

    for(unsigned i = 1; Pow(K, i) <= N; ++i) ++count;

    std::cout << count << '\n';

    return 0;

}