#include <iostream>

int* CreateArray(const size_t size)
{
    return new(std::nothrow) int[size];
}

void ReadArray(int* const array, const size_t size)
{
    for(size_t i = 0; i < size; i++)
    {
        std::cin >> array[i];
    }
}

void PrintArray(const int* const array, const size_t size)
{
    for(size_t i = 0; i < size; i++)
    {
        std::cout << *(array + i) << ' ';
    }
    std::cout << std::endl;
}

int main()
{
    size_t n;
    std::cin >> n;

    int* array = CreateArray(n);
    if(!array)
    {
        std::cout << "Memory problem!" << std::endl;
        return -1;
    }

    ReadArray(array, n);
    PrintArray(array, n);

    delete[] array;
    array = nullptr;
    
    return 0;
}
