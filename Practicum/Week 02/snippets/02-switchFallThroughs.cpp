#include <iostream>

int main() {
    int num = 2;
    int num2 = 0;

    std::cout << "Switch one:\n";
    switch(num) {
        case 1:
            std::cout << "Number is 1" << std::endl;
        case 2:
            std::cout << "Number is 2" << std::endl;
        case 3:
            std::cout << "Number is 3" << std::endl;
        default:
            std::cout << "Number is not 1, 2, or 3" << std::endl;
    }

    std::cout << "Switch two:\n";
    switch(num) {
        default:
            std::cout << "Number is not 1, 2, or 3" << std::endl;
        case 1:
            std::cout << "Number is 1" << std::endl;
        case 2:
            std::cout << "Number is 2" << std::endl;
        case 3:
            std::cout << "Number is 3" << std::endl;
    }

    std::cout << "Switch three:\n";
    switch(num2) {
        default:
            std::cout << "Number is not 1, 2, or 3" << std::endl;
        case 1:
            std::cout << "Number is 1" << std::endl;
        case 2:
            std::cout << "Number is 2" << std::endl;
        case 3:
            std::cout << "Number is 3" << std::endl;
    }

    return 0;
}
