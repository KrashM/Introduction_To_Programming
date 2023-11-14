#include <iostream>

void InsertionSort(int array[], size_t const size){

    for(size_t i = 1; i < size; ++i){

        size_t j = i;
        int x = array[i];

        while(j > 0 && array[j - 1] > x){

            array[j] = array[j - 1];
            --j;

        }

        array[j] = x;

    }

}

int main(){

    size_t const SIZE = 10;
    int arr[SIZE] = { 5, 1, 6, 8, 0, 4, 3, 2, 9, 7 };

    for(size_t i = 0; i < SIZE; i++) std::cout << arr[i] << ' ';
    std::cout << '\n';

    InsertionSort(arr, SIZE);

    for(size_t i = 0; i < SIZE; i++) std::cout << arr[i] << ' ';
    std::cout << '\n';

}