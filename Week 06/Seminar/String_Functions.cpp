#include <iostream>

// Gives the lenght of the string
unsigned int strlen(const char str[]){

    unsigned int i = 0;
    while(str[i] != '\0') i++;    
    return i;

}

// Copies the second string into the first
void strcpy(char copied[], const char toBeCopied[]){

    const unsigned int len = strlen(toBeCopied);
    for(unsigned int i = 0; i < len; i++) copied[i] = toBeCopied[i];
    copied[len] = '\0';

}

// Compares first string to the second string: = -> 0; < -> -1; > -> 1
int strcmp(const char str1[], const char str2[]){

    const unsigned int len1 = strlen(str1), len2 = strlen(str2);

    if(len1 > len2) return 1;
    if(len1 < len2) return -1;

    for(unsigned int i = 0; i < len1; i++)
        if(str1[i] != str2[i]){

            if(str1[i] > str2[i]) return 1;
            return -1;

        }

    return 0;

}

// Concatenates the second string to the first string
void strcat(char str1[], const char str2[]){

    const unsigned int len1 = strlen(str1), len2 = strlen(str2);
    for(unsigned int i = 0; i < len2; i++) str1[len1 + i] = str2[i];
    str1[len1 + len2] = '\0';

}

int main(){

    // Define 3 strings
    char str1[255] = "Hello", str2[255] = " World", str3[255];

    // Get the lenght of str1 -> 5
    std::cout << strlen(str1) << '\n';

    // Copy str1 into str3 -> str3 = "Hello"
    strcpy(str3, str1);
    std::cout << str3 << '\n';

    str3[0] = 's';

    // Compare str1 and str3
    // "Hello" < "sello" -> -1
    std::cout << strcmp(str1, str3) << '\n';
    // "sello" > "Hello" -> 1
    std::cout << strcmp(str3, str1) << '\n';
    //  "Hello" = "Hello" -> 0
    std::cout << strcmp(str1, str1) << '\n';

    // Concatenate str2 to str1 -> str1 = "Hello World"
    strcat(str1, str2);
    std::cout << str1 << '\n';

}