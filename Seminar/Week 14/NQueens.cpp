#include <iostream>

using std::min;
using std::cin;
using std::cout;

void print(bool **board, const size_t &size){

    for(size_t i = 0; i < size; ++i){

        for(size_t j = 0; j < size; ++j)
            if(board[i][j]) cout << "Q ";
            else cout << ". ";
        cout << '\n';

    }

}

bool isSafe(const size_t &row, const size_t &col, bool **board, const size_t &size){

    for(size_t i = 0; i < size; ++i)
        if(board[i][col])
            return false;

    for(size_t i = 0; i <= min(row, col); ++i)
        if(board[row - i][col - i])
            return false;

    for(size_t i = 0; i <= row && col + i < size; ++i)
        if(board[row - i][col + i])
            return false;
    
    return true;

}

bool map(bool **board, const size_t &size, const size_t &row){

    if(row == size){

        print(board, size);
        return true;

    }

    for(size_t i = 0; i < size; ++i){

        if(isSafe(row, i, board, size)){

            board[row][i] = true;
            if(map(board, size, row + 1)) return true;
            board[row][i] = false;

        }

    }

    return false;

}

int main(){

    size_t n;
    cin >> n;

    bool **board = new bool*[n];
    for(size_t i = 0; i < n; i++){

        board[i] = new bool[n];
        for(size_t j = 0; j < n; ++j)
            board[i][j] = false;

    }

    map(board, n, 0);

    for(size_t i = 0; i < n; ++i)
        delete[] board[i];
    delete[] board;

}