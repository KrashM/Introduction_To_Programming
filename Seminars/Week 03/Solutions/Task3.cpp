#include <iostream>

int main(){

    int num1, num2, num3, num4, num5;

    std::cin >> num1 >> num2 >> num3 >> num4 >> num5;
    std::cout << (num1 ^ num2 ^ num3 ^ num4 ^ num5) << '\n';

    return 0;

}