#include <iostream>
#include <cstddef>
#include <new>

size_t const CAPACITY = 1001;
size_t const VALUE_CAPACITY = 11;
size_t const LETTERS_COUNT = 26;

bool IsUpper(char const ch){
    return 'A' <= ch && ch <= 'Z';
}

bool IsLower(char const ch){
    return 'a' <= ch && ch <= 'z';
}

char ToLower(char const ch){
    if(IsUpper(ch)) return 'a' - 'A' + ch;
    return ch;
}

size_t Strlen(char const * const str){

    size_t size = 0;
    while(str[size]) ++size;
    return size;

}

void Strcpy(char *dest, char const *src){

    while(*src)
        *(dest++) = *(src++);
    *dest = '\0';

}

bool SubstrMatch(char const *str, char const *value){

    while(*str && *str == *value){

        ++str;
        ++value;

    }

    return !*value;

}

char *Encrypt(char const * const str, char const map[][VALUE_CAPACITY]){

    size_t size = 0;

    for(size_t i = 0; str[i]; ++i){

        char key = ToLower(str[i]) - 'a';
        size += *map[key] ? Strlen(map[key]) : 1;

    }

    char *result = new(std::nothrow) char[size + 1];
    if(!result) return nullptr;

    size_t index = 0;

    for(size_t i = 0; str[i]; ++i){

        char key = ToLower(str[i]) - 'a';

        if(*map[key])
            for(size_t k = 0; map[key][k]; ++k)
                result[index++] = map[key][k];
        else result[index++] = str[i];

    }

    result[index] = '\0';

    return result;

}

char *Decrypt(char const * const str, char const map[][VALUE_CAPACITY]){

    size_t size = 0;

    for(size_t i = 0; str[i]; ++i){

        size_t maxSize = 0;

        for(size_t j = 0; j < LETTERS_COUNT; ++j)
            if(*map[j] && SubstrMatch(str + i, map[j]))
                maxSize = std::max(maxSize, Strlen(map[j]) - 1);

        i += maxSize;
        ++size;

    }

    char *result = new(std::nothrow) char[size + 1];
    if(!result) return nullptr;

    size_t index = 0;

    for(size_t i = 0; str[i]; ++i){

        size_t maxIndex = SIZE_MAX, maxSize = 0;

        for(size_t j = 0; j < LETTERS_COUNT; ++j)
            if(*map[j] && SubstrMatch(str + i, map[j])){

                size_t length = Strlen(map[j]);

                if(length > maxSize){

                    maxSize = length;
                    maxIndex = j;

                }

            }
        
        if(maxIndex != SIZE_MAX){

            result[index++] = 'a' + maxIndex;
            i += Strlen(map[maxIndex]) - 1;

        }
        else result[index++] = str[i];


    }

    result[index] = '\0';

    return result;

}

int main(){

    size_t size;
    std::cin >> size;

    if(size > LETTERS_COUNT){

        std::cout << "Invalid input\n";
        return -1;

    }

    char map[LETTERS_COUNT][VALUE_CAPACITY] = {"", };
    char key;

    for(size_t i = 0; i < size; ++i){

        std::cin >> key;
        std::cin.ignore();

        if(!IsLower(key) && !IsUpper(key)){

            std::cout << "Invalid input\n";
            return -1;

        }

        key = ToLower(key) - 'a';

        std::cin.getline(map[key], VALUE_CAPACITY);

    }

    char str[CAPACITY];

    size_t n;
    std::cin >> n;
    std::cin.ignore();

    for(size_t i = 0; i < n; ++i){

        std::cin.getline(str, CAPACITY);

        char *result = Encrypt(str, map);
        if(result) std::cout << result << '\n';

        delete[] result;

    }

    std::cin >> n;
    std::cin.ignore();

    for(size_t i = 0; i < n; ++i){

        std::cin.getline(str, CAPACITY);

        char *result = Decrypt(str, map);
        if(result) std::cout << result << '\n';

        delete[] result;

    }

    return 0;

}

/*
8
i ala
l bala
d cana
e h
t disco
o electro
c pro
a some
1
I l0ve to code!
1
ala somem discoelectroelectro proelectroelectrobala!

8
i ala
l bala
d cana
e h
t disco
o electro
c pro
a some
1
hello world!
1
hhbalabalaelectro welectrorbalacana!
*/