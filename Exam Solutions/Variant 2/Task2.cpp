#include <iostream>

using std::cin;
using std::cout;
using std::nothrow;

struct int_array{
    
    int *arr;
    unsigned int size;
    
};

int_array duplicate(const int_array &arr){

    int_array duped;
    duped.size = arr.size * 2;

    duped.arr = new(nothrow) int[duped.size];
    if(!duped.arr){

        duped.size = 0;
        return duped;

    }

    for(size_t i = 0; i < arr.size; ++i)
        duped.arr[2 * i] = duped.arr[2 * i + 1] = arr.arr[i];

    return duped;

}

int main(){

    int_array arr;
    cin >> arr.size;

    arr.arr = new(nothrow) int[arr.size];
    if(!arr.arr) return 1;

    for(unsigned i = 0; i < arr.size; ++i)
        cin >> arr.arr[i];

    int_array duped = duplicate(arr);

    for(unsigned i = 0; i < duped.size; ++i)
        cout << duped.arr[i] << ' ';
    cout << '\n';

    delete[] arr.arr;
    delete[] duped.arr;

}