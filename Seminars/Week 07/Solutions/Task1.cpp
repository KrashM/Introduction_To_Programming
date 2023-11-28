#include <iostream>

size_t const CAPACITY = 1024;

int BinarySearch(int const arr[], size_t const size, int const k){

    int start = 0, end = size - 1, mid;

    while(start <= end){

        mid = (start + end) / 2;
        if(mid == size - 1 || (arr[mid] <= k && arr[mid + 1] > k)) return arr[mid];

        if(k < arr[mid]) end = mid - 1;
        else start = mid + 1;

    }

    return INT32_MIN;

}

int main(){

    int arr[CAPACITY], k;
    size_t n;
    std::cin >> n;

    for(size_t i = 0; i < n; ++i) std::cin >> arr[i];
    std::cin >> k;

    std::cout << BinarySearch(arr, n, k) << '\n';

    return 0;

}