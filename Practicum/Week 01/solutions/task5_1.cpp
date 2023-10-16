#include <iostream>

int main()
{
    const double PI = 3.14159;

    double r;
    std::cin >> r;

    std::cout << "V = " << (4 * PI * r * r * r) / 3 << std::endl;
    
    return 0;
}
