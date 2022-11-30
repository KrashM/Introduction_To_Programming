#include <iostream>

void removeEmptySpaces(char str[], const unsigned int size){

    unsigned int newSize = size;
    for(unsigned int i = 0; i < size; i++)
        if(str[i] == ' '){

            for(unsigned int j = 0; j < size - i - 1; j++)
                str[i + j] = str[i + j + 1];
            newSize--;

        }
    str[newSize] = '\0';
    

}

int main(){

    char str[] = "Hello there my friends it's nice to meet you.";
    unsigned int size = sizeof(str) - 1;
    removeEmptySpaces(str, size);
    std::cout << str << '\n';

}