#include <iostream>

using std::cin;
using std::cout;
using std::swap;
using std::size_t;

void reverseRows(size_t **matrix, const size_t &n){

    for(size_t i = 0; i < n; i++)
        for(size_t j = 0, k = n - 1; j < k; j++, k--)
            swap(matrix[i][j], matrix[i][k]);

}

void transpose(size_t **matrix, const size_t &n){

    for (int i = 0; i < n; i++)
        for (int j = i; j < n; j++)
            swap(matrix[i][j], matrix[j][i]);

}

void rotate90(size_t **matrix, const size_t &n){

    transpose(matrix, n);
    reverseRows(matrix, n);

}

void print(size_t **matrix, const size_t &n){

    for(size_t i = 0; i < n; ++i){

        for(size_t j = 0; j < n; ++j)
            cout << matrix[i][j] << ' ';
        cout << '\n';

    }

}

int main(){

    size_t n;
    cin >> n;

    size_t **matrix = new size_t *[n];
    for(size_t i = 0; i < n; ++i) matrix[i] = new size_t[n];

    for(size_t i = 0; i < n; ++i)
        for(size_t j = 0; j < n; ++j)
            cin >> matrix[i][j];

    rotate90(matrix, n);
    print(matrix, n);

    for(size_t i = 0; i < n; ++i) delete[] matrix[i];
    delete[] matrix;

}