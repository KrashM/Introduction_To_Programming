#include <iostream>

int main()
{
    int x, y;
    std::cin >> x >> y;

    std::cout<< std::boolalpha << ((x ^ y) < 0) << std::endl;
    return 0;
}
