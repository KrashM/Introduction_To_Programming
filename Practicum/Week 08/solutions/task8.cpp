#include <iostream>

const unsigned int MAX_SIZE = 100;

unsigned int ReadSize()
{
    unsigned int size;
    do
    {
        std::cin >> size;
    } while (size == 0 || size > MAX_SIZE);

    return size;
}

void ReadMatrix(int matrix[][MAX_SIZE], const unsigned int n, const unsigned int m)
{
    for (unsigned i = 0; i < n; i++)
    {
        for (unsigned j = 0; j < m; j++)
        {
            std::cin >> matrix[i][j];
        }
    }
}

void PrintMatrix(const int matrix[][MAX_SIZE], const unsigned int n, const unsigned int m)
{
    for (unsigned i = 0; i < n; i++)
    {
        for (unsigned j = 0; j < m; j++)
        {
            std::cout << matrix[i][j] << ' ';
        }
        std::cout << std::endl;
    }
}

void TransformMatrix(int matrix[][MAX_SIZE], const unsigned int n, const unsigned int m)
{
    int j;
    for (unsigned i = 0; i < n; i++)
    {
        j = 0;
        while (matrix[i][j] != 1 && j < m)
        {
            j++;
        }
        if (j == m)
        {
            continue;
        }
        for (unsigned k = 0; k < m; k++)
        {
            matrix[i][k] = 1;
        }
    }
}

int main()
{
    int matrix[MAX_SIZE][MAX_SIZE];

    unsigned int n = ReadSize(),
                 m = ReadSize();

    ReadMatrix(matrix, n, m);

    std::cout << std::endl;
    
    TransformMatrix(matrix, n, m);
    PrintMatrix(matrix, n, m);

    return 0;
}