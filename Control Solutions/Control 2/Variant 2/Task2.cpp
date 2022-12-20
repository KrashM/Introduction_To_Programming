#include <iostream>

using std::cin;
using std::cout;
using std::size_t;
using std::boolalpha;

#define MAX_SIZE 1024

bool isHeel(const int *array, const size_t &n){

    bool flip = false;
    for(size_t i = 0; i < n - 1; ++i){

        if(!flip && array[i] > array[i + 1]) flip = true;
        if(flip && array[i] < array[i + 1]) return false;

    }

    return flip;

}

int main(){

    int array[MAX_SIZE];
    size_t n;

    cin >> n;

    for(size_t i = 0; i < n; ++i)
        cin >> array[i];
    
    cout << boolalpha << isHeel(array, n) << '\n';
    
}