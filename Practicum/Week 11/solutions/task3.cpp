#include <iostream>
#include <cstring>

bool IsWordCharacter(char const c)
{
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || 
           (c >= '0' && c <= '9') || 
           c == '_';
}

bool IsPunctuationMark(char const a)
{
    return a == ',' || a == '.' || a == '?' || a == '!'; 
}

bool IsValidString(const char* const str)
{
    for(unsigned i = 0; str[i]; ++i)
    {
        if(!IsWordCharacter(str[i]) && !IsPunctuationMark(str[i]) && str[i] != ' ')
        {
            return false;
        }
    }
    return true;
}

void Modify(char* const str)
{
    unsigned len = strlen(str), read = 0, write = 0;

    while(read < len && str[read] == ' ') ++read;

    while(read < len)
    {
        if(IsWordCharacter(str[read]) || IsPunctuationMark(str[read]))
        {
            str[write++] = str[read++];
        }

        while(str[read] == ' ' && read + 1 < len && str[read + 1] == ' ')
        {
            read++;
        }

        if(str[read] == ' ' && read + 1 < len && IsPunctuationMark(str[read + 1]))
        {
            str[write++] = str[read + 1];

            if(read + 1 != len)
                str[write++] = ' ';

            read += 2;
        }

        if(str[read] == ' ' && read + 1 < len && IsWordCharacter(str[read + 1]))
        {
            if(IsWordCharacter(str[write - 1])) 
                str[write++] = ' ';

            str[write++] = str[read + 1];
            read += 2;
        }
    }

    str[write] = '\0';
}

int main()
{
    unsigned len;
    std::cin >> len;

    char* str = new(std::nothrow) char[len + 1];
    if(!str)
    {
        std::cout << "Memory problem!" << std::endl;
        return -1;
    }

    std::cin.get();
    std::cin.getline(str, len + 1);
    
    if(!IsValidString(str))
    {
        std::cout << "Threre are invalid characters in the string!" << std::endl;

        delete[] str;
        str = nullptr;

        return -1;
    }

    Modify(str);
    std::cout << std::endl << str << std::endl;

    delete[] str;
    str = nullptr;

    return 0;
}
