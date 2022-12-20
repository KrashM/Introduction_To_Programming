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

bool leq(const char *num1, const char *num2){

    const size_t len1 = strlen(num1), len2 = strlen(num2);
    if(len1 != len2) return len1 < len2;

    for(size_t i = 0; i < len1; ++i)
        if(num1[i] != num2[i])
            return num1[i] < num2[i];
    
    return true;

}

int main(){

    char num1[MAX_SIZE], num2[MAX_SIZE];
    cin >> num1 >> num2;

    try{
        validate(num1);
        validate(num2);
    }
    catch(const int &ex){
        cout << "Input is invalid\n";
        return -1;
    }

    cout << boolalpha << leq(num1, num2) << '\n';

}