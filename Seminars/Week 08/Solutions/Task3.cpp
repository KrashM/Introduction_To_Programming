#include <iostream>

size_t const CAPACITY = 100;

bool IsLowerTriangle(int matrix[][CAPACITY], size_t const n){

    for(size_t i = 0; i < n - 1; ++i)
        for(size_t j = i + 1; j < n; ++j)
            if(matrix[i][j] != 0) return false;

    return true;

}

bool IsUpperTriangle(int matrix[][CAPACITY], size_t const n){

    for(size_t i = 1; i < n; ++i)
        for(size_t j = 0; j < i; ++j)
            if(matrix[i][j] != 0) return false;

    return true;

}

void CheckIfMatrixIsTriangle(int matrix[][CAPACITY], size_t const n){

    if(IsLowerTriangle(matrix, n)){

        std::cout << "This is a lower triangular matrix\n";
        return;

    }

    if(IsUpperTriangle(matrix, n)){

        std::cout << "This is an upper triangular matrix\n";
        return;

    }

    std::cout << "This is neither an upper, nor a lower triangular matrix\n";

}

int main(){

    int matrix[CAPACITY][CAPACITY];
    size_t n;
    std::cin >> n;

    if(n >= CAPACITY){

        std::cout << "Invalid input\n";
        return -1;

    }

    for(size_t i = 0; i < n; ++i)
        for(size_t j = 0; j < n; ++j)
            std::cin >> matrix[i][j];

    CheckIfMatrixIsTriangle(matrix, n);

    return 0;

}