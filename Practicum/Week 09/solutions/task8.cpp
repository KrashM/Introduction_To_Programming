#include <iostream>

void Deallocate(int const * const * const matrix, const size_t rows)
{
    for(size_t i = 0; i < rows; i++)
    {
        delete[] (matrix + i);
    } 
    delete[] matrix;
}

int** AllocateMatrix(const size_t rows, const size_t cols)
{
    int** matrix = new(std::nothrow) int*[rows];
    if(!matrix)
    {
        return nullptr;
    }

    for(size_t i = 0; i < rows; i++)
    {
        *(matrix + i) = new(std::nothrow) int[cols];
        if(!*(matrix + i))
        {
            Deallocate(matrix, i);
            return nullptr;
        }
    }

    return matrix;
}

void ReadMatrix(int* const * const matrix, const size_t rows, const size_t cols)
{
    for(size_t i = 0; i < rows; i++)
    {
        for(size_t j = 0; j < cols; j++)
        {
            std::cin >> *(*(matrix + i) + j);
        }
    }
}

void Modify(int* const * const matrix, const size_t rows, const size_t cols)
{
    for(size_t i = 0; i < rows; i++)
    {
        size_t read = 0, write = 0;
        while(read < cols)
        {
            if(*(*(matrix + i) + read) == 0)
            {
                read++;
            }
            else
            {
                *(*(matrix + i) + write) = *(*(matrix + i) + read);
                write++;
                read++;
            }
        }
        for(size_t j = write; j < cols; j++)
        {
            *(*(matrix + i) + j) = 0;
        }
    }
}

void PrintMatrix(int const * const * const matrix, const size_t rows, const size_t cols)
{
    for(size_t i = 0; i < rows; i++)
    {
        for(size_t j = 0; j < cols; j++)
        {
            std::cout << *(*(matrix + i) + j) << ' ';
        }
        std::cout << std::endl;
    }
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
    Modify(matrix, rows, cols);

    std::cout << std::endl;
    PrintMatrix(matrix, rows, cols);

    Deallocate(matrix, rows);
    return 0;
}
