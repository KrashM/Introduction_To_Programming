#include <iostream>

void printStarPyramid(int n)
{

    for (int i = 0; i <= n; i++)
    {
        for (int j = n - 1; j >= i; j--)
            std::cout << ' ';
        for (int j = 1; j <= 2 * i - 1; j++)
            std::cout << '*';

        std::cout << "\n";
    }
    for (int i = n - 1; i > 0; i--)
    {
        for (int j = i; j <= n - 1; j++)
            std::cout << ' ';
        for (int j = 1; j <= 2 * i - 1; j++)
            std::cout << '*';
        std::cout << "\n";
    }
}

int main()
{
    int n;
    std::cin >> n;
    printStarPyramid(n);
}