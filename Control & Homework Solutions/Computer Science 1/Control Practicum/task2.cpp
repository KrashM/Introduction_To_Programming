#include <iostream>

size_t const CAPACITY = 10;

bool IsValidMove(unsigned const size, unsigned const x, unsigned const y){
    return x < size && y < size;
}

void FillMatrix(unsigned matrix[][CAPACITY], unsigned const size, unsigned const x, unsigned const y, unsigned number = 0){

    if(!IsValidMove(size, x, y) || matrix[y][x]) return;

    matrix[y][x] = number;

    FillMatrix(matrix, size, x + 1, y, number ^ (1 << (x)));
    FillMatrix(matrix, size, x, y + 1, number ^ (1 << (size + y - 1)));
    FillMatrix(matrix, size, x - 1, y, number ^ (1 << (x - 1)));
    FillMatrix(matrix, size, x, y - 1, number ^ (1 << (size + y - 2)));

}

void PrintMatrix(unsigned const matrix[][CAPACITY], unsigned const size){
    
    for(unsigned i = 0; i < size; ++i){

        for(unsigned j = 0; j < size; ++j)
            std::cout << matrix[i][j] << ' ';
        std::cout << '\n';

    }

}

int main(){

    unsigned matrix[CAPACITY][CAPACITY] = {0, }, n, startX, startY;

    std::cin >> n >> startX >> startY;

    if(n >= CAPACITY || startX >= n || startY >= n){

        std::cout << "Invalid input\n";
        return -1;

    }

    FillMatrix(matrix, n, startX, startY);
    PrintMatrix(matrix, n);

    return 0;

}