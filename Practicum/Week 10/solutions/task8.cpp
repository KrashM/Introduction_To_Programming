#include <iostream>
#include <cstring>

const unsigned int MAX_SIZE = 100, MAX_LEN = 20;

void ReadArray(char array[][MAX_LEN], const unsigned int n)
{
    for(unsigned i = 0; i < n; i++)
    {
        std::cin >> array[i];
    }
}

void ClearArray(char array[][MAX_LEN], unsigned int& n)
{
    unsigned int k = 0, read = 0, write = 0;
    while(read < n)
    {
        if(strlen(array[read]) < 4)
        {
            read++; k++;
        }
        else
        {
            strcpy(array[write], array[read]);
            read++; write++;
        }
    }
    n -= k;
}

void PrintArray(const char array[][MAX_LEN], const unsigned int n)
{
    for(unsigned i = 0; i < n; i++)
    {
        std::cout << array[i] << std::endl;
    }
}

int main()
{
    char array[MAX_SIZE][MAX_LEN];
    unsigned int n;
    do
    {
        std::cout << "Enter n: ";
        std::cin >> n;
    } while(n > MAX_SIZE);

    ReadArray(array, n);
    ClearArray(array, n);

    std::cout << std::endl;
    PrintArray(array, n);
    return 0;
}
