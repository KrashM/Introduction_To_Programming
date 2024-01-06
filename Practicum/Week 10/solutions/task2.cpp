#include <iostream>

size_t strlen(const char* const str)
{
    unsigned int len = 0;
    while(str[len]) // str[len] != '\0'
    {
        ++len;
    }
    return len;
}

int strcmp(const char* str1, const char* str2)
{
    while(*str1 && *str2 && *str1 == *str2)
    {
        ++str1;
        ++str2;
    }
    return *str1 - *str2;
}

// The destination array must be large enough to append the contents of 
// source array (including the terminating null character).
void strcat(char* const destination, const char* const source)
{
    size_t destLen = strlen(destination), 
           srcLen  = strlen(source);

    for(size_t i = 0; i < srcLen; i++)
    {
        destination[destLen + i] = source[i];
    }
    destination[destLen + srcLen] = '\0';
}

// The destination array must be large enough to contain the same string 
// as source (including the terminating null character).
void strcpy(char* const destination, const char* const source)
{
    size_t srcLen = strlen(source);
    for(size_t i = 0; i < srcLen; i++)
    {
        destination[i] = source[i];
    }
    destination[srcLen] = '\0';
}

int main()
{
    const size_t MAX_SIZE = 256;
    char str1[MAX_SIZE], str2[MAX_SIZE];

    std::cout << "str1: ";
    std::cin.getline(str1, MAX_SIZE);

    std::cout << "str2: ";
    std::cin.getline(str2, MAX_SIZE);

    size_t str1Len = strlen(str1), str2Len = strlen(str2);
    std::cout << "\nstr1 length: " << str1Len
              << "\nstr2 length: " << str2Len
              << std::endl;
    
    std::cout << "\nstring comparation: " << strcmp(str1, str2) << std::endl;

    if(str1Len + str2Len + 1 <= MAX_SIZE)
    {
        strcat(str1, str2);
        std::cout << "\nconcatenation: " << str1 << std::endl;
        str1Len = strlen(str1);
    }

    if(str1Len + 1 <= MAX_SIZE)
    {
        strcpy(str2, str1);
        std::cout << "\ncopy str1 to str2: " << str2 << std::endl;
    }
    return 0;
}
