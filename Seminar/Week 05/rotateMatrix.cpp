#include <iostream>

using std::cin;
using std::cout;

void rotate(int arr[][3], const int SIZE){

    int rotatedMatrix[SIZE][SIZE];

    for(int i = 0; i < SIZE; i++){
        for(int j = 0; j < SIZE; j++){
            rotatedMatrix[i][SIZE - j - 1] = arr[j][i];
        }
    }

    for(int i = 0; i < SIZE; i++){
        for(int j = 0; j < SIZE; j++){
            arr[i][j] = rotatedMatrix[i][j];
        }
    }

}

void print(int arr[][3], const int SIZE){

    for(int i = 0; i < SIZE; i++){
        for(int j = 0; j < SIZE; j++){
            std::cout << arr[i][j] << ' ';
        }
        std::cout << '\n';
    }

}

int main(){

    const int SIZE = 3;
    int arr[SIZE][SIZE] = {{1, 2, 3},
                           {4, 5, 6},
                           {7, 8, 9}};
    rotate(arr, SIZE);
    print(arr, SIZE);

}