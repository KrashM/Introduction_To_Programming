#include <iostream>

void swap(int &a, int &b){

    int temp = a;
    a = b;
    b = temp;

}

void bubbleSort(int arr[], const int SIZE){

    for(int i = 0; i < SIZE - 1; i++)
        for(int j = i + 1; j < SIZE; j++)
            if(arr[i] > arr[j])
                swap(arr[i], arr[j]);

}

int main(){

    const int SIZE = 10;
    int arr[SIZE] = { 5, 1, 6, 8, 0, 4, 3, 2, 9, 7 };

    for(int i = 0; i < SIZE; i++) std::cout << arr[i] << ' ';
    std::cout << '\n';

    bubbleSort(arr, SIZE);

    for(int i = 0; i < SIZE; i++) std::cout << arr[i] << ' ';
    std::cout << '\n';

}