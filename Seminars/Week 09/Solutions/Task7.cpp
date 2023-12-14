#include <iostream>

void Swap(int &a, int &b){

    int temp = a;
    a = b;
    b = temp;

}

void Reorder(int * const array, size_t const n, int const k){

    size_t index = 0;

    for(size_t i = 0; i < n; ++i)
        if(array[i] < k){
            
            Swap(array[i], array[index++]);
            if(array[i] == k) Swap(array[i], array[index]);

        }

}

void Print(int const * const array, size_t const n){

    for(size_t i = 0; i < n; ++i)
        std::cout << array[i] << ' ';
    std::cout << '\n';

}

int main(){

    size_t n;
    std::cin >> n;

    int *array = new(std::nothrow) int[n], k;

    if(!array){

        std::cout << "Memory error\n";
        return -1;

    }

    for(size_t i = 0; i < n; ++i) std::cin >> array[i];
    std::cin >> k;

    Reorder(array, n, k);
    Print(array, n);

    delete[] array;

    return 0;
    
}