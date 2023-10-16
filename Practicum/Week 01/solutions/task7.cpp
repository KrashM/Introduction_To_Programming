#include <iostream>

int main()
{
    int a, b, c;
    std::cin >> a >> b >> c;

    std::cout << std::boolalpha << (std::min(a, c) < b && b < std::max(a, c)) << std::endl;

    std::cout << std::boolalpha << ((a - c < 0 && a < b && b < c) ||          // a < c
                                    (a - c > 0 && c < b && b < a))            // a > c
              << std::endl; 

    // Bonus task 
    std::cout << std::boolalpha << ((a - c) * (c - b) < 0) << std::endl; 

    return 0;
}
