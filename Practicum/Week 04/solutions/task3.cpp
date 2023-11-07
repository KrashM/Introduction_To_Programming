#include <iostream>

int main()
{
    unsigned int x, n;
    std::cin >> x >> n;

    unsigned short count = 0;

    while(x != 0)
    {
        if(x % 10 == n)
        {
            count++;
        }
        x /= 10;    // x = x / 10
    }

    std::cout << count << std::endl;    
    return 0;
}
