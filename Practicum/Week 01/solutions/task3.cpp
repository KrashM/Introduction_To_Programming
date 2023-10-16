#include <iostream>

int main()
{
    int num;
    std::cin >> num;
    
    int firstDigit = num / 100,
        secondDigit = (num / 10) % 10,
        thirdDigit = num % 10;

    std::cout << std::boolalpha << (firstDigit % 2 && secondDigit % 2 && thirdDigit % 2) << std::endl;
    
    return 0;
}
