#include <iostream>

int main()
{
    char symbol;
    std::cin >> symbol;

    if(symbol >= '0' && symbol <= '9')
    {
        std::cout << "digit" << std::endl;
    }
    else if(symbol >= 'a' && symbol <= 'z')
    {
        std::cout << "lowercase" << std::endl;
    }
    else if(symbol >= 'A' && symbol <= 'Z')
    {
        std::cout << "uppercase" << std::endl;
    }
    else
    {
        std::cout << "The symbol is not a digit, lowercase or uppercase." << std::endl;
    }
    
    return 0;
}