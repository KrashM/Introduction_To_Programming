#include <iostream>

using std::cin;
using std::cout;

size_t strlen(const char str[]){

    size_t i = 0;
    while(str[i] != '\0') i++;    
    return i;

}

bool isUpper(const char &ch){
    return 'A' <= ch && ch <= 'Z';
}
bool isLower(const char &ch){
    return 'a' <= ch && ch <= 'z';
}

bool isLetter(const char &ch){
    return isLower(ch) || isUpper(ch);
}

int main(){

    char str[1024];
    cin.getline(str, 1024);

    size_t minWordIndex = 0;

    for(size_t i = 1; i < strlen(str); ++i)
        if(!isLetter(str[i - 1]) && isLetter(str[i]))
            for(size_t j = 0; j < strlen(str) - i; ++j)
                if(str[minWordIndex + j] > str[i + j] || isLetter(str[minWordIndex + j]) && !isLetter(str[i + j])) minWordIndex = i;
                else break;

    for(size_t i = minWordIndex; isLetter(str[i]); ++i) cout << str[i];
    cout << '\n';
    
}