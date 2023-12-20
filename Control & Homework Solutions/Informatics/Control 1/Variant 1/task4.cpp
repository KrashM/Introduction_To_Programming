#include <iostream>

size_t const CAPACITY = 1024;

void ReadArray(int arr[], size_t const n){

    for(size_t i = 0; i < n; ++i) std::cin >> arr[i];

}

void PrintArray(int const arr[], size_t const n){

    for(size_t i = 0; i < n; ++i) std::cout << arr[i] << ' ';
    std::cout << '\n';

}

bool IsSortedAscending(int const arr[], size_t const n){

    for(size_t i = 0; i < n - 1; ++i)
        if(arr[i] > arr[i + 1]) return false;
    return true;

}

bool IsSortedDescending(int const arr[], size_t const n){

    for(size_t i = 0; i < n - 1; ++i)
        if(arr[i] < arr[i + 1]) return false;
    return true;

}

bool IsSorted(int const arr[], size_t const n){
    return IsSortedAscending(arr, n) || IsSortedDescending(arr, n);
}

unsigned CountEvenSetBits(int const number){

    unsigned count = 0;
    for(unsigned i = 0; i < sizeof(number) * 8; i += 2)
        count += !!(number & 1 << i);
    return count;

}

unsigned CountEvenEvenNumbers(int const arr[], size_t const n){

    unsigned counter = 0;

    for(size_t i = 0; i < n; ++i)
        counter += CountEvenSetBits(arr[i]) % 2 == 0;

    return counter;

}

void ClearArray(int arr[], size_t &n){

    for(size_t i = 0; i < n; ++i)
        if(CountEvenSetBits(arr[i]) % 2 == 0){

            for(size_t j = i; j < n - 1; ++j) arr[j] = arr[j + 1];
            --n;
            --i;

        }

}

int main(){

    int arr[CAPACITY];
    size_t n;
    std::cin >> n;

    if(n > CAPACITY){

        std::cout << "Wrong input\n";
        return -1;

    }

    ReadArray(arr, n);
    PrintArray(arr, n);

    std::cout << CountEvenEvenNumbers(arr, n) << '\n';

    ClearArray(arr, n);
    PrintArray(arr, n);

    return 0;

}