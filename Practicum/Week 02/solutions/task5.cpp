#include <iostream>

int main() {

    int kilos;
    char destination;

    std::cin >> kilos >> destination;
    switch (destination)
    {
    case 'A':
        std::cout << kilos * 5 << std::endl; 
        break;
    case 'B':
        std::cout << kilos * 7 << std:: endl;
        break;
    case 'C':
        std::cout << kilos * 10 << std::endl;
        break;
    }
}