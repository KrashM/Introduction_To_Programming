#include <iostream>

void Swap(unsigned int* a, unsigned int* b)
{
    unsigned int temp = *a;
    *a = *b;
    *b = temp;
}

unsigned int* CreateArray(const size_t size)
{
    return new(std::nothrow) unsigned int[size];
}

void ReadArray(unsigned int* const array, const size_t size)
{
    for(size_t i = 0; i < size; i++)
    {
        std::cin >> array[i];
    }
}

void PrintArray(const unsigned int* const array, const size_t size)
{
    for(size_t i = 0; i < size; i++)
    {
        std::cout << array[i] << ' ';
    }
    std::cout << std::endl;
}

void Modify(unsigned int* const array, const size_t size)
{
    for(size_t i = 0; i < size / 2; i++)
    {
        if(array[i] > array[size - i - 1])
        {
            Swap(&array[i], &array[size - i - 1]);
        }
    }
}

int main()
{
    size_t n;
    std::cin >> n;

    unsigned int* array = CreateArray(n);
    if(!array)
    {
        std::cout << "Memory problem!" << std::endl;
        return -1;
    }

    ReadArray(array, n);
    Modify(array, n);
    PrintArray(array, n);

    delete[] array;
    array = nullptr;
    
    return 0;
}
