#include <iostream>

using std::cin;
using std::cout;
using std::size_t;
using std::boolalpha;

#define MAX_SIZE 1024

bool isDigit(const char &ch){
    return '0' <= ch && ch <= '9';
}

size_t strlen(const char *str){

    size_t i = 0;
    while(str[i] != '\0') i++;
    return i;

}

void validate(const char *str){

    for(size_t i = 0; i < strlen(str); ++i)
        if(!isDigit(str[i])) throw -1;

}

bool ed(const char *str){

    for(size_t i = 0; i < strlen(str); ++i)
        if((str[i] - '0') % 2 == 1)
            return false;

    return true;
    
}

int main(){

    char num[MAX_SIZE];
    cin >> num;

    try{
        validate(num);
    }
    catch(const int &ex){
        cout << "Input is invalid\n";
        return -1;
    }

    cout << boolalpha << ed(num) << '\n';
    
}