#include <iostream>

using std::cin;
using std::cout;
using std::swap;
using std::nothrow;

void sort(int *arr, const size_t &size){

    for(size_t i = 0; i < size - 1; ++i)
        for(size_t j = i + 1; j < size; ++j)
            if(arr[i] > arr[j])
                swap(arr[i], arr[j]);

}

int main(){

    size_t size;
    cin >> size;

    int *arr = new(nothrow) int[size];
    if(!arr) return 1;

    for(size_t i = 0; i < size; ++i)
        cin >> arr[i];

    sort(arr, size);

    for(size_t i = 0; i < size; ++i)
        cout << arr[i] << ' ';
    cout << '\n';

    delete[] arr;

}