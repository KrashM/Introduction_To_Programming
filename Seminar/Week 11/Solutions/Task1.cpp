#include <iostream>

using std::cin;
using std::cout;
using std::size_t;

char findFirstUppercase(const char *str){

    if(*str == '\0') return '\0';
    if(*str >= 'A' && *str <= 'Z') return *str;
    return findFirstUppercase(str + 1);

}

int main(){

    const size_t SIZE = 255;
    char str[SIZE];
    cin.getline(str, SIZE);

    cout << findFirstUppercase(str) << '\n';

}