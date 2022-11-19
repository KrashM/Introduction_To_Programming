#include <iostream>

using std::cin;
using std::cout;

size_t strlen(const char str[]){

    size_t i = 0;
    while(str[i] != '\0') i++;
    return i;

}

bool isDigit(const char &c){
    return c >= '0' && c <= '9';
}

size_t countNumbers(const char str[]){

    const size_t len = strlen(str);
    size_t count = 0;
    for(size_t i = 0; i < len - 1; i++)
        if(isDigit(str[i]) && !isDigit(str[i + 1])) count++;
    return count + isDigit(str[len - 1]);

}

int main(){

    const size_t SIZE = 255;
    char str[SIZE];
    cin.getline(str, SIZE);

    cout << countNumbers(str) << '\n';

}