#include <iostream>
#include <cstring>

bool IsDigit(char c)
{
    return c >= '0' && c <= '9';
}

unsigned CountNumbers(const char* const str)
{
    unsigned int count = 0, i = 0, len = strlen(str);
    while(i < len)
    {
        bool isNum = false;
        while(IsDigit(str[i]))
        {
            isNum = true;
            i++;
        }
        count += isNum;
        i += !isNum;
    }
    return count;
}

unsigned ToInt(const char* str, const unsigned int from, const unsigned int to)
{
    unsigned int result = 0;
    for(unsigned i = from; i <= to; i++)
    {
        result *= 10;
        result += (str[i] - '0');
    }
    return result;
}

unsigned int* GetNumbers(const char* str, const unsigned int size)
{
    unsigned int* numbers = new(std::nothrow) unsigned int[size];
    if(!numbers)
    {
        return nullptr;
    }

    unsigned int len = strlen(str), i = 0, j = 0;
    while(i < len && j < size)
    {
        if(IsDigit(str[i]))
        {
            unsigned int from = i, to = i;
            while(i + 1 < len && IsDigit(str[i + 1]))
            {
                to++;
                i++;
            }
            numbers[j] = ToInt(str, from, to);
            j++; i++;
        }
        else i++;
    }

    return numbers;
}

int main()
{
    const unsigned int CAPACITY = 256;
    char str[CAPACITY];
    std::cin.getline(str, CAPACITY);

    unsigned int size = CountNumbers(str);
    if(size == 0)
    {
        return 0;
    }

    unsigned int* numbers = GetNumbers(str, size);
    if(!numbers)
    {
        std::cout << "Memory problem!" << std::endl;
        return -1;
    }

    for(unsigned i = 0; i < size; i++)
    {
        std::cout << numbers[i] << ' ';
    }
    std::cout << std::endl;

    delete[] numbers;
    numbers = nullptr;

    return 0;
}
