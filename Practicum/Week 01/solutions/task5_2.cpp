#include <iostream>
#include <cmath>

int main()
{
    const double PI = 3.14159;

    double r, h;
    std::cin >> r >> h;

    std::cout << "V = " << (PI * r * r * h) / 3  << std::endl;
    
    return 0;
}
