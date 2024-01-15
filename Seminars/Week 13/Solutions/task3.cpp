#include <iostream>
#include <cstddef>

typedef bool(*PredicateFunction)(int const, int const);

void Sort(int * const arr, size_t const size, PredicateFunction predicate){

    for(size_t i = 0; i < size - 1; i++){
        size_t min_index = i;
        for(size_t j = i + 1; j < size; j++){
            if(predicate(arr[min_index], arr[j])){
                min_index = j;
            }
        }
        if(min_index != i){
            std::swap(arr[i], arr[min_index]);
        }
    }

}

bool EvenBeforeOdd(int const a, int const b){
    return a % 2 && !(b % 2);
}

bool Ascending(int const a, int const b){
    return a > b;
}

bool Descending(int const a, int const b){
    return a < b;
}

int main(){

    size_t const SIZE = 10;
    int arr[SIZE] = { 5, 1, 6, 8, 0, 4, 3, 2, 9, 7 };

    Sort(arr, SIZE, EvenBeforeOdd);

    for(size_t i = 0; i < SIZE; ++i)
        std::cout << arr[i] << ' ';
    std::cout << '\n';

    Sort(arr, SIZE, Ascending);

    for(size_t i = 0; i < SIZE; ++i)
        std::cout << arr[i] << ' ';
    std::cout << '\n';

    Sort(arr, SIZE, Descending);

    for(size_t i = 0; i < SIZE; ++i)
        std::cout << arr[i] << ' ';
    std::cout << '\n';

    return 0;

}