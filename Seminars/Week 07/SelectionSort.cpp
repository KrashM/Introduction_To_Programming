#include <iostream>

void Swap(int &a, int &b){

    int temp = a;
    a = b;
    b = temp;

}

void SelectionSort(int arr[], size_t const SIZE){

    size_t min_index;

    for(size_t i = 0; i < SIZE - 1; i++){

        min_index = i;

        for(size_t j = i + 1; j < SIZE; j++)
            if(arr[min_index] > arr[j])
                min_index = j;

        if(min_index != i) Swap(arr[i], arr[min_index]);

    }

}

int main(){

    size_t const SIZE = 10;
    int arr[SIZE] = { 5, 1, 6, 8, 0, 4, 3, 2, 9, 7 };

    for(size_t i = 0; i < SIZE; i++) std::cout << arr[i] << ' ';
    std::cout << '\n';

    SelectionSort(arr, SIZE);

    for(size_t i = 0; i < SIZE; i++) std::cout << arr[i] << ' ';
    std::cout << '\n';

}