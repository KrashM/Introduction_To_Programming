#include <iostream>

int** AllocateMatrix(const size_t rows, const size_t cols)
{
    int** matrix = new(std::nothrow) int*[rows];
    if(!matrix)
    {
        return nullptr;
    }

    for(size_t i = 0; i < rows; i++)
    {
        matrix[i] = new(std::nothrow) int[cols];
        if(!matrix[i])
        {
            for(size_t j = 0; j < i; j++)
            {
                delete[] matrix[j];
            }
            delete[] matrix;
            matrix = nullptr;

            return nullptr;
        }
    }

    return matrix;
}

void ReadMatrix(int** matrix, const size_t rows, const size_t cols)
{
    for(size_t i = 0; i < rows; i++)
    {
        for(size_t j = 0; j < cols; j++)
        {
            std::cin >> matrix[i][j];
        }
    }
}

void PrintMatrix(int** matrix, const size_t rows, const size_t cols)
{
    for(size_t i = 0; i < rows; i++)
    {
        for(size_t j = 0; j < cols; j++)
        {
            std::cout << matrix[i][j] << ' ';
        }
        std::cout << std::endl;
    }
}

void Deallocate(int** matrix, const size_t rows)
{
    for(size_t i = 0; i < rows; i++)
    {
        delete[] matrix[i];
    } 
    delete[] matrix;
    matrix = nullptr;
}

int main()
{
    size_t rows, cols;
    std::cin >> rows >> cols;

    int** matrix = AllocateMatrix(rows, cols);
    if(!matrix)
    {
        std::cout << "Memory problem!" << std::endl;
        return -1;
    }

    ReadMatrix(matrix, rows, cols);

    std::cout << std::endl;
    PrintMatrix(matrix, rows, cols);

    Deallocate(matrix, rows);
    return 0;
}
