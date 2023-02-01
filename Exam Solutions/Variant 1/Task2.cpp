#include <iostream>

using std::cin;
using std::cout;
using std::nothrow;

struct int_array{
    
    int *arr;
    unsigned int size;
    
};

unsigned countEvens(const int_array &arr){

    size_t counter = 0;
    for(unsigned i = 0; i < arr.size; ++i)
        counter += arr.arr[i] % 2 == 0;

    return counter;

}

int_array filter_evens(const int_array &arr){

    int_array filtered;
    filtered.size = countEvens(arr);

    filtered.arr = new(nothrow) int[filtered.size];
    if(!filtered.arr){

        filtered.size = 0;
        return filtered;

    }

    unsigned j = 0;

    for(unsigned i = 0; i < arr.size; ++i)
        if(arr.arr[i] % 2 == 0)
            filtered.arr[j++] = arr.arr[i];

    return filtered;

}

int main(){

    int_array arr;
    cin >> arr.size;

    arr.arr = new(nothrow) int[arr.size];
    if(!arr.arr) return 1;

    for(unsigned i = 0; i < arr.size; ++i)
        cin >> arr.arr[i];

    int_array filtered = filter_evens(arr);

    for(unsigned i = 0; i < filtered.size; ++i)
        cout << filtered.arr[i] << ' ';
    cout << '\n';

    delete[] arr.arr;
    delete[] filtered.arr;

}