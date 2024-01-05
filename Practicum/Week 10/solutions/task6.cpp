#include <iostream>
#include <cstring>

const unsigned int MAX_SIZE = 100, MAX_LEN = 11;

void ReadArray(char array[][MAX_LEN], const unsigned int n)
{
    for(unsigned i = 0; i < n; i++)
    {
        std::cin >> array[i];
    }
}

void Swap(char* a, char* b)
{
    char temp[MAX_LEN];
    strcpy(temp, a);
    strcpy(a, b);
    strcpy(b, temp);
}

// selection sort -> asc
void Sort(char array[][MAX_LEN], const unsigned int n)
{
    for(unsigned i = 0; i < n; i++) 
    {
        unsigned minIndex = i;
        for(unsigned j = i + 1; j < n; j++) 
        {
            if(strlen(array[j]) < strlen(array[minIndex]))
            {
                minIndex = j;
            }
        }

        if(minIndex != i) 
        {
            Swap(array[minIndex], array[i]);
        }
    }
}

void PrintArray(const char array[][MAX_LEN], const unsigned int n)
{
    for(unsigned i = 0; i < n; i++)
    {
        std::cout << array[i] << ' ';
        if((i + 1) % 3 == 0)
        {
            std::cout << std::endl;
        }
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
    Sort(array, n);

    std::cout << std::endl;
    PrintArray(array, n);
    
    return 0;
}
