#include <iostream>

int main()
{
    char letter;
    std::cin >> letter;

    char uppercase = letter - 'a' + 'A';
    std::cout << uppercase << std::endl;
    
    return 0;
}
