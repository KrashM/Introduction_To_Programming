#include <iostream>

unsigned int countRepeats(const char str[], const unsigned int size, const char c){

    unsigned int count = 0;
    for(unsigned int i = 0; i < size; i++)
        count += str[i] == c;
    return count;

}

int main(){

    char str[] = "ababbbccba", c;
    std::cin >> c;
    std::cout << countRepeats(str, sizeof(str) - 1, c) << '\n';

}