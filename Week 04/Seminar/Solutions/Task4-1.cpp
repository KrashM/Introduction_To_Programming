#include <iostream>

unsigned int log_k(unsigned int n, const unsigned int &k){

    unsigned int result = 0;
    while(n >= k){

        result++;
        n /= k;

    }

    return result;

}

int main(){

    unsigned int n, k;
    std::cin >> n >> k;

    std::cout << log_k(n, k) << '\n';

}