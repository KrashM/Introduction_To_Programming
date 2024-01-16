#include <iostream>
#include <cstddef>
#include <new>

void ReduceArray(int * const array, size_t &n){

    if(n == 1) return;
    for(size_t i = 0; i < n - 1; ++i)
        array[i] += array[i + 1];
    ReduceArray(array, --n);

}

int main(){

    size_t n;
    std::cin >> n;

    int *array = new(std::nothrow) int[n];

    if(!array){

        std::cout << "Memory error\n";
        return -1;

    }

    for(size_t i = 0; i < n; ++i) std::cin >> array[i];

    ReduceArray(array, n);
    std::cout << array[0] << '\n';

    delete[] array;

    return 0;

}