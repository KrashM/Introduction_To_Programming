#include <iostream>

int getPrimeDivisorsCount(int n)
{
    int count = 0;
    int lastNum = 1;
    int index = 2;
    while (n > 1)
    {
        if (n % index == 0)
        {
            n /= index;
            if (lastNum != index)
                count++;
            lastNum = index;
        }
        else
            index++;
    }
    return count;
}

void printNumbers(int a, int b, int c)
{

    for (int i = a; i <= b; i++)
    {
        if (getPrimeDivisorsCount(i) == c)
            std::cout << i << ' ';
    }
}

int main()
{
    int a, b, c;
    std::cin >> a >> b >> c;
    printNumbers(a, b, c);
}