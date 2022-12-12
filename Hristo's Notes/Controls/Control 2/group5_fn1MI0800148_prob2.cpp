#include <iostream>

using std::cin;
using std::cout;

void shrink(int* &result, int n){

    int *shrunk = new int[n + 1];
    for(int i = 0; i < n; i++) shrunk[i] = result[i];
    shrunk[n] = -1;
    delete[] result;
    result = shrunk;

}

bool isValid(int number){

    while(number != 0){

        int powOfTen = 1, lastDigit = number % 10;
        number /= 10;
        while(powOfTen <= number){

            if(lastDigit == (number / powOfTen) % 10) return true;
            powOfTen *= 10;

        }

    }

    return false;

}

int* collect(int **matrix, int n){

    int *result = new int[1], index = 0;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < i + 1; j++){

            if(isValid(matrix[n - 1 - i + j][j])){
                
                result[index] = matrix[n - 1 - i + j][j];
                index++;

            }

        }

    for(int j = 1; j < n; j++)
        for(int i = 0; i < n - j; i++){

            if(isValid(matrix[i][i + j])){
                
                result[index] = matrix[j][i + j];
                index++;

            }

        }

    
    shrink(result, index);
    return result;

}

void input(){

    int n;
    cout << "Insert n: ";
    cin >> n;

    int **matrix = new int*[n];

    for(int i = 0; i < n; i++){

        matrix[i] = new int[n];
        for(int j = 0; j < n; j++) cin >> matrix[i][j];

    }

    int *result = collect(matrix, n);
    for(int i = 0; result[i] != -1; i++)
        if(i == 0) cout << result[i];
        else cout << ' ' << result[i]; 

}

int main(){

    input();

}
/*
3
1076
1356
1918
6252
6766
5525
5524
3176
1716
*/