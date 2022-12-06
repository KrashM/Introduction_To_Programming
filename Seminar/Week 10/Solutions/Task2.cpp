#include <iostream>

using std::cin;
using std::cout;
using std::size_t;
using std::boolalpha;

bool isMagicSquare(size_t **matrix, const size_t &n){

    size_t diagonal1 = 0, diagonal2 = 0;
    for(size_t i = 0; i < n; ++i){

        diagonal1 += matrix[i][i];
        diagonal2 += matrix[i][n - i - 1];

    }

    // Двата диагонала имат различна сума
    if(diagonal1 != diagonal2) return false;

    size_t rowSum, colSum;
    for(size_t i = 0; i < n; ++i){

        rowSum = colSum = 0;
        for(size_t j = 0; j < n; ++j){

            rowSum += matrix[i][j];
            colSum += matrix[j][i];

        }

        // Или сумата на ред и колона е различна или на колоната с диагонала
        if(rowSum != colSum || colSum != diagonal1) return false;

    }

    return true;

}

int main(){

    size_t n;
    cin >> n;

    size_t **matrix = new size_t *[n];
    for(size_t i = 0; i < n; ++i) matrix[i] = new size_t[n];

    for(size_t i = 0; i < n; ++i)
        for(size_t j = 0; j < n; ++j)
            cin >> matrix[i][j];

    cout << boolalpha << isMagicSquare(matrix, n) << '\n';

    for(size_t i = 0; i < n; ++i) delete[] matrix[i];
    delete[] matrix;

}