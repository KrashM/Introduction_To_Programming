#include <iostream>

using std::cin;
using std::cout;
using std::size_t;
using std::boolalpha;

#define MAX_SIZE 1024

bool isLeftSaw(const int *array, const size_t &n){


    bool flip = false;

    for(size_t i = 0; i < n - 1; ++i){

        if(!flip && array[i] < array[i + 1]) return false;
        if(flip && array[i] > array[i + 1]) return false;

        flip = !flip;

    }

    return true;
    
}

bool isRightSaw(const int *array, const size_t &n){

    bool flip = false;

    for(size_t i = 0; i < n - 1; ++i){

        if(!flip && array[i] > array[i + 1]) return false;
        if(flip && array[i] < array[i + 1]) return false;

        flip = !flip;

    }

    return true;

}

bool isSaw(const int *array, const size_t &n){
    return isLeftSaw(array, n) || isRightSaw(array, n);
}

int main(){

    int array[MAX_SIZE];
    size_t n;

    cin >> n;

    for(size_t i = 0; i < n; ++i)
        cin >> array[i];
    
    cout << boolalpha << isSaw(array, n) << '\n';

}