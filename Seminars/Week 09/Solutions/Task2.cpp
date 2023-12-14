#include <iostream>

void Swap(int &a, int &b){

    int temp = a;
    a = b;
    b = temp;

}

unsigned CountTurnedBits(int number){

    unsigned count = 0;

    for(unsigned i = 0; i < sizeof(number) * 8; ++i)
        count += !!(number & 1 << i);

    return count;

}

void Sort(int * const array, size_t const size){

    for(size_t i = 0; i < size - 1; ++i)
        for(size_t j = i + 1; j < size; ++j)
            if(CountTurnedBits(array[i]) > CountTurnedBits(array[j])) Swap(array[i], array[j]);
            else if(array[i] > array[j]) Swap(array[i], array[j]);

}

int main(){

    size_t n;
    std::cin >> n;

    int *array = new(std::nothrow) int[n];

    if(!array){

        std::cout << "Memory error\n";
        return -1;

    }

    for(size_t i = 0; i < n; ++i) std::cin >> array[i];

    Sort(array, n);

    for(size_t i = 0; i < n; ++i) std::cout << array[i] << ' ';
    std::cout << '\n';

    delete[] array;

    return 0;

}