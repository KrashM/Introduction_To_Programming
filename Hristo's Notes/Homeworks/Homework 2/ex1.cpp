#include <iostream>

using std::cin;
using std::cout;

void resizeArray(int* &array, int size, int new_size){

    int *resize = new int[new_size];
    for(int i = 0; i < new_size; i++)
        resize[i] = array[i];
    delete[] array;
    array = resize;

}

void transformMatrix(int **A, int **B, int n1, int m1, int n2, int m2){

    int n = (n2 < n1) ? n2 : n1, m = (m2 < m1) ? m2 : m1;

    // Resizing
    if(n1 > n)
        for(int i = n1 - 1; i >= n; i--)
            delete[] A[i];

    if(m1 > m)
        for(int i = 0; i < n; i++)
            resizeArray(A[i], m1, m);
    // End of resizing

    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++){

            if(A[i][j] < B[i][j]) A[i][j] = B[i][j];
            if(A[i][j] > B[i][j]) A[i][j] *= -1;

        }

    cout << "New A is:\n";
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++)
            cout << A[i][j] << ' ';
        cout << '\n';
    }

}

int main(){

    int n1, m1, n2, m2;
    cin >> n1 >> m1 >> n2 >> m2;

    int **A = new int*[n1], **B = new int*[n2];

    cout << "A:\n";
    for(int i = 0; i < n1; i++){

        A[i] = new int[m1];
        for(int j = 0; j < m1; j++)
            cin >> A[i][j];
    
    }
    
    cout << "B:\n";
    for(int i = 0; i < n2; i++){

        B[i] = new int[m2];
        for(int j = 0; j < m2; j++)
            cin >> B[i][j];

    }

    cout << '\n';

    transformMatrix(A, B, n1, m1, n2, m2);

    for(int i = 0; i < ((n2 < n1) ? n2 : n1); i++)
        delete[] A[i];
    delete[] A;

    for(int i = 0; i < n2; i++)
        delete[] B[i];
    delete[] B;

}

/*
// No resizing
3 4 3 5

1 2 3 -4
10 19 2 0
-5 0 2 1

1 -3 8 10 34
4 7 13 2 9
3 0 -4 5 2

// Resize by rows
3 4 2 5

1 2 3 -4
10 19 2 0
-5 0 2 1

1 -3 8 10 34
4 7 13 2 9

// Resizing by columns
3 4 3 3

1 2 3 -4
10 19 2 0
-5 0 2 1

1 -3 8
4 7 13
3 0 -4

// Resizing by rows and columns
3 4 2 3

1 2 3 -4
10 19 2 0
-5 0 2 1

1 -3 8 
4 7 13
*/