#include <iostream>

int main()
{
    int a, b, c;
    std::cin >> a >> b >> c;

    std::cout << std::boolalpha << (a % 3 == 0) << std::endl; // !(a % 3) е алтернативен вариант
    std::cout << std::boolalpha << (b >= -9 && b <= 13) << std::endl;
    std::cout << std::boolalpha << (c < 0 || c > 8) << std::endl;
    std::cout << std::boolalpha << (a < 0 || b < 0 || c < 0) << std::endl;
    std::cout << std::boolalpha << (a == b && b == c) << std::endl;
    
    return 0;
}
