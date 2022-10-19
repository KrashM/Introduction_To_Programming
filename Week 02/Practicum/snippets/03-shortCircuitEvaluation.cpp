#include <iostream>

int main ()
{
    int a = 4, b = 5, c = 6;

    if ((a-- < 4) && (++b == 6)) 
    {
        std::cout << "if" << std::endl;
    }
    else
    {
        std::cout << "else" << std::endl;
    }

    std::cout << a << " " << b << std::endl;
    
    return 0;
}