#include <iostream>

unsigned int pow(const unsigned int &n, const unsigned int &k){

    unsigned int result = 1;
    for(unsigned int i = 0; i < k; i++) result *= n;

    return result;

}

int main(){

    unsigned int n, k;
    std::cin >> n >> k;

    std::cout << pow(n, k) << '\n';

}