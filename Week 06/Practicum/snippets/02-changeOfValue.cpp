#include <iostream>
#include <cstring>

const std::size_t MAX_CAPACITY = 1024;

void swap(char str1[], char str2[]);

int main ()
{
    char str1[MAX_CAPACITY] = "Pesho";
    char str2[MAX_CAPACITY] = "Lyubo";

    std::cout << str1 << " " << str2 << std::endl;
    swap(str1, str2);
    std::cout << str1 << " " << str2 << std::endl;

    return 0;
}

void swap(char str1[], char str2[])
{
    char temp[MAX_CAPACITY];

    strcpy(temp, str1);
    strcpy(str1, str2);
    strcpy(str2, temp);
}