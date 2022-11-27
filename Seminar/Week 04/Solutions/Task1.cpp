#include <iostream>

bool isEven(const unsigned int &n){

    return n % 2;

}

int main(){

    unsigned int n;
    std::cin >> n;

    std::cout << std::boolalpha << isEven(n) << '\n';

}