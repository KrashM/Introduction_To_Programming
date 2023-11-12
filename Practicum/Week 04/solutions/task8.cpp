#include <iostream>
#include <cmath>

int main()
{
    unsigned int n;
    std::cin >> n;

    unsigned int count = 0, sum = 0, copy = n;

    while(copy != 0)
    {
        count++;
        copy /= 10;
    }

    copy = n;

    while(copy != 0)
    {
        sum += pow(copy % 10, count);
        copy /= 10;
    }

    std::cout << std::boolalpha << (sum == n) << std::endl;
    return 0;
}
