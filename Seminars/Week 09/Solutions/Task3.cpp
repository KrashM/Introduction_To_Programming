#include <iostream>

int FindMiddleIndex(int const * const nums, size_t const size){

    int totalSum = 0, leftSum = 0;

    for(size_t i = 0; i < size; ++i) totalSum += nums[i];

    for(size_t i = 0; i < size; ++i){

        if(leftSum == totalSum - nums[i]) return i;
        leftSum += nums[i];
        totalSum -= nums[i];

    }

    return -1;

}

int main(){

    size_t n;
    std::cin >> n;

    int *nums = new(std::nothrow) int[n];

    if(!nums){

        std::cout << "Memory error\n";
        return -1;

    }

    for(size_t i = 0; i < n; ++i) std::cin >> nums[i];

    std::cout << FindMiddleIndex(nums, n) << '\n';

    delete[] nums;

    return 0;

}