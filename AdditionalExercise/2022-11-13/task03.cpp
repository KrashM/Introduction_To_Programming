#include <iostream>
#include <cstring>

// Да се напише програма, която приема низ и намира най-късата и най-дългата дума в него.

const std::size_t MAX_CAPACITY = 1024;

void printLongestAndShortestWords(const char str[]);

int main ()
{
    char str[MAX_CAPACITY];

    std::cin.getline(str, MAX_CAPACITY);

    printLongestAndShortestWords(str);

    return 0;
}

// !(a || b) = !a && !b
// !(a && b) = !a || !b

void printLongestAndShortestWords(const char str[])
{
    char shortest[MAX_CAPACITY], longest[MAX_CAPACITY];
    std::size_t shortestSize, longestSize;

    std::size_t i = 0;

    while (str[i] != '\0' && str[i] != ' ')
    {
        shortest[i] = str[i];
        longest[i] = str[i];
        ++i;
    }

    shortest[i] = '\0';
    longest[i] = '\0';

    shortestSize = longestSize = i;
    ++i;
    
    std::size_t currentSize = 0;
    char temp[MAX_CAPACITY];

    while (str[i] != '\0')
    {
        if (str[i] != ' ')
        {
            temp[currentSize] = str[i];
            ++currentSize;
        }
        else
        {
            temp[currentSize] = '\0';
            if (currentSize < shortestSize)
            {
                strcpy(shortest, temp);
                shortestSize = currentSize;
            }
            if (currentSize > longestSize)
            {
                strcpy(longest, temp);
                longestSize = currentSize;
            }

            currentSize = 0;
        }
        ++i;
    }

    std::cout << shortest << ' ' << longest << '\n';
}