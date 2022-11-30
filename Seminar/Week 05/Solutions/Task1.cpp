#include <iostream>

int findMin(int arr[], const unsigned int size){

    int min = arr[0];

    for(unsigned int i = 0; i < size; i++)
        if(arr[i] < min) min = arr[i];

    return min;

}

int main(){

    const unsigned int SIZE = 4; 
    int arr[4] = {12, 5, 23, 9};

    std::cout << findMin(arr, SIZE) << '\n';

}