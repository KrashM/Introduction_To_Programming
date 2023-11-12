#include <iostream>

int main()
{
    int x = 1;

    x <<= 12;           // x = x << 12
    x |= 8;
    x |= (1 << 5);
    x |= (1 << 6);
    x |= (1 << 8);
    x |= (1 << 10);
    x >>= 3;            // x = x >> 3
    x ^= (1 << 2);      // x = x ^ (1 << 2)

    std::cout << x << std::endl;
    return 0;
}
