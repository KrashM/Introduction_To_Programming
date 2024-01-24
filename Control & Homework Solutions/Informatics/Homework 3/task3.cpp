#include <iostream>
#include <cstddef>
#include <new>

bool IsUpper(char const ch){
    return 'A' <= ch && ch <= 'Z';
}

char ToLower(char const ch){
    if(IsUpper(ch)) return 'a' - 'A' + ch;
    return ch;
}

bool IsWordCharacter(char const ch){
    return 'a' <= ch && ch <= 'z' || 'A' <= ch && ch <= 'Z' || ch == '-';
}

size_t WordLength(char const * const word){

    size_t size = 0;
    while(word[size] && IsWordCharacter(word[size])) ++size;
    return size;

}

void CopyWord(char *dest, char const *src){
    
    if(!dest || !src) return;

    while(*src && IsWordCharacter(*src)){

        *dest = ToLower(*src);
        ++dest;
        ++src;

    }

    *dest = '\0';

}

bool AreEqual(char const *str1, char const *str2){

    while(IsWordCharacter(*str1) && ToLower(*str1) == ToLower(*str2)){

        ++str1;
        ++str2;

    }

    return !IsWordCharacter(*str1) && !IsWordCharacter(*str2);

}

bool ResizeText(char *&text, size_t const size, size_t const newCapacity){

    char *temp = new(std::nothrow) char[newCapacity];
    if(!temp) return false;

    for(size_t i = 0; i < size; ++i) temp[i] = text[i];

    delete[] text;
    text = temp;

    return true;

}

bool IsInsideArrayOfWords(char **words, size_t const size, char const * const word){

    for(size_t i = 0; i < size; ++i)
        if(AreEqual(words[i], word)) return true;
    return false;

}

char const *GetNextWord(char const *text){

    while(IsWordCharacter(*text)) ++text;
    if(!*text) return text;
    while(!IsWordCharacter(*text)) ++text;
    return text;

}

void FreeWordsArray(char **words, size_t const size){

    for(size_t i = 0; i < size; ++i)
        delete[] words[i];
    delete[] words;

}

bool IsLexicographicallyBigger(char const *word1, char const *word2){

    while(*word1 == *word2){

        ++word1;
        ++word2;

    }

    return *word1 > *word2;

}

void SortWords(char **words, unsigned * const occurences, size_t const size){

    for(size_t i = 1; i < size; ++i){

        size_t j = 0;
        char *word = words[i];
        unsigned occurence = occurences[i];

        while(j < i && (occurences[i - j - 1] < occurence || occurences[i - j - 1] == occurence && IsLexicographicallyBigger(words[i - j - 1], word))){

            words[i - j] = words[i - j - 1];
            occurences[i - j] = occurences[i - j - 1];
            ++j;

        }

        words[i - j] = word;
        occurences[i - j] = occurence;

    }

}

char const *InputText(size_t &size, size_t &totalNumberOfWords){

    size_t capacity = 8;
    char *text = new(std::nothrow) char[capacity];
    bool startedWord = false;
    char ch;

    if(!text) return nullptr;

    totalNumberOfWords = size = 0;

    while((std::cin.get(ch)) && ch != '#'){

        totalNumberOfWords += startedWord && !IsWordCharacter(ch);
        startedWord = IsWordCharacter(ch);

        if(size == capacity && !ResizeText(text, size, capacity *= 2)){

            delete[] text;
            return nullptr;

        }

        text[size++] = ch;

    };

    totalNumberOfWords += startedWord;

    if(size == capacity && !ResizeText(text, size, capacity += 1)){

        delete[] text;
        return nullptr;

    }

    text[size++] = '\0';

    return text;

}

size_t CountUniqueWords(char const *text, size_t const totalNumberOfWords){

    size_t uniqueWords = 1;
    char const *currentWord = GetNextWord(text);

    for(size_t i = 1; i < totalNumberOfWords; ++i){

        char const *previousWord = text;
        bool unique = true;

        for(size_t j = 0; j < i; ++j){


            if(AreEqual(currentWord, previousWord)){

                unique = false;
                break;

            }

            previousWord = GetNextWord(previousWord);

        }
        
        uniqueWords += unique;
        currentWord = GetNextWord(currentWord);

    }

    return uniqueWords;

}

char **GenerateArrayOfUniqueWords(char const * const text, size_t const uniqueWords){

    char **words = new(std::nothrow) char *[uniqueWords];
    if(!words) return nullptr;

    char const *currentWord = text;
    for(size_t i = 0; i < uniqueWords; ++i){

        while(IsInsideArrayOfWords(words, i, currentWord)) currentWord = GetNextWord(currentWord);

        size_t currentWordLength = WordLength(currentWord);
        words[i] = new(std::nothrow) char[currentWordLength + 1];

        if(!words[i]){

            FreeWordsArray(words, i);
            return nullptr;

        }

        CopyWord(words[i], currentWord);
        currentWord = GetNextWord(currentWord);

    }

    return words;

}

unsigned *GenerateOccurenceArray(char const * const text, char **words, size_t const uniqueWords){

    unsigned *occurences = new(std::nothrow) unsigned[uniqueWords];
    if(!occurences) return nullptr;

    for(size_t i = 0; i < uniqueWords; ++i) occurences[i] = 0;
    for(size_t i = 0; i < uniqueWords; ++i){

        char const *currentWord = text;

        while(*currentWord){

            occurences[i] += AreEqual(currentWord, words[i]);
            currentWord = GetNextWord(currentWord);

        }

    }

    return occurences;

}

int main(){

    size_t size, totalNumberOfWords;

    char const *text = InputText(size, totalNumberOfWords);
    if(!text){

        std::cout << "Memory error\n";
        return -1;

    }

    size_t uniqueWords = CountUniqueWords(text, totalNumberOfWords);
    char **words = GenerateArrayOfUniqueWords(text, uniqueWords);    

    if(!words){

        std::cout << "Memory error\n";
        delete[] text;
        return -1;

    }

    unsigned *occurences = GenerateOccurenceArray(text, words, uniqueWords);

    if(!occurences){

        std::cout << "Memory error\n";
        FreeWordsArray(words, uniqueWords);
        delete[] text;
        return -1;

    }

    SortWords(words, occurences, uniqueWords);

    std::cout << "all words - " << totalNumberOfWords << '\n';
    std::cout << "distinct words - " << uniqueWords << '\n';

    for(size_t i = 0; i < uniqueWords; ++i)
        std::cout << words[i] << " - " << occurences[i] << '\n';

    delete[] text;
    delete[] occurences;
    FreeWordsArray(words, uniqueWords);

    return 0;

}

/*
Once upon a time there were three happy little pigs. The first little pig
played the flute, the second little pig played the violin and the third little
pig played the piano.#

ala2bala#
*/