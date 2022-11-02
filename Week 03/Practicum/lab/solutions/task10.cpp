#include <iostream>
#include <cstddef>


int main()
{
    int n;
    std::cin >> n;
    if (n % 2 == 0)
    {
        return 1;
    }

    // Note that the number n means the spaces between the stars on first and last row
    int spaces = n, offset = 0, iterations = n + 2;
    for (int i = 0; i < iterations; ++i)
    {
        for (int i = 0; i < offset; ++i)
        {
            std::cout << ' ';
        }

        if (i < iterations / 2)
        {
            offset += 2;
        }
        else
        {
            offset -= 2;
        }

        for (int j = 0; j < 3 - (2 * (i == iterations / 2)); ++j)
        {
            std::cout << '*';
            for (int i = 0; i < spaces; ++i)
            {
                std::cout << ' ';
            }
        }
        std::cout << '\n';

        if (i < iterations / 2)
        {
            spaces -= 2;
        }
        else
        {
            spaces += 2;
        }
    }

    return 0;
}