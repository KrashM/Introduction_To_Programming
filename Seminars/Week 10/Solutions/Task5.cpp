#include <iostream>

void removeEmptySpaces(char str[], unsigned int &size){

    unsigned int readIndex, writeIndex;
    readIndex = writeIndex = 0;

    for(unsigned int i = 0; i < size; i++)
        if(str[i] == ' ') ++readIndex;
        else str[writeIndex++] = str[readIndex++];

    size -= readIndex - writeIndex;
    str[size] = '\0';
    

}

int main(){

    char str[] = "Hello there my friends it's nice to meet you.";
    unsigned int size = sizeof(str) - 1;
    removeEmptySpaces(str, size);
    std::cout << str << '\n';

}