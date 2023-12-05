#include <iostream>

size_t const CAPACITY = 100;

bool IsMagicSquare(int matrix[][CAPACITY], size_t const n){

    int diagonal1 = 0, diagonal2 = 0;
    for(size_t i = 0; i < n; ++i){

        diagonal1 += matrix[i][i];
        diagonal2 += matrix[i][n - i - 1];

    }

    // Двата диагонала имат различна сума
    if(diagonal1 != diagonal2) return false;

    int rowSum, colSum;
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

    std::cout << std::boolalpha << IsMagicSquare(matrix, n) << '\n';

    return 0;

}