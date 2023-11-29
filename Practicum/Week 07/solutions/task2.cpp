#include <iostream>

double const EPSILON = 0.001;

bool BinarySearch(double const arr[], size_t const size, double const toBeSearched){

    int start = 0, end = size - 1, mid;

    while(start <= end){

        mid = (start + end) / 2;

        if(std::abs(arr[mid] - toBeSearched) < EPSILON) return true;

        if(toBeSearched < arr[mid]) end = mid - 1;
        else start = mid + 1;

    }

    return false;

}

int main(){

    size_t const CAPACITY = 1024;
    double arr[CAPACITY], k;
    size_t size;

    std::cin >> size;
    if(size >= CAPACITY){

        std::cout << "Invalid input\n";
        return -1;

    }

    for(size_t i = 0; i < size; ++i) std::cin >> arr[i];
    std::cin >> k;

    std::cout << std::boolalpha << BinarySearch(arr, size, k) << '\n';

    return 0;

}