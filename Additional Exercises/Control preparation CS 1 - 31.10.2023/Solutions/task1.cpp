#include <iostream>

int countNumbersLessThanX(int n, int x)
{
    int number;
    int counter = 0;
    for (int i = 1; i <= n; i++)
    {
        std::cin >> number;
        if (number < x)
            counter++;
    }
    return counter;
}

int main()
{
    int x, n;
    std::cin >> n >> x;
    std::cout << countNumbersLessThanX(n, x) << std::endl;
}