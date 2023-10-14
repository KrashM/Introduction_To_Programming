#include <iostream>

int main() {
    int num = 10;

    if (num > 10) {
        std::cout << "The number is greater than 10." << std::endl;
    } else if (num < 10) {
        std::cout << "The number is less than 10." << std::endl;
    } else {
        std::cout << "The number is equal to 10." << std::endl;
    }

    return 0;
}
