#include <iostream>

double pow(double x, int y)
{
    double result = 1;
    for (int i = 1; i <= y; i++)
    {
        result *= x;
    }
    return result;
}

double f(double x, int n)
{
    double powerX = pow(x, n);
    double sum = 0;
    double coef;
    for (int i = 0; i <= n; i++)
    {
        std::cin >> coef;
        sum += powerX * coef;
        powerX /= x;
    }
    return sum;
}

int main()
{
    double x, n;
    std::cin >> x >> n;
    std::cout << f(x, n) << std::endl;
}