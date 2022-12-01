#include <iostream>

using std::cin;
using std::cout;
using std::size_t;

const size_t SIZE = 3, PLAYERS = 2;

void print(char board[][SIZE]){

    for(size_t i = 0; i < SIZE; i++){

        for(size_t j = 0; j < SIZE; j++)
            cout << board[i][j] << ' ';
        cout << '\n';

    }

}

// Забравихме само да си валидираме индексите
bool areValidIndexes(const size_t &i, const size_t &j){

    return 0 <= i && i < SIZE && 0 <= j && j < SIZE;

}

bool isValidMove(char board[][SIZE], size_t i, size_t j){

    return board[i][j] == ' ';

}

bool hasWinner(char board[][SIZE]){

    if(board[0][0] == board[0][1] && board[0][1] == board[0][2] && board[0][0] != ' ') return true;
    if(board[1][0] == board[1][1] && board[1][1] == board[1][2] && board[1][0] != ' ') return true;
    if(board[2][0] == board[2][1] && board[2][1] == board[2][2] && board[2][0] != ' ') return true;
    if(board[0][0] == board[1][0] && board[1][0] == board[2][0] && board[0][0] != ' ') return true;
    if(board[0][1] == board[1][1] && board[1][1] == board[2][1] && board[0][1] != ' ') return true;
    if(board[0][2] == board[1][2] && board[1][2] == board[2][2] && board[0][2] != ' ') return true;
    if(board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ') return true;
    if(board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ') return true;

    return false;

}

int main(){

    char board[SIZE][SIZE] = {
        {' ', ' ', ' '},
        {' ', ' ', ' '},
        {' ', ' ', ' '}
    };

    int row, col;

    const char player1 = 'o', player2 = 'x';
    bool hasFinished = false;

    for(size_t i = 0; i < 3; i++){

        if(hasFinished) break;

        for(size_t j = 0; j < 3; j++){

            do{
                cin >> row >> col;
                row--;
                col--;
            }while(!areValidIndexes(row, col) || !isValidMove(board, row, col)); // Добавяме и новата проверка тук
            board[row][col] = ((i + j) % 2 == 0) ? player1 : player2;
            print(board);
            if(hasWinner(board)){

                if((i + j) % 2 == 0) cout << "Player 1 wins!\n";
                else cout << "Player 2 wins\n";
                hasFinished = true;
                break;

            }

        }

    }

    if(!hasFinished) cout << "Tie\n";

}