#include <iostream>

int gcd(int a, int b){

    int result = std::min(a, b);

    while(result > 0){

        if(!(a % result) && !(b % result)) break;
        result--;

    }

    return result;

}

int findLargestSubsetWithGCD1(const int arr[], const int n){

    int currentGCD = arr[0];

    for(int i = 1; i < n; i++){

        currentGCD = gcd(currentGCD, arr[i]);
        if(currentGCD == 1) return n;
    
    }

    return 0;

}

int main(){

    const int SIZE = 10;
    int arr[SIZE] = { 4, 8, 2, 2, 3, 18, 8, 10, 22, 12 };

    std::cout << findLargestSubsetWithGCD1(arr, SIZE) << '\n';

}