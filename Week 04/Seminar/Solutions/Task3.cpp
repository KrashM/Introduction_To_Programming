#include <iostream>

bool isSufix(unsigned int n, unsigned int m){

    while(m != 0){

        if(n % 10 != m % 10) return false;
        n /= 10;
        m /= 10;

    }

    return true;

}

int main(){

    unsigned int n, m;
    std::cin >> n >> m;

    std::cout << std::boolalpha << isSufix(n, m) << '\n';

}