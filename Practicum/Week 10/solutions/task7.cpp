#include <iostream>
#include <cstring>

const size_t MAX_SIZE = 100, LETTERS = 26;

bool IsValid(const char* const str)
{
    unsigned int len = strlen(str);
    for(unsigned i = 0; i < len; i++)
    {
        if(!(str[i] >= 'a' && str[i] <= 'z'))
        {
            return false;
        }
    }
    return true;
}

char* RemoveDuplicates(const char* const str)
{
    unsigned int letters[LETTERS] = { 0, }, 
                 len = strlen(str);

    for(unsigned i = 0; i < len; i++)
    {
        letters[str[i] - 'a']++;
    }

    unsigned int length = 0;
    for(unsigned i = 0; i < LETTERS; i++)
    {
        length += (letters[i] == 1);
    }

    char *result = new(std::nothrow) char[length + 1];
    if(!result)
    {
        std::cout << "Memory problem!" << std::endl;
        return nullptr;
    }

    unsigned int index = 0;
    for(unsigned i = 0; i < len; i++)
    {
        if(letters[str[i] - 'a'] == 1)
        {
            result[index++] = str[i];
        }
    }
    result[length] = '\0';
    return result;
}

int main()
{
    char input[MAX_SIZE];
    std::cin.getline(input, MAX_SIZE);

    if(!IsValid(input))
    {
        std::cout << "Incorrect input!" << std::endl;
        return -1;
    }

    char* result = RemoveDuplicates(input);
    std::cout << result << std::endl;

    delete[] result;
    result = nullptr;

    return 0;
}
