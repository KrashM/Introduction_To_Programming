#include <iostream>

int main()
{
    const unsigned int MAX_SIZE = 10;
    unsigned int count[MAX_SIZE] = {0,};

    unsigned int k;
    std::cout << "Enter k: ";
    std::cin >> k;

    for(unsigned i = 0; i < k; i++)
    {
        unsigned short digit;
        do
        {
            std::cin >> digit;
        } while(digit > 9);

        count[digit]++;
    }

    for(unsigned i = 0; i < MAX_SIZE; i++)
    {
        std::cout << '[' << i << "]: " << count[i] << std::endl;
    }

    return 0;
}
