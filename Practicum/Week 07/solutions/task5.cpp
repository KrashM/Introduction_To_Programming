#include <iostream>

bool BinarySearch(int const arr[], size_t start, size_t end, int const toBeSearched){

    int mid;

    while(start <= end){

        mid = (start + end) / 2;

        if(arr[mid] == toBeSearched) return true;

        if(toBeSearched < arr[mid]) end = mid - 1;
        else start = mid + 1;

    }

    return false;

}

void TwoSum(int const arr[], size_t const size, int const sum){

    for(size_t i = 0; i < size; ++i)
        if(BinarySearch(arr, i + 1, size - 1, sum - arr[i]))
            std::cout << arr[i] << ' ' << sum - arr[i] << '\n';

}

int main(){

    size_t const CAPACITY = 1024;
    int arr[CAPACITY], sum;
    size_t size;

    std::cin >> size;
    if(size >= CAPACITY){

        std::cout << "Invalid input\n";
        return -1;

    }

    for(size_t i = 0; i < size; ++i) std::cin >> arr[i];
    std::cin >> sum;

    TwoSum(arr, size, sum);

    return 0;

}