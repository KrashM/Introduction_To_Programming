#include <iostream>
#include <iomanip>

using std::cin;
using std::cout;
using std::setw;
using std::size_t;

const size_t possibleMoves = 8;
const int xMove[8] = { 2, 1, -1, -2, -2, -1, 1, 2 };
const int yMove[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };

int isSafe(int **sol, const size_t &n, const size_t &x, const size_t &y){

    return x < n && y < n && sol[x][y] == -1;

}

void printSolution(int **sol, const size_t &n){

    for(size_t i = 0; i < n; i++){

        for(size_t j = 0; j < n; j++)
            cout << setw(2) << sol[i][j] << " ";
        cout << '\n';

    }

}

bool solve(int **sol, const size_t &n, const size_t &x, const size_t &y, const unsigned int &movei){

    if(movei == n * n) return true;
    size_t next_x, next_y;

    for(size_t k = 0; k < possibleMoves; k++){

        next_x = x + xMove[k];
        next_y = y + yMove[k];

        if(isSafe(sol, n, next_x, next_y)){

            sol[next_x][next_y] = movei;
            if(solve(sol, n, next_x, next_y, movei + 1)) return true;
            sol[next_x][next_y] = -1; // Backtracking

        }

    }

    return false;

}

int main(){

    size_t n;
    cin >> n;

    int **board = new int*[n];
    for(size_t i = 0; i < n; ++i){
        
        board[i] = new int[n];
        for(size_t j = 0; j < n; ++j)
            board[i][j] = -1;

    }

    board[0][0] = 1;

    if(solve(board, n, 0, 0, 1)) printSolution(board, n);
    else cout << "Solution does not exist";

    for(size_t i = 0; i < n; ++i) delete[] board[i];
    delete[] board;

}