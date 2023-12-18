#include <iostream>
#include <cstring>

const size_t MAX_SIZE = 100;

int GetMaxLen(char *s)
{
    int maxLen = 0, len = 0, index = 0;
    while (s[index])
    {
        if (s[index] == ' ')
        {
            maxLen = std::max(maxLen, len);
            len = 0;
        }
        else
            len++;
        index++;
    }
    maxLen = std::max(maxLen, len);
    return maxLen;
}

void split(char *s, char *a, char *b)
{
    char *word = new (std::nothrow) char[GetMaxLen(s) + 1];
    if (!word)
    {
        std::cout << "Memory error" << std::endl;
        return;
    }

    int index = 0, wordIndex = 0, n=strlen(s);
    bool onlyLowerCase = true;
    a[0] = 0;
    b[0] = 0;
    while (index<n)
    {
        onlyLowerCase = true;
        wordIndex = 0;
        while (s[index] && s[index] != ' ')
        {
            word[wordIndex] = s[index];
            onlyLowerCase &= (s[index] >= 'a' && s[index] <= 'z');
            index++;
            wordIndex++;
        }
        word[wordIndex] = 0;
        wordIndex++;

        if (onlyLowerCase)
        {
            strcat(a, word);
            strcat(a, " ");
        }
        else
        {
            strcat(b, word);
            strcat(b, " ");
        }

        index++;
    }

    a[strlen(a) - 1] = 0;
    b[strlen(b) - 1] = 0;
}

int main()
{
    char s[MAX_SIZE] = "Please give me 4 COLD beers NOW!";
    char a[MAX_SIZE], b[MAX_SIZE];
    split(s, a, b);
    std::cout << "|" << a << "|" << b << "|" << std::endl;
}
