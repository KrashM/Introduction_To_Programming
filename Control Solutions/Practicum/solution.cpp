#include <iostream>
#include <fstream>
#include <cstring>

const std::size_t MAX_TEXT_CAPACITY = 10 * 1024 * 1024;
const std::size_t MAX_WORD_CAPACITY = 128;

struct DictionaryPair
{
    char* word;
    char replacement;
};

void readInput(char* input);

bool isLowerCase(char ch);

bool isUpperCase(char ch);

bool isLetter(char ch);

bool isDigit(char ch);

bool isPartOfWord(char ch);

bool isBlank(char ch);

bool isSentenceEnding(char ch);

bool isPunctuationMark(char ch);

bool containsValidSymbols(const char* text);

bool doesNotHaveConsecutiveBlankSymbols(const char* text);

bool arePunctiationMarksValid(const char* text);

bool areSentencesValid(const char* text);

bool areWordsValid(const char* text);

bool isInputValid(const char* input);

DictionaryPair* createDictionary(std::size_t n);

void deallocateDictionary(DictionaryPair* dictionary, std::size_t size);

int stricmp(const char* str1, const char* str2);

char toLower(char ch);

std::size_t minFrom(DictionaryPair* dictionary, std::size_t from, std::size_t to);

void sort(DictionaryPair* dictionary, std::size_t dictionarySize);

int binarySearch(const char* key, const DictionaryPair* dictionary, std::size_t left, std::size_t right);

char* encrypt(const char* text, DictionaryPair* dictionary, std::size_t dictionarySize);

int main ()
{
    std::ofstream problems("problems.txt");
    if (!problems)
    {
        std::cout << "Problem while opening the file\n";
        return 1;
    }

    problems << "The problems start here:" << std::endl;

    char* input = new (std::nothrow) char[MAX_TEXT_CAPACITY + 1];
    if (!input)
    {
        problems << "Problem while allocating memory for the input text\n";
        problems.close();
        return 1;
    }

    readInput(input);

    if (!isInputValid(input))
    {
        problems << "The input text is not valid\n";
        delete[] input;
        problems.close();
        return 1;
    }

    std::size_t n;
    std::cin >> n;

    DictionaryPair* dictionary = createDictionary(n);
    if (!dictionary)
    {
        problems << "Problem while creating the dictionary\n";
        delete[] input;
        problems.close();
        return 1;
    }

    char* encryptedInput = encrypt(input, dictionary, n);
    if (!encryptedInput)
    {
        problems << "Problem while encrypting the input\n";
        deallocateDictionary(dictionary, n);
        delete[] input;
        problems.close();
        return 1;
    }

    std::cout << encryptedInput;
    std::cout << "??" << std::endl; // we didn't save them in the input, so we add it now

    problems << "Kazano chestno - vsichko mi e nared!\n";

    delete[] encryptedInput;
    deallocateDictionary(dictionary, n);
    delete[] input;
    problems.close();

    return 0;
}

void readInput(char* input)
{
    std::size_t i = 0;
    while (true)
    {
        input[i] = std::cin.get();

        if (i >= 2 && input[i] == '?' && 
        input[i - 1] == '?' && input[i - 2] == '?')
        {
            break;
        }
        
        ++i;
    }
    input[i - 1] = '\0'; // we don't need the last two '?'
}

bool isLowerCase(char ch)
{
    return ch >= 'a' && ch <= 'z';
}

bool isUpperCase(char ch)
{
    return ch >= 'A' && ch <= 'Z';
}

bool isLetter(char ch)
{
    return isLowerCase(ch) || isUpperCase(ch);
}

bool isDigit(char ch)
{
    return ch >= '0' && ch <= '9';
}

bool isPartOfWord(char ch)
{
    return isLetter(ch) || isDigit(ch);
}

bool isBlank(char ch)
{
    return ch == ' ' || ch == '\n';
}

bool isSentenceEnding(char ch)
{
    return ch == '.' || ch == '!' || ch == '?';
}

bool isPunctuationMark(char ch)
{
    return ch == ',' || isSentenceEnding(ch);
}

bool containsValidSymbols(const char* text)
{
    while (*text)
    {
        if (!isLowerCase(*text) && !isUpperCase(*text) &&
        !isDigit(*text) && !isBlank(*text) && !isPunctuationMark(*text))
        {
            return false;
        }

        ++text;
    }

    return true;
}

bool doesNotHaveConsecutiveBlankSymbols(const char* text)
{
    for (std::size_t i = 1; text[i] != '\0'; ++i)
    {
        if (isBlank(text[i]) && isBlank(text[i - 1]))
        {
            return false;
        }
    }

    return true;
}

bool arePunctiationMarksValid(const char* text)
{
    std::size_t i;
    for (i = 0; text[i + 1] != '\0'; ++i)
    {
        if (isPunctuationMark(text[i]))
        {
            if (i == 0)
            {
                return false;
            }
            if (!isPartOfWord(text[i - 1]) || !isBlank(text[i + 1]))
            {
                return false;
            }
        }
    }

    return isLetter(text[i - 1]); // check for the last "?"
}

bool areSentencesValid(const char* text)
{
    if (!isUpperCase(text[0]))
    {
        return false;
    }

    for (std::size_t i = 0; text[i + 1] != '\0'; ++i)
    {
        if (isSentenceEnding(text[i]) && 
        (!isBlank(text[i + 1]) || !isUpperCase(text[i + 2])))
        {
            return false;
        }
    }

    return true;
}

bool areWordsValid(const char* text)
{
    for (std::size_t i = 1; text[i] != '\0'; ++i)
    {
        if (isUpperCase(text[i]) && isLowerCase(text[i - 1]))
        {
            return false;
        }
    }

    return true;
}

bool isInputValid(const char* input)
{
    return containsValidSymbols(input) &&
           doesNotHaveConsecutiveBlankSymbols(input) &&
           arePunctiationMarksValid(input) &&
           areSentencesValid(input) &&
           areWordsValid(input);
}

DictionaryPair* createDictionary(std::size_t n)
{
    DictionaryPair* dictionary = new (std::nothrow) DictionaryPair[n];
    if (!dictionary)
    {
        return nullptr;
    }

    char buffer[MAX_WORD_CAPACITY + 1], ch;
    for (std::size_t i = 0; i < n; ++i)
    {
        std::cin >> buffer >> ch;

        dictionary[i].word = new (std::nothrow) char[strlen(buffer) + 1];
        if (!isLetter(ch) || !dictionary[i].word)
        {
            deallocateDictionary(dictionary, i);
            return nullptr;
        }

        strcpy(dictionary[i].word, buffer);
        dictionary[i].replacement = ch;
    }

    return dictionary;
}

void deallocateDictionary(DictionaryPair* dictionary, std::size_t size)
{
    for (std::size_t i = 0; i < size; ++i)
    {
        delete[] dictionary[i].word;
    }

    delete[] dictionary;
}

char toLower(char ch)
{
    if (isUpperCase(ch))
    {
        ch += ('a' - 'A');
    }

    return ch;
}

int stricmp(const char* str1, const char* str2)
{
    if (!*str1 && !*str2)
    {
        return 0;
    }
    if (!*str1)
    {
        return -1; 
    }
    if (!*str2)
    {
        return 1;
    }

    if (toLower(*str1) != toLower(*str2))
    {
        return toLower(*str1) - toLower(*str2);
    }

    return stricmp(str1 + 1, str2 + 1);
}

std::size_t minFrom(DictionaryPair* dictionary, std::size_t from, std::size_t to)
{
    std::size_t minIndex = from;
    for (std::size_t i = from + 1; i < to; ++i)
    {
        if (stricmp(dictionary[i].word, dictionary[minIndex].word) < 0)
        {
            minIndex = i;
        }
    }

    return minIndex;
}

void sort(DictionaryPair* dictionary, std::size_t dictionarySize)
{
    for (std::size_t i = 0; i < dictionarySize - 1; ++i)
    {
        std::size_t min = minFrom(dictionary, i, dictionarySize);
        std::swap(dictionary[i], dictionary[min]);
    }
}

int binarySearch(const char* key, const DictionaryPair* dictionary, std::size_t left, std::size_t right)
{
    if (left >= right)
    {
        return -1;
    }

    int mid = (left + right) / 2;

    int comparison = stricmp(key, dictionary[mid].word);
    if (comparison == 0)
    {
        return mid;
    }
    else if (comparison < 0)
    {
        return binarySearch(key, dictionary, left, mid);
    }

    return binarySearch(key, dictionary, mid + 1, right);
}

char* encrypt(const char* text, DictionaryPair* dictionary, std::size_t dictionarySize)
{
    sort(dictionary, dictionarySize);

    char* tempResult = new (std::nothrow) char[MAX_TEXT_CAPACITY + 1];
    std::size_t resultIndex = 0;

    char temp[MAX_WORD_CAPACITY + 1];
    std::size_t tempIndex = 0;

    for (std::size_t i = 0; text[i] != '\0'; ++i)
    {
        tempIndex = 0;
        temp[0] = '\0';

        if (isPartOfWord(text[i]))
        {
            std::size_t start = i;
            std::size_t end = i;
            temp[tempIndex++] = text[end];
            temp[tempIndex] = '\0';

            bool replacementHappened = false;

            while (true)
            {
                int index = binarySearch(temp, dictionary, 0, dictionarySize);
                if (index >= 0)
                {
                    tempResult[resultIndex++] = dictionary[index].replacement;
                    replacementHappened = true;
                    break;
                }
                else
                {
                    ++end;
                    if (!isPartOfWord(text[end]))
                    {
                        tempResult[resultIndex++] = text[start];
                        break;
                    }
                    temp[tempIndex++] = text[end];
                    temp[tempIndex] = '\0';
                }
            }

            if (replacementHappened)
            {
                i = end;
            }
        }
        else
        {
            tempResult[resultIndex++] = text[i];
        }
    }

    tempResult[resultIndex] = '\0';

    char* result = new (std::nothrow) char[resultIndex + 1];
    if (!result)
    {
        delete[] tempResult;
        return nullptr;
    }
    strcpy(result, tempResult);

    delete[] tempResult;

    return result;
}