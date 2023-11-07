#include <iostream>

int main()
{
    unsigned int n;
    std::cin >> n;

    for(int i = 1; i <= n; i++)
    {
        if(n % i == 0)
        {
            std::cout << i << ' ';
        }
    }
    
    std::cout << std::endl;
    return 0;
}
