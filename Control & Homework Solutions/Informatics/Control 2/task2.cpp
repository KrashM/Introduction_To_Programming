#include <iostream>
#include <cstddef>

bool IsLetter(char const ch){
    return ('a' <= ch && ch <= 'z') || ('A' <= ch && ch <= 'Z');
}

bool IsDigit(char const ch){
    return '0' <= ch && ch <= '9';
}

bool IsWordCharacter(char const ch){
    return IsLetter(ch) || IsDigit(ch);
}

bool strcmp(char const *lhs, char const *rhs){

    while(*lhs == *rhs && IsWordCharacter(*lhs)){

        ++lhs;
        ++rhs;

    }

    if(!IsWordCharacter(*lhs) && !IsWordCharacter(*rhs)) return true;
    if(!IsWordCharacter(*lhs) && IsWordCharacter(*rhs) || *lhs < *rhs) return false;
    if(!IsWordCharacter(*rhs) && IsWordCharacter(*lhs) || *lhs > *rhs) return true;
    return true;

}

char const *FindNextWord(char const *str){

    while(*str && IsWordCharacter(*str)) ++str;
    while(*str && !IsWordCharacter(*str)) ++ str;
    return str;

}

char const *MinWord(char const * const str){

    char const *minWord = IsWordCharacter(*str) ? str : FindNextWord(str);
    char const *current = FindNextWord(minWord);

    while(*current){

        if(strcmp(minWord, current)) minWord = current;
        current = FindNextWord(current);

    }

    return minWord;

}

int main(){

    size_t const CAPACITY = 1024;
    char str[CAPACITY];
    std::cin.getline(str, CAPACITY);

    std::cout << MinWord(str) << '\n';
    return 0;

}

/*
me? why always me?
this sentence is false.
- What is C++? - A 37-year old programming language.
a cat is sleeping and purring on a chair.
*/