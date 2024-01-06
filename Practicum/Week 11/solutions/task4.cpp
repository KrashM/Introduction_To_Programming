#include <iostream>

const unsigned int MAX_SIZE = 100;

unsigned int ReadSize()
{
    unsigned int size;
    do
    {
        std::cout << "Enter size: ";
        std::cin >> size;
    } while (size > MAX_SIZE);
    return size;
}

void ReadArray(int array[], unsigned int const size)
{
    std::cout << "Enter array:\n";
    for(unsigned i = 0; i < size; i++)
    {
        std::cin >> array[i];
    }
}

void PrintArray(const int array[], unsigned int const size)
{
    for(unsigned i = 0; i < size; i++)
    {
        std::cout << array[i] << ' ';
    }
    std::cout << std::endl;
}

int* MergeArr(const int arr1[], const int arr2[], const unsigned int n1, const unsigned int n2)
{
    unsigned int index1 = 0, index2 = 0;

    int* result = new(std::nothrow) int[n1 + n2];
    if(!result)
    {
        return nullptr;
    }

    unsigned int index = 0;

    while(index1 < n1 || index2 < n2)
    {
        if(index1 == n1)
        {
            result[index] = arr2[index2];
            index2++; 
        }
        else if(index2 == n2)
        {
            result[index] = arr1[index1];
            index1++;
        }
        else
        {
            if(arr1[index1] > arr2[index2])
            {
                result[index] = arr2[index2];
                index2++;
            }
            else
            {
                result[index] = arr1[index1];
                index1++;
            }
        }
        index++;
    }
    return result;
}

int main()
{
    int arr1[MAX_SIZE], arr2[MAX_SIZE];

    unsigned int n1 = ReadSize();
    ReadArray(arr1, n1);

    unsigned int n2 = ReadSize();
    ReadArray(arr2, n2);

    int* result = MergeArr(arr1, arr2, n1, n2);
    if(!result)
    {
        std::cout << "Memory problem!" << std::endl;
        return -1;
    }

    std::cout << std::endl;
    PrintArray(result, n1 + n2);

    delete[] result;
    result = nullptr;

    return 0;
}

/*
5
1 3 5 7 9
6 
2 4 6 8 10 12
*/
