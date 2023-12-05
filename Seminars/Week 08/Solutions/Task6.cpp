#include <iostream>

size_t const CAPACITY = 100;

void Swap(int &a, int &b){

    int temp = a;
    a = b;
    b = temp;

}

int CalculateDeterminant(int matrix[][CAPACITY], size_t const n){

    int temp, det = 1, index, total = 1;

    for(size_t i = 0; i < n; ++i){

        index = i;

        while(index < n && !matrix[index][i]) ++index;

        if(index == n) continue;

        if(index != i){

            for(size_t j = 0; j < n; ++j)
                Swap(matrix[index][j], matrix[i][j]);
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

    return det / total;

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

    std::cout << CalculateDeterminant(matrix, n) << '\n';

    return 0;

}