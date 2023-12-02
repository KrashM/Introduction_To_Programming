#include <iostream>

const unsigned int MAX_SIZE = 100;

unsigned int ReadSize()
{
    unsigned int size;
    do
    {
        std::cin >> size;
    } while(size == 0 || size > MAX_SIZE);

    return size;
}

void ReadMatrix(int matrix[][MAX_SIZE], const unsigned int n, const unsigned int m)
{
    for(unsigned i = 0; i < n; i++)
    {
        for(unsigned j = 0; j < m; j++)
        {
            std::cin >> matrix[i][j];
        }
    }    
}

void CountEvenAndOdd(const int matrix[][MAX_SIZE], const unsigned int n, const unsigned int m)
{
    unsigned int even = 0, odd = 0, 
                 limit = n < m ? n : m;
    
    for(unsigned i = 0; i < limit; i++)
    {
        for(unsigned j = 0; j < i; j++)
        {
            if(matrix[i][j] % 2 == 0)
            {
                even++;
            }
        }
    }
    std::cout << "Even: " << even << std::endl;

    for(unsigned i = 0; i < n; i++)
    {
        for(unsigned j = i + 1; j < m; j++)
        {
            if(matrix[i][j] % 2 != 0)
            {
                odd++;
            }
        }
    }  
    std::cout << "Odd: " << odd << std::endl;
}

int main()
{
    int matrix[MAX_SIZE][MAX_SIZE];

    unsigned int n = ReadSize(),
                 m = ReadSize();

    ReadMatrix(matrix, n, m);
    std::cout << std::endl;
    CountEvenAndOdd(matrix, n, m);
    
    return 0;
}
