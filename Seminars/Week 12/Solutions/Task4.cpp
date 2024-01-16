#include <iostream>
#include <iomanip>
#include <cstddef>
#include <new>

size_t const POSSIBLE_MOVES = 8;
int const X_MOVES[POSSIBLE_MOVES] = { 2, 1, -1, -2, -2, -1, 1, 2 };
int const Y_MOVES[POSSIBLE_MOVES] = { 1, 2, 2, 1, -1, -2, -2, -1 };

int isSafe(int const * const * const sol, size_t const n, size_t const x, size_t const y){
    return x < n && y < n && sol[x][y] == -1;
}

void printSolution(int const * const * const sol, size_t const n){

    for(size_t i = 0; i < n; i++){

        for(size_t j = 0; j < n; j++)
            std::cout << std::setw(2) << sol[i][j] << ' ';
        std::cout << '\n';

    }

}

bool solve(int * const * const sol, size_t const n, size_t const x, size_t const y, unsigned const movei){

    if(movei == n * n) return true;
    size_t next_x, next_y;

    for(size_t k = 0; k < POSSIBLE_MOVES; k++){

        next_x = x + X_MOVES[k];
        next_y = y + Y_MOVES[k];

        if(isSafe(sol, n, next_x, next_y)){

            sol[next_x][next_y] = movei;
            if(solve(sol, n, next_x, next_y, movei + 1)) return true;
            sol[next_x][next_y] = -1; // Backtracking

        }

    }

    return false;

}

void FreeMatrix(int const * const * const matrix, size_t const rows){

    for(size_t i = 0; i < rows; ++i)
        delete[] matrix[i];
    delete[] matrix;

}

int main(){

    size_t n;
    std::cin >> n;

    int **board = new(std::nothrow) int *[n];

    if(!board){

        std::cout << "Memory error\n";
        return -1;

    }

    for(size_t i = 0; i < n; ++i){
        
        board[i] = new(std::nothrow) int[n];

        if(!board[i]){

            std::cout << "Memory error\n";
            FreeMatrix(board, i);
            return -1;

        }

    }

    for(size_t i = 0; i < n; ++i)
        for(size_t j = 0; j < n; ++j)
            board[i][j] = -1;

    board[0][0] = 1;

    if(solve(board, n, 0, 0, 1)) printSolution(board, n);
    else std::cout << "Solution does not exist\n";

    FreeMatrix(board, n);

    return 0;

}