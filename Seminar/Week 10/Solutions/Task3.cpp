#include <iostream>

using std::cin;
using std::cout;
using std::size_t;

bool isLowerTriangle(size_t **matrix, const size_t &n){

    for(size_t i = 0; i < n - 1; ++i)
        for(size_t j = i + 1; j < n; ++j)
            if(matrix[i][j] != 0) return false;

    return true;

}

bool isUpperTriangle(size_t **matrix, const size_t &n){

    for(size_t i = 1; i < n; ++i)
        for(size_t j = 0; j < i; ++j)
            if(matrix[i][j] != 0) return false;

    return true;

}

void checkIfMatrixIsTriangle(size_t **matrix, const size_t &n){

    if(isLowerTriangle(matrix, n)){

        cout << "This is a lower triangular matrix\n";
        return;

    }

    if(isUpperTriangle(matrix, n)){

        cout << "This is an upper triangular matrix\n";
        return;

    }

    cout << "This is neither an upper, nor a lower triangular matrix\n";

}

int main(){

    size_t n;
    cin >> n;

    size_t **matrix = new size_t *[n];
    for(size_t i = 0; i < n; ++i) matrix[i] = new size_t[n];

    for(size_t i = 0; i < n; ++i)
        for(size_t j = 0; j < n; ++j)
            cin >> matrix[i][j];

    checkIfMatrixIsTriangle(matrix, n);

    for(size_t i = 0; i < n; ++i) delete[] matrix[i];
    delete[] matrix;

}