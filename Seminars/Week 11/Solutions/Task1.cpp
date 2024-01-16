#include <iostream>
#include <cstddef>

char FindFirstUppercase(char const * const str){

    if(*str == '\0') return '\0';
    if('A' <= *str && *str <= 'Z') return *str;
    return FindFirstUppercase(str + 1);

}

int main(){

    size_t const SIZE = 256;
    char str[SIZE];
    std::cin.getline(str, SIZE);

    std::cout << FindFirstUppercase(str) << '\n';

    return 0;

}