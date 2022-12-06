#include <iostream>

using std::cin;
using std::cout;
using std::swap;
using std::size_t;

size_t calculateDeterminant(size_t **matrix, const size_t &n){

    int temp, det = 1, index, total = 1;

    for(size_t i = 0; i < n; ++i){

        index = i;

        while(index < n && !matrix[index][i]) ++index;

        if(index == n) continue;

        if(index != i){

            for(int j = 0; j < n; ++j)
                swap(matrix[index][j], matrix[i][j]);
            det *= (index - i) % 2 ? -1 : 1;

        }

        for(size_t j = i + 1; j < n; ++j){

            temp = matrix[j][i];

            for(size_t k = 0; k < n; ++k)
                matrix[j][k] = (matrix[i][i] * matrix[j][k]) - (temp * matrix[i][k]);

            total *= matrix[i][i];

        }

    }

    for(size_t i = 0; i < n; ++i) det *= matrix[i][i];
    return (det / total);

}

int main(){

    size_t n;
    cin >> n;

    size_t **matrix = new size_t *[n];
    for(size_t i = 0; i < n; ++i) matrix[i] = new size_t[n];

    for(size_t i = 0; i < n; ++i)
        for(size_t j = 0; j < n; ++j)
            cin >> matrix[i][j];

    cout << calculateDeterminant(matrix, n) << '\n';

    for(size_t i = 0; i < n; ++i) delete[] matrix[i];
    delete[] matrix;

}