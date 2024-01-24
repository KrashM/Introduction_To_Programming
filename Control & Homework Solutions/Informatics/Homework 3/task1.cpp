#include <iostream>
#include <cstddef>
#include <new>

void FreeMemory(int const * const * const matrix, size_t const size){

    for(size_t i = 0; i < size; ++i)
        delete[] matrix[i];
    delete[] matrix;

}

int **input(size_t &N, size_t &M){

    std::cin >> N >> M;

    int **matrix = new(std::nothrow) int *[N];
    if(!matrix) return nullptr;

    for(size_t i = 0; i < N; ++i){

        matrix[i] = new(std::nothrow) int[M];
        if(!matrix[i]){

            FreeMemory(matrix, i);
            return nullptr;

        }

    }

    for(size_t i = 0; i < N; ++i)
        for(size_t j = 0; j < M; ++j)
            std::cin >> matrix[i][j];

    return matrix;

}

unsigned GetNumberOfDivisors(int const n){

    unsigned counter = 0, k;

    for(k = 1; k * k < n; ++k)
        counter += 2 * !(n % k);
    counter += !(n % k);

    return counter;

}

void transform(int **matrix, size_t const N, size_t const M){

    unsigned D;
    std::cin >> D;

    for(size_t i = 0; i < N; ++i)
        for(size_t j = 0; j < M; ++j)
            if(GetNumberOfDivisors(matrix[i][j]) == D)
                matrix[i][j] = 0;

}

void RemoveEmtpyRows(int * * const matrix, size_t &N, size_t const M){

    for(size_t i = 0; i < N; ++i){

        bool hasNonZeroElement = false;

        for(size_t j = 0; j < M; ++j)
            if(matrix[i][j]){

                hasNonZeroElement = true;
                break;

            }

        if(!hasNonZeroElement){

            delete[] matrix[i--];
            --N;

            for(size_t j = i + 1; j < N - 1; ++j)
                matrix[j] = matrix[j + 1];

        }

    }

}

void RemoveEmtpyCols(int * const * const matrix, size_t const N, size_t &M){

    for(size_t i = 0; i < M; ++i){

        bool hasNonZeroElement = false;

        for(size_t j = 0; j < N; ++j)
            if(matrix[i][j]){

                hasNonZeroElement = true;
                break;

            }

        if(!hasNonZeroElement){

            for(size_t j = 0; j < N; ++j)
                for(size_t k = i; k < M - 1; ++k)
                    matrix[j][k] = matrix[j][k + 1];

            --M;
            --i;

        }

    }

}

void clear(int * * const matrix, size_t &N, size_t &M){

    RemoveEmtpyRows(matrix, N, M);
    RemoveEmtpyCols(matrix, N, M);

}

void print(int const * const * const matrix, size_t const N, size_t const M){

    for(size_t i = 0; i < N; ++i){

        for(size_t j = 0; j < M; ++j)
            std::cout << matrix[i][j] << ' ';
        std::cout << '\n';

    }

}

int main(){

    size_t N, M;

    int **matrix = input(N, M);
    if(!matrix){

        std::cout << "Memory error\n";
        return -1;

    }

    std::cout << '\n';
    print(matrix, N, M);
    std::cout << '\n';
    transform(matrix, N, M);
    print(matrix, N, M);
    std::cout << '\n';
    clear(matrix, N, M);
    print(matrix, N, M);
    std::cout << '\n';

    FreeMemory(matrix, N);
    return 0;

}