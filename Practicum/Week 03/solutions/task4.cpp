#include <iostream>

int main() {

    int num;
    std::cin >> num;

    int mask = num >> (sizeof(int) * 8 - 1);
    int absVal = (num + mask) ^ mask;

    std::cout << "Absolute value: " << absVal << '\n';

    return 0;

}