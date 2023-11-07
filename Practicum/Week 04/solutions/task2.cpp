#include <iostream>

int main()
{
    unsigned int n;
    std::cin >> n;

    unsigned int fact = 1;
    
    for(int i = 2; i <= n; i++)
    {
        fact *= i;  // fact = fact * i;
    }

    std::cout << fact << std::endl;
    return 0;
}
