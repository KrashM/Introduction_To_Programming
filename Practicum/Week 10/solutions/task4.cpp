#include <iostream>
#include <cstring>

int Find(const char* const s, const char* const s1)
{
    size_t const sLen = strlen(s), s1Len = strlen(s1);

    for(size_t i = 0; i < sLen; i++)
    {
        size_t j = 0;
        while(s[i] && s1[j] && s[i] == s1[j])
        {
            i++;
            j++;
        }

        i -= j;

        if(j - 1 == s1Len)
        {
            return i;
        }
    }

    return -1;
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
