#include <iostream>

int main()
{
    unsigned short x, n;
    std::cin >> x >> n;

    if(x > 255 || n > 7)
    {
        std::cout << "Incorrect input." << std::endl;
        return 1;
    }

    //change bit with index n to 1
    x |= (1 << n);  // x = x | (1 << n)
    std::cout << x << std::endl;

    //change bit with index n to 0
    x &= ~(1 << n);  // x = x & ~(1 << n)
    std::cout << x << std::endl;

    //toggle bit with index n
    x ^= (1 << n);  // x = x ^ (1 << n)
    std::cout << x << std::endl;

    return 0;
}
