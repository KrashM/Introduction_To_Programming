#include <iostream>

void SpaceElementsByOne(int arr[], size_t &size){

    size = 2 * size;
    for(size_t i = size - 2; i > 0; i -= 2)
        arr[i] = arr[i / 2];

}

void FillArray(int arr[], size_t &size){

    SpaceElementsByOne(arr, size);
    arr[1] = arr[0];
    for(size_t i = 3; i < size; i += 2)
        arr[i] = arr[i - 1] + arr[i - 2];

}

int main(){

    size_t const CAPACITY = 1024;
    int arr[CAPACITY];
    size_t size, k, index;

    std::cin >> size;
    if(size >= CAPACITY){

        std::cout << "Invalid input\n";
        return -1;

    }

    for(size_t i = 0; i < size; ++i) std::cin >> arr[i];

    FillArray(arr, size);

    std::cin >> k;

    for(size_t i = 0; i < k; ++i){

        std::cin >> index;

        if(2 * index + 1 >= size){

            std::cout << "\nInvalid input\n";
            return -1;

        }

        std::cout << arr[2 * index + 1] << ' ';

    }

    std::cout << '\n';

    return 0;

}