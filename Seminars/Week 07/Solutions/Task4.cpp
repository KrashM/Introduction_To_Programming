#include <iostream>

size_t const CAPACITY = 1024;

int FindMoundIndex(int const arr[], size_t const size){

    int start = 0, end = size - 1;

    while(start < end){

        int mid = start + (end - start) / 2;

        if(arr[mid] > arr[mid + 1]) end = mid;
        else start = mid + 1;

    }

    return start;

}

int main(){

    int arr[CAPACITY];
    size_t n;
    std::cin >> n;

    for(size_t i = 0; i < n; ++i) std::cin >> arr[i];
    std::cout << FindMoundIndex(arr, n) << '\n';

    return 0;

}