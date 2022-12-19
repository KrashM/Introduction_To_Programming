#include <iostream>

using std::cin;
using std::cout;
using std::swap;

bool isUppercase(const char &ch){
    return 'A' <= ch && ch <= 'Z';
}

size_t strlen(const char str[]){

    size_t i = 0;
    while(str[i] != '\0') i++;
    return i;

}

void bubbeSort(char str[], const size_t &n){

    for(size_t i = 0; i < n - 1; ++i)
        for(size_t j = i + 1; j < n; ++j)
            if(str[i] > str[j])
                swap(str[i], str[j]);

}

int main(){

    char str[1024];
    cin >> str;

    bubbeSort(str, strlen(str));

    for(size_t i = 0; i < strlen(str); ++i){

        if(isUppercase(str[i])) continue;
        cout << str[i];

    }
    
}