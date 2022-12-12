#include <iostream>

using std::cin;
using std::cout;
using std::size_t;

void reduceArray(int *&array, size_t &n){

    if(n == 1) return;
    for(size_t i = 0; i < n - 1; ++i)
        array[i] += array[i + 1];
    reduceArray(array, --n);

}

int main(){

    size_t n;
    cin >> n;

    int *array = new int[n];
    for(size_t i = 0; i < n; ++i) cin >> array[i];

    reduceArray(array, n);
    cout << array[0] << '\n';

    delete[] array;

}