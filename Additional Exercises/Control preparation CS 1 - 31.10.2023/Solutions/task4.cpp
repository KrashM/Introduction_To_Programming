#include <iostream>

int sumOfDigits(int n)
{
    int sum = 0;
    while (n != 0)
    {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

int addDigits(int n)
{
    while (n >= 10)
    {
        n = sumOfDigits(n);
    }
    return n;
}

int main()
{
    int n;
    std::cin >> n;
    std::cout << addDigits(n) << std::endl;
}