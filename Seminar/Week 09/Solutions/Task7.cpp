#include <iostream>

using std::cin;
using std::cout;
using std::size_t;

void swap(int &a, int &b){

    int temp = a;
    a = b;
    b = temp;

}

void reorder(int *array, const size_t &n, const int &k){

    size_t index = 0;

    for(size_t i = 0; i < n; ++i)
        if(array[i] < k){
            
            swap(array[i], array[index++]);
            if(array[i] == k) swap(array[i], array[index]);

        }

}

void print(const int *array, const size_t &n){

    for(size_t i = 0; i < n; ++i)
        cout << array[i] << ' ';
    cout << '\n';

}

int main(){

    size_t n;
    cin >> n;

    int *array = new int[n], k;

    for(size_t i = 0; i < n; ++i) cin >> array[i];
    cin >> k;

    reorder(array, n, k);
    print(array, n);

    delete[] array;
    
}