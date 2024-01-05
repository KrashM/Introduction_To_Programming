#include <iostream>
#include <cstring>

char* LargestPrefix(const char* str1, const char* str2, const char* str3)
{
    size_t minlen = std::min(strlen(str1), strlen(str2));
    minlen = std::min(minlen, strlen(str3));

    char* result = new(std::nothrow) char[minlen + 1];
    if(!result)
    {
        return nullptr;
    }

    for(int i = 0; i < minlen; i++)
    {
        if(str1[i] != str2[i] || str2[i] != str3[i])
        {
            result[i] = '\0';
            return result;
        }
        else
        {
            result[i] = str1[i];
        }
    }

    result[minlen] = '\0';
    return result;
}

int main()
{
    size_t n1, n2, n3;
    std::cin >> n1;

    char* str1 = new(std::nothrow) char[n1];
    if(!str1)
    {
        std::cout << "Memory problem!" << std::endl;
        return -1;
    }

    std::cin.get();
    std::cin.getline(str1, n1 + 1);

    std::cin >> n2;

    char* str2 = new(std::nothrow) char[n2];
    if(!str2)
    {
        std::cout << "Memory problem!" << std::endl;

        delete[] str1;
        str1 = nullptr;

        return -1;
    }

    std::cin.get();
    std::cin.getline(str2, n2 + 1);

    std::cin >> n3;

    char* str3 = new(std::nothrow) char[n3];
    if(!str3)
    {
        std::cout << "Memory problem!" << std::endl;

        delete[] str1;
        str1 = nullptr;

        delete[] str2;
        str2 = nullptr;

        return -1;
    }

    std::cin.get();
    std::cin.getline(str3, n3 + 1);

    char* pref = LargestPrefix(str1, str2, str3);
    if(pref)
    {
        std::cout << '\n' << pref << std::endl;
    }

    delete[] pref;
    pref = nullptr;

    delete[] str1;
    str1 = nullptr;

    delete[] str2;
    str2 = nullptr;

    delete[] str3;
    str3 = nullptr;

    return 0;
}
