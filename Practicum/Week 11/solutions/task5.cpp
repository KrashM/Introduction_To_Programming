#include <iostream>

void Deallocate(int const * const * const matrix, const unsigned int n)
{
    for(unsigned i = 0; i < n; i++)
    {
        delete[] matrix[i];
    } 
    delete[] matrix;
}

int** AllocateMatrix(const unsigned int n, const unsigned int m)
{
    int** matrix = new(std::nothrow) int*[n];
    if(!matrix)
    {
        return nullptr;
    }

    for(unsigned i = 0; i < n; i++)
    {
        matrix[i] = new(std::nothrow) int[m];
        if(!matrix[i])
        {
            Deallocate(matrix, i);
            matrix = nullptr;

            return nullptr;
        }
    }

    return matrix;
}

void ReadMatrix(int * const * const matrix, const unsigned int n, const unsigned int m)
{
    for(unsigned i = 0; i < n; i++)
    {
        for(unsigned j = 0; j < m; j++)
        {
            std::cin >> matrix[i][j];
        }
    }
}

int* MinInRow(int const * const * const matrix, const unsigned int n, const unsigned int m)
{
    int* minInRow = new(std::nothrow) int[n];
    if(!minInRow)
    {
        return nullptr;
    }

    for(unsigned i = 0; i < n; i++)
    {
        minInRow[i] = INT_MAX;
        for(unsigned j = 0; j < m; j++)
        {
            if(matrix[i][j] < minInRow[i])
            {
                minInRow[i] = matrix[i][j];
            }
        }
    }  

    return minInRow;
}

int* MaxInCol(int const * const * const matrix, const unsigned int n, const unsigned int m)
{
    int* maxInCol = new(std::nothrow) int[m];
    if(!maxInCol)
    {
        return nullptr;
    }

    for(unsigned i = 0; i < m; i++)
    {
        maxInCol[i] = INT_MIN;
        for(unsigned j = 0; j < n; j++)
        {
            if(matrix[j][i] > maxInCol[i])
            {
                maxInCol[i] = matrix[j][i];
            }
        }
    }  

    return maxInCol;
}

void PrintLuckyNumbers(int const * const * const matrix, const unsigned int n, const unsigned int m)
{
    int* minInRow = MinInRow(matrix, n, m);
    if(!minInRow)
    {
        std::cout << "Memory problem!" << std::endl;
        return;
    }

    int* maxInCol = MaxInCol(matrix, n, m);
    if(!maxInCol)
    {
        std::cout << "Memory problem!" << std::endl;

        delete[] minInRow;
        minInRow = nullptr;

        return;
    }

    for(unsigned i = 0; i < n; i++)
    {
        for(unsigned j = 0; j < m; j++)
        {
            if(matrix[i][j] == minInRow[i] && matrix[i][j] == maxInCol[j])
            {
                std::cout << matrix[i][j] << ' ';
            }
        }
    }
    std::cout << std::endl;

    delete[] minInRow;
    minInRow = nullptr;

    delete[] maxInCol;
    maxInCol = nullptr;
}

int main()
{
    unsigned n, m;
    std::cin >> n >> m;

    int** matrix = AllocateMatrix(n, m);
    if(!matrix)
    {
        std::cout << "Memory problem!" << std::endl;
        return -1;
    }

    ReadMatrix(matrix, n, m);

    std::cout << std::endl;
    PrintLuckyNumbers(matrix, n, m);

    Deallocate(matrix, n);
    return 0;
}
