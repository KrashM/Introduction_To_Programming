#include <iostream>

const std::size_t MAX_ARRAY_CAPACITY = 100;

void readArray(int array[], std::size_t size);

void printArray(const int array[], std::size_t size);

std::size_t minFrom(const int array[], std::size_t from, std::size_t to);

void selectionSort(int array[], std::size_t size);

int main()
{
    std::size_t size;
    int numbers[MAX_ARRAY_CAPACITY];

    std::cin >> size;
    readArray(numbers, size);

    selectionSort(numbers, size);

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

std::size_t minFrom(const int array[], std::size_t from, std::size_t to)
{
    std::size_t min = from;
    for (std::size_t i = from + 1; i < to; ++i)
    {
        if (array[i] < array[min])
        {
            min = i;
        }
    }
    return min;
}

void selectionSort(int array[], std::size_t size)
{
    for (std::size_t i = 0; i < size - 1; ++i)
    {
        int minIndex = minFrom(array, i, size);
        std::swap(array[i], array[minIndex]);
    } 
}
