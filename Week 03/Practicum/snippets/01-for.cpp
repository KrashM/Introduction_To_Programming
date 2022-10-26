#include <iostream>
#include <cstddef>

int main ()
{
    std::size_t n;
    std::cin >> n;

    for (std::size_t i = 1; i <= n; ++i)
    {
        for (std::size_t j = 1; j <= i; ++j)
        {
            std::cout << j << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}