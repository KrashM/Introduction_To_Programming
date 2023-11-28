#include <iostream>

size_t const CAPACITY = 1024;

void Swap(int &a, int &b){

    int temp = a;
    a = b;
    b = temp;

}

void SelectionSort(int arr[], size_t const size){

    for(size_t i = 0; i < size - 1; i++)
        for(size_t j = i + 1; j < size; j++)
            if(arr[i] > arr[j])
                Swap(arr[i], arr[j]);

}

void FindElementIndexes(int arr[], size_t const size, int const k){

    SelectionSort(arr, size);
    for(size_t i = 0; i < size; ++i)
        if(arr[i] == k)
            std::cout << i << ' ';

}

int main(){

    int arr[CAPACITY], k;
    size_t n;
    std::cin >> n;

    for(size_t i = 0; i < n; ++i) std::cin >> arr[i];
    std::cin >> k;

    FindElementIndexes(arr, n, k);

    return 0;

}