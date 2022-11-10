#include <iostream>

bool isPalindrome(const char str[], const unsigned int size){

    for(unsigned int i = 0; i < size / 2; i++)
        if(str[i] != str[size - 1 - i]) return false;
    return true;

}

int main(){

    char str[] = "skjwiaonsse";
    std::cout << std::boolalpha << isPalindrome(str, sizeof(str) - 1) << '\n';

}