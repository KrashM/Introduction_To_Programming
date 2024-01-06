#include <iostream>
#include <cctype>

const unsigned int MAX_SIZE = 1024;

void flipCase(char str[]){

    for(unsigned int i = 0; str[i] != '\0'; i++)
        if(str[i] >= 'A' && str[i] <= 'Z') str[i] = std::tolower(str[i]);
        else if(str[i] >= 'a' && str[i] <= 'z') str[i] = std::toupper(str[i]);

}

int main(){

    char str[MAX_SIZE];
    std::cin >> str;
    flipCase(str);

    std::cout << str << '\n';

}