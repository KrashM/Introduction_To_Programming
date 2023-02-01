#include <iostream>

using std::cin;
using std::cout;
using std::nothrow;

void shift_left(int *arr, const size_t &size, const size_t &k){

    int temp;

    for(size_t i = 0; i < k; ++i){

        temp = arr[0];
        for(size_t j = 0; j < size - 1; ++j)
            arr[j] = arr[j + 1];
        arr[size - 1] = temp;

    }

}

int main(){

    size_t size, k;
    cin >> size;

    int *arr = new(nothrow) int[size];
    if(!arr) return 1;

    for(unsigned i = 0; i < size; ++i)
        cin >> arr[i];

    cin >> k;

    shift_left(arr, size, k);

    for(unsigned i = 0; i < size; ++i)
        cout << arr[i] << ' ';
    cout << '\n';

    delete[] arr;

}