#include <iostream>

using std::cin;
using std::cout;

size_t strlen(const char str[]){

    size_t i = 0;
    while(str[i] != '\0') i++;
    return i;

}

size_t countSentences(const char str[]){

    const size_t len = strlen(str);
    size_t count = 0;
    for(size_t i = 0; i < len; i++)
        if(str[i] == '.' || str[i] == '!' || str[i] == '?') count++;
    return count;

}

int main(){

    const size_t SIZE = 255;
    char str[SIZE];
    cin.getline(str, SIZE);

    cout << countSentences(str) << '\n';

}