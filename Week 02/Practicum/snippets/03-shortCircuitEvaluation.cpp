#include <iostream>

int main ()
{
    int a = 4, b = 5;

    if ((++b == 6) || (a-- < 4)) // the first one is 'true', so the second one will not evaluate
    {
        // directly goes here without avaluating the second statement
        std::cout << "if" << std::endl;
    }
    else
    {
        std::cout << "else" << std::endl;
    }

    std::cout << a << " " << b << std::endl; // 4 6

    int c = 4, d = 5;

    if ((c-- < 4) && (++d == 6)) // the first one is 'false', so the second one will not evaluate
    {
        std::cout << "if" << std::endl;
    }
    else
    {
        // directly goes here without avaluating the second statement
        std::cout << "else" << std::endl;
    }

    std::cout << c << " " << d << std::endl; // 3 5
    
    return 0;
}