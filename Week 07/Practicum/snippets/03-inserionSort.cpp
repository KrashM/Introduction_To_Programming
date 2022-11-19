#include <iostream>

const std::size_t MAX_ARRAY_CAPACITY = 100;

void readArray(int array[], std::size_t size);

void printArray(const int array[], std::size_t size);

void insertInSorted(int array[], std::size_t size, int x);

void insertionSort(int array[], std::size_t size);

int main()
{
    std::size_t size;
    int numbers[MAX_ARRAY_CAPACITY];

    std::cin >> size;
    readArray(numbers, size);

    insertionSort(numbers, size);

    printArray(numbers, size);

    return 0;
}

void readArray(int array[], std::size_t size)
{
    for (std::size_t i = 0; i < size; ++i)
    {
        std::cin >> array[i];
    }
}

void printArray(const int array[], std::size_t size)
{
    for (std::size_t i = 0; i < size; ++i)
    {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;
}

void insertInSorted(int array[], std::size_t size, int x)
{
    std::size_t i = size;
    while (i > 0 && array[i-1] > x)
    {
        array[i] = array[i-1];
        --i;
    }
    array[i] = x;
}

void insertionSort(int array[], std::size_t size)
{
    for (std::size_t i = 1; i < size; ++i)
    {
        insertInSorted(array, i, array[i]);
    }
}