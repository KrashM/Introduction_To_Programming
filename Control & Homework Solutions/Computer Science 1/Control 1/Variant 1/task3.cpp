#include <iostream>

int main(){

    unsigned N, a, prev, count = 1;
    std::cin >> N;

    if(N == 0){

        std::cout << 0 << '\n';
        return 0;

    }

    std::cin >> prev;

    for(unsigned i = 1; i < N; ++i){

        std::cin >> a;

        if(a >= prev) ++count;
        else break;

        prev = a;

    }

    std::cout << count << '\n';

    return 0;

}