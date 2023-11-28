#include <iostream>

int FindMajorityNumber(int const * const array, size_t const size){

    unsigned timesFound, majorityFound = 0;
    int result;

    for(size_t i = 0; i < size - majorityFound; ++i){

        timesFound = 1;

        for(size_t j = i + 1; j < size; ++j)
            if(array[i] == array[j]) ++timesFound;

        if(timesFound > majorityFound){

            majorityFound = timesFound;
            result = array[i];

        }

    }

    return result;

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

    std::cout << FindMajorityNumber(array, n) << '\n';

    delete[] array;

    return 0;

}