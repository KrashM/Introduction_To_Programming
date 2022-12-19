#include <iostream>

using std::cin;
using std::cout;

bool isStronglyIncreasing(const int arr[], const size_t &n){

    for(size_t i = 0; i < n - 1; ++i)
        if(arr[i] >= arr[i + 1]) return false;
    return true;

}

bool isIncreasingThanDecreasing(const int arr[], const size_t &n){

    bool flip = true;

    for(size_t i = 0; i < n - 1; ++i)
        if(flip) flip = arr[i] < arr[i + 1];
        else if(arr[i] <= arr[i + 1]) return false;

    return true;

}

bool isDecreasingThanIncreasing(const int arr[], const size_t &n){

    bool flip = true;

    for(size_t i = 0; i < n - 1; ++i)
        if(flip) flip = arr[i] > arr[i + 1];
        else if(arr[i] >= arr[i + 1]) return false;

    return true;

}

int main(){

    size_t n;
    cin >> n;

    int arr[1024];
    for(size_t i = 0; i < n; ++i)
        cin >> arr[i];

    if(isStronglyIncreasing(arr, n)) cout << "It is strongly increasing\n";
    else if(isDecreasingThanIncreasing(arr, n)) cout << "It is decreasing than increasing after kth element.\n";
    else if(isIncreasingThanDecreasing(arr, n)) cout << "It is increasing than decreasing after kth element.\n";
    else cout << "None of the others\n";

}