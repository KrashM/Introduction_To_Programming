#include <iostream>

size_t const CAPACITY = 1024;

int FindDuplicateElement(int arr[], size_t const size){

    for(size_t i = 0; i < size; ++i){

        int temp = std::abs(arr[i]);
        arr[temp - 1] = -arr[temp - 1];
        if(arr[temp - 1] > 0) return temp;

    }

    return -1; 

}

int main(){

    int arr[CAPACITY];
    size_t n;
    std::cin >> n;

    for(size_t i = 0; i < n; ++i) std::cin >> arr[i];
    std::cout << FindDuplicateElement(arr, n) << '\n';

    return 0;

}