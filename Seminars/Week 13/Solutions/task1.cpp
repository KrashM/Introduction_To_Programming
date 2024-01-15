#include <iostream>

typedef int(*OperationType)(int const);

int AddOne(int const x){
    return x + 1;
}

int Double(int const x){
    return 2 * x;
}

void Map(int * const array, size_t const size, OperationType operation){

    if(!size) return;

    array[size - 1] = operation(array[size - 1]);
    Map(array, size - 1, operation);

    // Алтернативен вариант
    // *array = operation(*array);
    // Map(array + 1, size - 1, operation);

}

int main(){

    size_t const SIZE = 5;
    int array[SIZE] = {1, 2, 3, 4, 5};

    Map(array, SIZE, AddOne);

    for(size_t i = 0; i < SIZE; ++i)
        std::cout << array[i] << ' ';
    std::cout << '\n';

    Map(array, SIZE, Double);

    for(size_t i = 0; i < SIZE; ++i)
        std::cout << array[i] << ' ';
    std::cout << '\n';

    return 0;

}