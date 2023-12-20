#include <iostream>

size_t const CAPACITY = 1024;

void ReadArray(double arr[], size_t const n){

    for(size_t i = 0; i < n; ++i) std::cin >> arr[i];

}

void PrintArray(double const arr[], size_t const n){

    for(size_t i = 0; i < n; ++i) std::cout << arr[i] << ' ';
    std::cout << '\n';

}

bool IsSorted(double const arr[], size_t const n){

    for(size_t i = 0; i < n - 1; ++i)
        if(arr[i] > arr[i + 1]) return false;
    return true;

}

unsigned NumbersToClear(double const arr[], size_t const n){

    unsigned counter = 0;
    bool mapping[CAPACITY] = {false, };

    for(size_t i = 0; i < n - 1; ++i)
        for(size_t j = i + 1; j < n; ++j)
            if(!mapping[j])
                mapping[j] |= arr[i] > arr[j];

    for(size_t i = 0; i < n; ++i)
        counter += mapping[i];

    return counter;

}

void ClearArray(double arr[], size_t &n){

    for(size_t i = 0; i < n - 1; ++i)
        for(size_t j = i + 1; j < n; ++j)
            if(arr[i] > arr[j]){

                for(size_t k = j; k < n - 1; ++k) arr[k] = arr[k + 1];
                --n;
                --j;

            }

}

int main(){

    double arr[CAPACITY];
    size_t n;
    std::cin >> n;

    if(n > CAPACITY){

        std::cout << "Wrong input\n";
        return -1;

    }

    ReadArray(arr, n);
    PrintArray(arr, n);

    std::cout << NumbersToClear(arr, n) << '\n';

    ClearArray(arr, n);
    PrintArray(arr, n);

    return 0;

}