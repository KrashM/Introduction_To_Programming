#include <iostream>

unsigned int* CreateArray(const size_t size)
{
    unsigned int* array = new(std::nothrow) unsigned int[size];
    if(!array)
    {
        return nullptr;
    }
    return array;
}

void ReadArray(unsigned int* array, const size_t size)
{
    for(size_t i = 0; i < size; i++)
    {
        std::cin >> array[i];
    }
}

void Swap(unsigned int* a, unsigned int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

// selection sort -> asc
void SortAsc(unsigned int* array, const size_t from, const size_t to)
{
    for(unsigned i = from; i < to; i++) 
    {
        unsigned minIndex = i;
        for(unsigned j = i + 1; j < to; j++) 
        {
            if (array[j] < array[minIndex])
            {
                minIndex = j;
            }
        }

        if(minIndex != i) 
        {
            Swap(&array[minIndex], &array[i]);
        }
    }
}


// selection sort -> desc
void SortDesc(unsigned int* array, const size_t from, const size_t to)
{
    for(unsigned i = from; i < to; i++) 
    {
        unsigned maxIndex = i;
        for(unsigned j = i + 1; j < to; j++) 
        {
            if(array[j] > array[maxIndex])
            {
                maxIndex = j;
            }
        }

        if(maxIndex != i) 
        {
            Swap(&array[maxIndex], &array[i]);
        }
    }
}

void Sort(unsigned int* array, const size_t size)
{
    SortAsc(array, 0, size / 2);
    SortDesc(array, size / 2, size);
}

void PrintArray(const unsigned int* array, const size_t size)
{
    for(size_t i = 0; i < size; i++)
    {
        std::cout << array[i] << ' ';
    }
    std::cout << std::endl;
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
    Sort(array, n);
    PrintArray(array, n);

    delete[] array;
    array = nullptr;
    
    return 0;
}
