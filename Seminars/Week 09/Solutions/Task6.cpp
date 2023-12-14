#include <iostream>

int *PrintSumDiffs(int * const array, size_t const size){

    int *answer = new(std::nothrow) int[size], total;

    if(!answer) return nullptr;

    for(size_t i = 1; i < size; ++i)
        array[i] += array[i - 1];
    
    total = array[size - 1];

    answer[0] = total - array[0];

    for(size_t i = 1; i < size; ++i)
        answer[i] = std::abs(total - array[i] - array[i - 1]);

    return answer;

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

    int *result = PrintSumDiffs(array, n);

    if(!result){

        std::cout << "Memory error\n";
        delete[] array;
        return -1;

    }

    for(size_t i = 0; i < n; ++i) std::cout << result[i] << ' ';
    std::cout << '\n';

    delete[] array;

    return 0;

}