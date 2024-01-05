#include <iostream>
#include <cstring>

const size_t MAX_SIZE = 100;

char* ReverseStr(char* s)
{
    int n = strlen(s);
    for (int i = 0; i < n / 2; i++)
    {
        std::swap(s[i], s[n - i - 1]);
    }
    return s;
}

int main()
{
    char str[MAX_SIZE];
    std::cin.getline(str, MAX_SIZE);
    std::cout << ReverseStr(str) << std::endl;
    return 0;
}
