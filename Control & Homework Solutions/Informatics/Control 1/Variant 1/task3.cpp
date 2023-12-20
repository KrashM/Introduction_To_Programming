#include <iostream>

size_t const CAPACITY = 1024;

bool CanMakeZigZag(int const arr[], size_t const size){

    size_t currentCount = 1;

    for(size_t i = 0; i < size - 1; ++i){

        if(size % 2){
            if((arr[i] != arr[0] || arr[i] != arr[size - 1]) && currentCount > size / 2 + 1) return false;
        }
        else if(currentCount > size / 2) return false;

        if(arr[i] == arr[i + 1]) ++currentCount;
        else currentCount = 1;

    }

    return true;

}

unsigned FindMostCommonElement(int const arr[], size_t const size){

    size_t maxCount = 0, count = 1;
    int element;

    for(size_t i = 0; i < size - 1; ++i)
        if(arr[i] == arr[i + 1]) count++;
        else{

            if(count > maxCount){

                maxCount = count;
                element = arr[i];

            }
            count = 1;

        }

    if(count > maxCount) element = arr[size - 1];

    return element;

}

void Swap(int &a, int &b){

    int temp = a;
    a = b;
    b = temp;

}

void Sort(int arr[], size_t const size){

    for(size_t i = 0; i < size - 1; ++i)
        for(size_t j = i + 1; j < size; ++j)
            if(arr[i] > arr[j])
                Swap(arr[i], arr[j]);

}

void MakeZigZag(int arr[], size_t const size){

    Sort(arr, size);

    if(!CanMakeZigZag(arr, size)){

        std::cout << "Can't make zig zag\n";
        return;

    }

    size_t mostCommon = FindMostCommonElement(arr, size);

    bool startFromEnd = mostCommon == arr[size - 1];

    size_t left = 0, right = size - 1;
    int newArray[CAPACITY] = {0, };

    for(size_t i = 0; i < size; ++i)
        newArray[i] = (i + startFromEnd) % 2 == 0 ? arr[left++] : arr[right--];

    for(size_t i = 0; i < size; ++i)
        arr[i] = newArray[i];

}

bool IsZigZag(int const arr[], size_t const size){

    if(size <= 1) return true;
    if(arr[0] == arr[1]) return false;

    bool is_less_than = arr[0] < arr[1];

    for(size_t i = 1; i < size - 1; ++i){

        if(arr[i] == arr[i + 1]) return false;
        if(arr[i] > arr[i + 1] && !is_less_than) return false;
        if(arr[i] < arr[i + 1] && is_less_than) return false;

        is_less_than = !is_less_than;

    }

    return true;

}

int main(){

    int arr[CAPACITY];
    size_t size;
    std::cin >> size;

    if(size > CAPACITY){

        std::cout << "Wrong input\n";
        return -1;

    }

    for(size_t i = 0; i < size; ++i) std::cin >> arr[i];

    std::cout << std::boolalpha << IsZigZag(arr, size) << '\n';

    if(!IsZigZag(arr, size)) MakeZigZag(arr, size);

    for(size_t i = 0; i < size; ++i) std::cout << arr[i] << ' ';
    std::cout << '\n';

    std::cout << std::boolalpha << IsZigZag(arr, size) << '\n';

    return 0;

}