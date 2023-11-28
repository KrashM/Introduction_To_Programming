#include <iostream>

size_t const CAPACITY = 1024;

void InsertionSort(int array[], size_t const size){

    for(size_t i = 1; i < size; ++i){

        size_t j = i;
        int x = array[i];

        while(j > 0 && array[j - 1] > x){

            array[j] = array[j - 1];
            --j;

        }

        array[j] = x;

    }

}

int FindMaximizedSum(int arr[], size_t const size){

    int result = 0;

    InsertionSort(arr, size);
    for(size_t i = 0; i < size; i += 2)
        result += arr[i];
    
    return result;

}

int main(){

    int arr[CAPACITY];
    size_t n;
    std::cin >> n;

    for(size_t i = 0; i < n; ++i) std::cin >> arr[i];
    std::cout << FindMaximizedSum(arr, n) << '\n';

    return 0;

}