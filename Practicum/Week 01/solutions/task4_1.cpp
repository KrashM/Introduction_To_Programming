#include <iostream>
#include <cmath>

int main()
{
    double a, b, c;
    std::cin >> a >> b >> c;

    double p = (a + b + c) / 2;
    std::cout << "S = " << sqrt(p * (p - a) * (p - b) * (p - c)) << std::endl;

    return 0;
}
