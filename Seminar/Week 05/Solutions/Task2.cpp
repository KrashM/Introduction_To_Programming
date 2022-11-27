#include <iostream>

int findSum(int arr[], const unsigned int SIZE){

    int sum = 0;

    for(unsigned int i = 0; i < SIZE; i++)
        sum += arr[i];

    return sum;

}

int main(){

    const unsigned int SIZE = 5;
    int arr[SIZE] = {13, 0, 2, 3, 16};

    std::cout << findSum(arr, SIZE) << '\n';

}