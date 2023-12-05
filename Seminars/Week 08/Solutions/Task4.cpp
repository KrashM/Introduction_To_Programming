#include <iostream>

size_t const CAPACITY = 100;

void FindSum(int A[][CAPACITY], int B[][CAPACITY], size_t const n, size_t const m){

    for(size_t i = 0; i < n; ++i){

        for(size_t j = 0; j < m; ++j)
            std::cout << A[i][j] + B[i][j] << ' ';
        std::cout << '\n';

    }

}

void FindDifference(int A[][CAPACITY], int B[][CAPACITY], size_t const n, size_t const m){

    for(size_t i = 0; i < n; ++i){

        for(size_t j = 0; j < m; ++j)
            std::cout << A[i][j] - B[i][j] << ' ';
        std::cout << '\n';

    }

}

int main(){

    int A[CAPACITY][CAPACITY], B[CAPACITY][CAPACITY];
    size_t n, m;
    std::cin >> n >> m;

    if(n >= CAPACITY || m >= CAPACITY){

        std::cout << "Invalid input\n";
        return -1;

    }

    for(size_t i = 0; i < n; ++i)
        for(size_t j = 0; j < m; ++j)
            std::cin >> A[i][j];

    for(size_t i = 0; i < n; ++i)
        for(size_t j = 0; j < m; ++j)
            std::cin >> B[i][j];

    std::cout << '\n';
    FindSum(A, B, n, m);
    std::cout << '\n';
    FindDifference(A, B, n, m);

    return 0;

}