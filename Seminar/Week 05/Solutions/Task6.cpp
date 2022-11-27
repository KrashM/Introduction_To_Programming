#include <iostream>
#include <limits.h>
#include <cmath>

int minDiff(const int arr[], const int len){

    int min = INT_MAX;

    for(int i = 0; i < len - 1; i++)
        for(int j = i + 1; j < len; j++)
            if(abs(arr[i] - arr[j]) < min)
                min = abs(arr[i] - arr[j]);

    return min;

}

int main(){

    const int SIZE = 8;

    const int arr[SIZE] = {10, 2, 5, 83, 20, 17, 24, 7};
    std::cout << minDiff(arr, SIZE) << '\n';

}