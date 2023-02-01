#include <iostream>
#include <cstring>

using std::cin;
using std::cout;
using std::swap;

bool isUppercase(const char &ch){
    return 'A' <= ch && ch <= 'Z';
}

void shake(char *s){

    size_t indexOfUppercase = 0, size = strlen(s);
    char temp;
    for(size_t i = 0; i < size; ++i)
        if(isUppercase(s[i])){

            temp = s[i];
            for(size_t j = i; j > indexOfUppercase; --j)
                s[j] = s[j - 1];
            s[indexOfUppercase++] = temp;

        }

}

int main(){

    char str[] = "Hello World!";
    shake(str);

    cout << str << '\n';

}