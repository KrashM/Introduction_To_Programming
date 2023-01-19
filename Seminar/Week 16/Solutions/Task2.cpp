#include <iostream>

using std::cin;
using std::cout;
using std::swap;
using std::nothrow;

void sort(int *&nums, const size_t &size){

    for(size_t i = 0; i < size - 1; ++i)
        for(size_t j = i + 1; j < size; ++j)
            if(nums[i] > nums[j])
                swap(nums[i], nums[j]);

}

int main(){

    size_t n, k;
    cin >> n;

    int *nums = new(nothrow) int[n];

    if(!nums) return 1;

    for(size_t i = 0; i < n; ++i)
        cin >> nums[i];

    sort(nums, n);

    cout << nums[k] << '\n';

    delete[] nums;

}