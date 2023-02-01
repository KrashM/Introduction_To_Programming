#include <iostream>
#include <cstring>

using std::cout;

bool isUppercase(const char &ch){
    return 'A' <= ch && ch <= 'Z';
}

void removeUpper(char *s){

    size_t diff = 0;
    for(size_t i = 0; i < strlen(s) + 1; ++i){

        while(isUppercase(s[i + diff])) ++diff;
        s[i] = s[i + diff];

    }

}

int main(){

    char str[] = "Hello World!";
    removeUpper(str);

    cout << str << '\n';

}