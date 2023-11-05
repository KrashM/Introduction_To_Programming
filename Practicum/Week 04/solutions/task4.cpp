#include <iostream>

int main()
{
    unsigned int n;
    std::cin >> n;

    unsigned int reversed = 0, copy = n;

    while(copy != 0)
    {
        reversed *= 10;
        reversed += copy % 10;
        copy /= 10;
    }

    std::cout << std::boolalpha << (n == reversed) << std::endl;
    return 0;
}
