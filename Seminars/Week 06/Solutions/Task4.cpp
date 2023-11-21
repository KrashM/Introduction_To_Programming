#include <iostream>

int countNumberOfMatchingIntegers(const int arr1[], const int arr2[], const unsigned int SIZE_1, const unsigned int SIZE_2){

    unsigned int counter = 0;

    for(unsigned i = 0; i < SIZE_1; i++)
        for(unsigned int j = 0; j < SIZE_2; j++)
            if(arr1[i] == arr2[j]){

                counter++;
                break;

            }

    return counter;

}

int main(){

    const unsigned int SIZE_1 = 9, SIZE_2 = 12;
    int arr1[SIZE_1] = {1, 2, 3, 4, 5, 6, 7, 8, 9}, arr2[SIZE_2] = {14, 67, 23, 4, 92, 6, 10, 2, 48, 5, 19, 4};

    std::cout << countNumberOfMatchingIntegers(arr1, arr2, SIZE_1, SIZE_2) << '\n';

}