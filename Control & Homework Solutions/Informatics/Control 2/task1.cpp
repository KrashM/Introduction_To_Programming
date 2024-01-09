#include <iostream>
#include <cstddef>
#include <new>

typedef int const * const * const int_const_matrix;
typedef int * const * const int_matrix;

bool HasRepeatingDigits(int const x){

    size_t const NUMBER_OF_DIGITS = 10;
    unsigned histogram[NUMBER_OF_DIGITS] = {0, };
    unsigned powerOfTen = 1;

    while(x >= powerOfTen){

        ++histogram[x / powerOfTen % 10];
        powerOfTen *= 10;

    }

    for(size_t i = 0; i < NUMBER_OF_DIGITS; ++i)
        if(histogram[i] > 1) return true;
    return false;

}

int *FilterNumbersWithReapeatingDigits(int_const_matrix matrix, size_t const rows, size_t const cols, size_t &size){

    size = 0;

    for(size_t i = 0; i < rows; ++i)
        for(size_t j = 0; j < cols; ++j)
            if(HasRepeatingDigits(matrix[i][j]))
                ++size;

    int *result = new(std::nothrow) int[size];

    if(!result) return nullptr;

    for(size_t i = 0, index = 0; i < rows; ++i)
        for(size_t j = 0; j < cols; ++j)
            if(HasRepeatingDigits(matrix[i][j]))
                result[index++] = matrix[i][j];

    return result;

}

void DeallocateMatrix(int_const_matrix matrix, size_t const rows){

    for(size_t i = 0; i < rows; ++i)
        delete[] matrix[i];
    delete[] matrix;

}

int **AllocateMatrix(size_t const rows, size_t const cols){

    int **matrix = new(std::nothrow) int *[rows];

    if(!matrix) return nullptr;

    for(size_t i = 0; i < rows; ++i){

        matrix[i] = new(std::nothrow) int[cols];

        if(!matrix[i]){

            DeallocateMatrix(matrix, i);
            return nullptr;

        }

    }

    return matrix;

}

void InsertMatrix(int_matrix matrix, size_t const rows, size_t const cols){

    for(size_t i = 0; i < rows; ++i)
        for(size_t j = 0; j < cols; ++j)
            std::cin >> matrix[i][j];

}

int main(){

    size_t rows, cols, size;
    std::cin >> rows >> cols;

    int **matrix = AllocateMatrix(rows, cols);

    if(!matrix){

        std::cout << "Memory error\n";
        return -1;

    }

    InsertMatrix((int_matrix)matrix, rows, cols);

    int *result = FilterNumbersWithReapeatingDigits((int_const_matrix)matrix, rows, cols, size);

    if(!result){

        std::cout << "Memory error\n";
        return -1;

    }

    for(size_t i = 0; i < size; ++i)
        std::cout << result[i] << ' ';
    std::cout << '\n';

    DeallocateMatrix((int_const_matrix)matrix, rows);
    delete[] result;

    return 0;

}

/*
3 3
1076  1356  1918
6252  6766  5525
5524  3176  1716
*/