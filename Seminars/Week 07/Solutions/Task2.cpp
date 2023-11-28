#include <iostream>

size_t const CAPACITY = 1024;

int FindMissingElement(int const arr[], size_t const size){

    int total_sum = (size * (size + 1)) / 2;
    for(size_t i = 0; i < size; ++i) total_sum -= arr[i];
    return total_sum;

}

int main(){

    int arr[CAPACITY];
    size_t n;
    std::cin >> n;

    for(size_t i = 0; i < n; ++i) std::cin >> arr[i];
    std::cout << FindMissingElement(arr, n) << '\n';

    return 0;

}