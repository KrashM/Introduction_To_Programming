#include <iostream>

void Swap(int &a, int &b){

    int temp = a;
    a = b;
    b = temp;

}

void Sort(int * const array, size_t const size){

    for(size_t i = 0; i < size - 1; ++i)
        for(size_t j = i + 1; j < size; ++j)
            if(array[i] > array[j])
                Swap(array[i], array[j]);

}

bool CanSplitIntoNPairs(int * const nums, size_t size){

    Sort(nums, size);

    for(size_t i = 0; i < size; i += 2)
        if(nums[i] != nums[i + 1])
            return false;

    return true;

}

int main(){

    size_t n;
    std::cin >> n;

    if(n % 2 != 0){

        std::cout << "Incorrect size\n";
        return -1;

    }

    int *nums = new(std::nothrow) int[n];

    if(!nums){

        std::cout << "Memory error\n";
        return -1;

    }

    for(size_t i = 0; i < n; ++i) std::cin >> nums[i];

    std::cout << std::boolalpha << CanSplitIntoNPairs(nums, n) << '\n';

    delete[] nums;

    return 0;

}