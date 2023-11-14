#include <iostream>

void Swap(int &a, int &b){

    int temp = a;
    a = b;
    b = temp;

}

void BubbleSort(int arr[], size_t const SIZE){

    bool swapped;

    for(size_t i = 0; i < SIZE - 1; i++){

        swapped = false;
        for(size_t j = 0; j < SIZE - i - 1; j++)
            if(arr[j] > arr[j + 1]){

                Swap(arr[j], arr[j + 1]);
                swapped = true;

            }

        // Ако не се сменят нито една двойка съседни клетки, то масивът е сортиран.
        if(!swapped) break;

    }

}

int main(){

    size_t const SIZE = 10;
    int arr[SIZE] = { 5, 1, 6, 8, 0, 4, 3, 2, 9, 7 };

    for(size_t i = 0; i < SIZE; i++) std::cout << arr[i] << ' ';
    std::cout << '\n';

    BubbleSort(arr, SIZE);

    for(size_t i = 0; i < SIZE; i++) std::cout << arr[i] << ' ';
    std::cout << '\n';

}