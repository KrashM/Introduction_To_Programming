#include <iostream>

using std::cin;
using std::cout;
using std::size_t;

int findUnique(const int arr[], const size_t &size){

    int result = 0;
    for(size_t i = 0; i < size; i++) result ^= arr[i];
    return result;

}

int main(){

    int arr[] = { 9, 18, 9, 12, 18, 15, 12 };
    const size_t size = sizeof(arr) / sizeof(arr[0]);
    cout << findUnique(arr, size) << '\n';

}