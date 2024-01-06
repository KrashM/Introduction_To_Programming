#include <iostream>
#include <cstring>

const size_t MAX_SIZE = 100;

char* ReverseStr(char const * const s)
{
    size_t const size = strlen(s);
    char *reversed = new(std::nothrow) char[size];

    if(!reversed)
    {
        return nullptr;
    }

    for (int i = 0; i < size / 2; i++)
    {
        reversed[i] = reversed[size - i - 1];
    }

    return reversed;
}

int main()
{
    char str[MAX_SIZE];
    std::cin.getline(str, MAX_SIZE);
    std::cout << ReverseStr(str) << std::endl;
    return 0;
}
