#include <iostream>

void pushZerosToEnd(int arr[], const int size){

    int count = 0;
 
    for(int i = 0; i < size; i++)
        if(arr[i] != 0)
            arr[count++] = arr[i];

    while(count < size) arr[count++] = 0;

}

void modifyAndRearrangeArr(int arr[], const int size){

    if(size == 1) return;
 
    for(int i = 0; i < size - 1; i++)
        if(arr[i] && arr[i] == arr[i + 1]){

            arr[i] = 2 * arr[i];
            arr[++i] = 0;

        }

    pushZerosToEnd(arr, size);

}

void printArray(int arr[], const int size){

    for(int i = 0; i < size; i++)
        std::cout << arr[i] << " ";
    std::cout << '\n';

}

int main(){

    int arr[] = { 0, 2, 2, 2, 0, 6, 6, 0, 0, 8 };
    const int size = sizeof(arr) / sizeof(arr[0]);

    std::cout << "Original array: ";
    printArray(arr, size);

    modifyAndRearrangeArr(arr, size);

    std::cout << "Modified array: ";
    printArray(arr, size);

}