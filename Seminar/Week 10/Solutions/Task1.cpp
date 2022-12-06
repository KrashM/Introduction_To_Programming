#include <iostream>

using std::cin;
using std::cout;
using std::size_t;

void printInSpiral(size_t **matrix, const size_t &n, const size_t &m){

    size_t numberOfSeen = 0, directionIndex = 0, x = 0, y = 0, newX, newY;
    bool **seen = new bool *[n];
    for(size_t i = 0; i < n; ++i) seen[i] = new bool[m];

    int directionRows[] = { 0, 1, 0, -1 }, directionCols[] = { 1, 0, -1, 0 };

    while(numberOfSeen < n * m){

        cout << matrix[x][y] << ' ';
        seen[x][y] = true;

        newX = x + directionRows[directionIndex];
        newY = y + directionCols[directionIndex];

        if(0 <= newX && newX < n && 0 <= newY && newY < m && !seen[newX][newY]){

            x = newX;
            y = newY;

        }
        else{

            directionIndex = (directionIndex + 1) % 4;
            x += directionRows[directionIndex];
            y += directionCols[directionIndex];

        }

        ++numberOfSeen;

    }

    for(size_t i = 0; i < n; ++i) delete[] seen[i];
    delete[] seen;

}

int main(){

    size_t n, m;
    cin >> n >> m;

    size_t **matrix = new size_t *[n];
    for(size_t i = 0; i < n; ++i) matrix[i] = new size_t[m];

    for(size_t i = 0; i < n; ++i)
        for(size_t j = 0; j < m; ++j)
            cin >> matrix[i][j];

    printInSpiral(matrix, n, m);

    for(size_t i = 0; i < n; ++i) delete[] matrix[i];
    delete[] matrix;

}

/*
3 3
1 2 3
4 5 6
7 8 9

4 5
 1  2  3  4  5
 6  7  8  9 10
11 12 13 14 15
16 17 18 19 20

4 3
 1  2  3
 4  5  6
 7  8  9
10 11 12
*/