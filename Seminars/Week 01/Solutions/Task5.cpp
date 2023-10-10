#include <iostream>

int main(){

    int n;
    std::cin >> n;
    int flipped = 100 * (n % 10) + 10 * ((n / 10) % 10) + n / 100;
    std::cout << flipped;

}