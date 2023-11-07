#include <iostream>

int main()
{
    unsigned int n;
    std::cin >> n;

    int a = 1, b = 0, c;
    for(int i = 0; i < n ; i++)
    {
        c = a + b;
        std::cout << c << ' ';

        a = b;
        b = c;
    }

    std::cout << std::endl;
    return 0;
}
