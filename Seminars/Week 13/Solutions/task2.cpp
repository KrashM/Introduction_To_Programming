#include <iostream>
#include <cstddef>
#include <new>

typedef bool(*PredicatFunction)(int const);

int *Filter(int const * const array, size_t const size, size_t &newSize, PredicatFunction predicat){

    newSize = 0;
    size_t counter = 0;
    for(size_t i = 0; i < size; ++i)
        if(predicat(array[i]))
            counter++;

    int *result = new(std::nothrow) int[counter];
    if(!result) return nullptr;

    for(size_t i = 0; i < size; ++i)
        if(predicat(array[i]))
            result[newSize++] = array[i];

    return result;

}

bool IsEven(int const x){
    return !(x % 2);
}

bool IsOdd(int const x){
    return x % 2;
}

int main(){

    size_t const SIZE = 5;
    size_t newSize;
    int array[SIZE] = {1, 2, 3, 4, 5};
    int *result = Filter(array, SIZE, newSize, IsEven);

    if(!result){

        std::cout << "Memory error\n";
        return -1;

    }

    for(size_t i = 0; i < newSize; ++i)
        std::cout << result[i] << ' ';
    std::cout << '\n';

    delete[] result;

    result = Filter(array, SIZE, newSize, IsOdd);

    if(!result){

        std::cout << "Memory error\n";
        return -1;

    }

    for(size_t i = 0; i < newSize; ++i)
        std::cout << result[i] << ' ';
    std::cout << '\n';

    delete[] result;

    return 0;

}