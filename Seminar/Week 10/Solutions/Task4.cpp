#include <iostream>

using std::cin;
using std::cout;
using std::size_t;

void findSum(int **A, int **B, const size_t &n, const size_t &m){

    for(size_t i = 0; i < n; ++i){

        for(size_t j = 0; j < m; ++j)
            cout << A[i][j] + B[i][j] << ' ';
        cout << '\n';

    }

}

void findDifference(int **A, int **B, const size_t &n, const size_t &m){

    for(size_t i = 0; i < n; ++i){

        for(size_t j = 0; j < m; ++j)
            cout << A[i][j] - B[i][j] << ' ';
        cout << '\n';

    }

}

int main(){

    size_t n, m;
    cin >> n >> m;

    int **A = new int *[n], **B = new int *[n];
    for(size_t i = 0; i < n; ++i){
        
        A[i] = new int[m];
        B[i] = new int[m];

    }

    for(size_t i = 0; i < n; ++i)
        for(size_t j = 0; j < m; ++j)
            cin >> A[i][j];

    for(size_t i = 0; i < n; ++i)
        for(size_t j = 0; j < m; ++j)
            cin >> B[i][j];

    cout << '\n';
    findSum(A, B, n, m);
    cout << '\n';
    findDifference(A, B, n, m);

    for(size_t i = 0; i < n; ++i){
        
        delete[] A[i];
        delete[] B[i];

    }

    delete[] A;
    delete[] B;

}