#include <iostream>

int getProcuct(const int* arr, std::size_t n);

void printStr(const char* str);

void printARow(char ch, std::size_t size);

void printTriangle(char ch, std::size_t rows);

int main ()
{

    int arr[] = {1, 2, 3, 4, 5};
    std::cout << getProcuct(arr, 5) << std::endl;

    printStr("Bravo, Lyubo");

    return 0;
}

int getProcuct(const int* arr, std::size_t n)
{
    if (n == 0)
    {
        return 1; 
    }

    return *arr * getProcuct(arr + 1, n - 1);
}

void printStr(const char* str)
{
    if (!*str)
    {
        std::cout << std::endl;
        return;
    }

    std::cout << *str;
    printStr(str + 1);
}

void printTriangle(char ch, std::size_t rows)
{
    if (rows == 0)
    {
        return;
    }

    printTriangle(ch, rows - 1);
    printARow(ch, rows);
    std::cout << std::endl;
}

void printARow(char ch, std::size_t size)
{
    if (size == 0)
    {
        return;
    }

    std::cout << ch << " ";
    printARow(ch, size - 1);
}