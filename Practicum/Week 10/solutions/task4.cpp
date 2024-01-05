#include <iostream>
#include <cstring>

int Find(const char* s, const char* s1)
{
    int index = -1;
    size_t sLen = strlen(s), s1Len = strlen(s1);

    for(size_t i = 0; i < sLen; i++)
    {
        size_t j = 0;
        while(*s && *s1 && s[i] == s1[j])
        {
            i++;
            j++;
        }

        i -= j;

        if(j - 1 == s1Len)
        {
            index = i;
            break;
        }
    }

    return index;
}

int main()
{
    const size_t MAX_SIZE = 256;
    char s[MAX_SIZE], s1[MAX_SIZE];

    std::cout << "s: ";
    std::cin.getline(s, MAX_SIZE);

    std::cout << "s1: ";
    std::cin.getline(s1, MAX_SIZE);

    std::cout << Find(s, s1) << std::endl;
    return 0;
}
