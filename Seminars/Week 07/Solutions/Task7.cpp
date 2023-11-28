#include <iostream>

size_t const CAPACITY = 1024;

int CountOfPairSumsSmallerThanK(int const arr[], size_t const size, int const k){

    int result = 0;

    for(int i = 0; i < size - 1; ++i)
        for(int j = i + 1; j < size; ++j)
            result += arr[i] + arr[j] < k;

    return result;

}

int main(){

    int arr[CAPACITY], k;
    size_t n;
    std::cin >> n >> k;

    for(size_t i = 0; i < n; ++i) std::cin >> arr[i];
    std::cout << CountOfPairSumsSmallerThanK(arr, n, k) << '\n';

    return 0;

}