#include <iostream>

int main()
{
    unsigned int n;
    std::cin >> n;

    while(n != 0)
    {
        std::cout << n % 10;
        n /= 10;    // n = n / 10;
    }

    return 0;
}
