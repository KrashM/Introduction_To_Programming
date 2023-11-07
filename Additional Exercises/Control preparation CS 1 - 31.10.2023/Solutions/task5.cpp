#include <iostream>

int countBounces(double n, double coef)
{
    int count = 0;
    while (n > 1)
    {
        if (n * coef > 1)
            count++;
        n = n * coef;
    }
    return count;
}

int main()
{
    double n, coef;
    std::cin >> n >> coef;
    std::cout << countBounces(n, coef) << std::endl;
}
