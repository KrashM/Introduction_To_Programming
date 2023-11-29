#include <iostream>

bool IsSorted(unsigned const arr[], size_t const size){

    bool isAscending = true, isDescending = true;
    for(size_t i = 0; i < size - 1 && (isAscending || isDescending); ++i){

        isAscending = isAscending && arr[i] > arr[i + 1];
        isDescending = isDescending && arr[i] < arr[i + 1];

    }

    return isAscending || isDescending;

}

void FindMostCommonElementWithoutExtraSpace(unsigned const arr[], size_t const size){

    unsigned mostCommonElementOccurences = 0, mostCommonElementIndex = 0, currentOccurences = 1, currentIndex = 0;
    for(size_t i = 1; i < size; ++i){

        if(arr[i] == arr[i - 1]) ++currentOccurences;
        else if(mostCommonElementOccurences < currentOccurences){

            mostCommonElementIndex = currentIndex;
            mostCommonElementOccurences = currentOccurences;

        }

    }

    std::cout << arr[mostCommonElementIndex] << ' ' << mostCommonElementOccurences << '\n';

}

void FindMostCommonElementWithExtraSpace(unsigned const arr[], size_t const size){

    size_t const MAX_ELEMENT = 1000;
    unsigned histogram[MAX_ELEMENT + 1] = { 0, };

    unsigned mostCommonElementOccurences = 0, mostCommonElement;

    for(size_t i = 0; i < size; ++i) ++histogram[arr[i]];

    for(size_t i = 0; i < MAX_ELEMENT + 1; ++i)
        if(histogram[i] > mostCommonElementOccurences){

            mostCommonElementOccurences = histogram[i];
            mostCommonElement = i;

        }

    std::cout << mostCommonElement << ' ' << mostCommonElementOccurences << '\n';

}

int main(){

    size_t const CAPACITY = 1024;
    unsigned arr[CAPACITY];
    size_t size;

    std::cin >> size;
    if(size == 0 || size >= CAPACITY){

        std::cout << "Invalid input\n";
        return -1;

    }

    for(size_t i = 0; i < size; ++i) std::cin >> arr[i];

    if(IsSorted(arr, size)) FindMostCommonElementWithoutExtraSpace(arr, size);
    else FindMostCommonElementWithExtraSpace(arr, size);

    return 0;

}