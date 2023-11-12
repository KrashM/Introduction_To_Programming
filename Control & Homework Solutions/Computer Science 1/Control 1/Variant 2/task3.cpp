#include <iostream>

int main(){

    unsigned S, N, a, count = 0, sum = 0;
    std::cin >> S >> N;

    if(N == 0){

        std::cout << 0 << '\n';
        return 0;

    }

    for(unsigned i = 0; i < N; ++i){

        std::cin >> a;
        sum += a;

        if(sum < S) ++count;
        else break;

    }

    std::cout << count << '\n';

    return 0;

}