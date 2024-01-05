#include <iostream>
#include <cstring>

char* Censor(const char* str)
{
    unsigned len = strlen(str);

    char* newStr = new(std::nothrow) char[len + 1];
    if(!newStr)
    {
        return nullptr;
    }
    
    for(unsigned i = 0; i < len; i++)
    {
        if(str[i] >= '0' && str[i] <= '9')
        {
            newStr[i] = '*';
        }
        else
        {
            newStr[i] = str[i];
        }
    }

    newStr[len] = '\0';
    return newStr;
}

int main()
{
    const unsigned int CAPACITY = 1024;
    char str[CAPACITY];
    std::cin.getline(str, CAPACITY);

    char* newStr = Censor(str);
    if(!newStr)
    {
        std::cout << "Memory problem!" << std::endl;
        return -1;
    }

    std::cout << newStr << std::endl;

    delete[] newStr;
    newStr = nullptr;

    return 0;
}
