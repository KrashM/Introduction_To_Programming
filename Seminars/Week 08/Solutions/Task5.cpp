#include <iostream>

size_t const CAPACITY = 100;

void Swap(int &a, int &b){

    int temp = a;
    a = b;
    b = temp;

}

void ReverseRows(int matrix[][CAPACITY], size_t const n){

    for(size_t i = 0; i < n; i++)
        for(size_t j = 0, k = n - 1; j < k; j++, k--)
            Swap(matrix[i][j], matrix[i][k]);

}

void Transpose(int matrix[][CAPACITY], size_t const n){

    for (int i = 0; i < n; i++)
        for (int j = i; j < n; j++)
            Swap(matrix[i][j], matrix[j][i]);

}

void Rotate90(int matrix[][CAPACITY], size_t const n){

    Transpose(matrix, n);
    ReverseRows(matrix, n);

}

void Print(int matrix[][CAPACITY], size_t const n){

    for(size_t i = 0; i < n; ++i){

        for(size_t j = 0; j < n; ++j)
            std::cout << matrix[i][j] << ' ';
        std::cout << '\n';

    }

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

    Rotate90(matrix, n);
    Print(matrix, n);

    return 0;

}