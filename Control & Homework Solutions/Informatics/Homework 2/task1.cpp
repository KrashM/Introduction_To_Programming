#include <iostream>

bool CanFormFrom(int const A[], int const B[], size_t const n, size_t const m){

    if(m >= n) return false;

    size_t index = 0;

    for(size_t i = 0; i < n; ++i) index += A[i] == B[index];

    return index == m;

}

int main(){

    size_t const CAPACITY = 1024;
    int A[CAPACITY], B[CAPACITY];
    size_t n, m;

    std::cin >> n >> m;

    if(n >= CAPACITY || m >= CAPACITY){

        std::cout << "Invalid input\n";
        return -1;

    }

    for(size_t i = 0; i < n; ++i) std::cin >> A[i];
    for(size_t i = 0; i < m; ++i) std::cin >> B[i];

    std::cout << std::boolalpha << CanFormFrom(A, B, n, m) << '\n';

    return 0;

}