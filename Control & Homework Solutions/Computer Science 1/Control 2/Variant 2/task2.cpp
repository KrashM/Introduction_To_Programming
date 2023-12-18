#include <iostream>

const size_t MAX_SIZE = 100;

bool AreSum(long a, long b, long c)
{
    if (a + b == c)
        return true;
    if (c + b == a)
        return true;
    if (a + c == b)
        return true;
    return false;
}

long CountSums(long arr1[], long arr2[], long arr3[], size_t n)
{
    int counter=0;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            for (int k = 0; k < n; k++){//може и с двоично
                counter+=AreSum(arr1[i], arr2[j], arr3[k]);
            }
        }
    }
    return counter;
}

void InputArr(long *arr, size_t n)
{
    for (int i = 0; i < n; i++)
        std::cin >> arr[i];
}

int main()
{
    size_t n;
    long arr1[MAX_SIZE], arr2[MAX_SIZE], arr3[MAX_SIZE];
    std::cin >> n;
    InputArr(arr1, n);
    InputArr(arr2, n);
    InputArr(arr3, n);
    std::cout << "Count of sums: " << CountSums(arr1, arr2, arr3, n) << std::endl;
}
/*
3
1 3 5
2 4 5
0 3 6

5
=> (1,2,3), (5,2,3), (1,5,6), (1,4,3), (5,5,0)
----------------------------
3
1 3 5
2 4 5
0 3 5

6
=> (1,2,3), (5,2,3), (1,4,5), (1,4,3), (5,5,0), (3,2,5)
*/