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

void PrintMin(const int matrix[][MAX_SIZE], const unsigned int n, const unsigned int m)
{
    for(unsigned i = 0; i < m; i++)
    {
        int min = INT_MAX;
        for(unsigned j = 0; j < n; j++)
        {
            if(matrix[j][i] < min)
            {
                min = matrix[j][i];
            }
        }
        std::cout << min << std::endl;
    }  
}

int main()
{
    int matrix[MAX_SIZE][MAX_SIZE];

    unsigned int n = ReadSize(),
                 m = ReadSize();

    ReadMatrix(matrix, n, m);
    std::cout << std::endl;
    PrintMin(matrix, n, m);
    
    return 0;
}
