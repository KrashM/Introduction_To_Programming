#include <iostream>

void Swap(int &a, int &b){

    int temp = a;
    a = b;
    b = temp;

}

void Sort(int arr[], size_t const size){

    size_t min_index;

    for(size_t i = 0; i < size - 1; i++){

        min_index = i;

        for(size_t j = i + 1; j < size; j++)
            if(arr[min_index] > arr[j])
                min_index = j;

        if(min_index != i) Swap(arr[i], arr[min_index]);

    }

}

int GetKthElementInArray(int arr[], size_t const size, size_t const k){

    Sort(arr, size);
    return arr[k - 1];

}

int main(){

    size_t const CAPACITY = 1024;
    int arr[CAPACITY];
    size_t size, k;

    std::cin >> size;
    if(size >= CAPACITY){

        std::cout << "Invalid input\n";
        return -1;

    }

    for(size_t i = 0; i < size; ++i) std::cin >> arr[i];

    std::cin >> k;
    if(k >= size){

        std::cout << "Invalid input\n";
        return -1;

    }

    std::cout << GetKthElementInArray(arr, size, k) << '\n';

    return 0;

}