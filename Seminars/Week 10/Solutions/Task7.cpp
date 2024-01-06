#include <iostream>

const unsigned int MAX_SIZE = 1024;

void strcpy(char copied[], const char toBeCopied[], const unsigned int size){

    for(unsigned int i = 0; i < size; i++) copied[i] = toBeCopied[i];
    copied[size] = '\0';

}

void findLongestAndShortestWord(const char str[], const unsigned int size){

    unsigned int maxLen = 0, shortestLen = MAX_SIZE, currLen = 0;
    char longest[MAX_SIZE], shortest[MAX_SIZE], curr[MAX_SIZE];

    for(unsigned int i = 0; i < size; i++)
        if(str[i] == ' '){

            if(currLen < shortestLen){

                strcpy(shortest, curr, currLen);
                shortestLen = currLen;

            }
            
            if(currLen > maxLen){

                strcpy(longest, curr, currLen);
                maxLen = currLen;

            }

            currLen = 0;

        }
        else curr[currLen++] = str[i];

    std::cout << longest << ' ' << shortest << '\n';

}

int main(){

    char str[] = "Hello there my friends it's nice to meet you.";
    findLongestAndShortestWord(str, sizeof(str) - 1);

}