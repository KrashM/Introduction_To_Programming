#include <iostream>

bool BinarySeach(int const arr[], size_t const SIZE, int const toBeSearched){

    int start = 0, end = SIZE - 1, mid;

    while(start <= end){

        mid = (start + end) / 2;

        // Възможно е тук да връщаме и индекса mid,
        // ако задачата го изисква.
        if(arr[mid] == toBeSearched) return true;

        if(toBeSearched < arr[mid]) end = mid - 1;
        else start = mid + 1;

    }

    return false;

}

int main(){

    size_t const SIZE = 10;
    int arr[SIZE] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };

    std::cout << std::boolalpha << BinarySeach(arr, SIZE, 2) << '\n';
    std::cout << std::boolalpha << BinarySeach(arr, SIZE, 7) << '\n';
    std::cout << std::boolalpha << BinarySeach(arr, SIZE, 10) << '\n';

}