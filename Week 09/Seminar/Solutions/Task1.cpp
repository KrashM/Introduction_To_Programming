#include <iostream>

using std::cin;
using std::cout;
using std::size_t;

int findMajorityNumber(const int *array, const size_t &n){

    size_t timesFound, majorityFound = 0;
    int result;

    for(size_t i = 0; i < n - majorityFound; ++i){

        timesFound = 1;

        for(size_t j = i + 1; j < n; ++j)
            if(array[i] == array[j]) ++timesFound;

        if(timesFound > majorityFound){

            result = array[i];
            majorityFound = timesFound;

        }

    }

    return result;

}

int main(){

    size_t n;
    cin >> n;
    int *array = new int[n], number;

    for(size_t i = 0; i < n; ++i) cin >> array[i];

    cout << findMajorityNumber(array, n) << '\n';

    delete[] array;

}