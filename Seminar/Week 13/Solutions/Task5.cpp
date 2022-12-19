#include <iostream>

using std::cin;
using std::cout;

size_t strlen(const char str[]){

    size_t i = 0;
    while(str[i] != '\0') i++;    
    return i;

}

long long convertToNumber(const char str[]){

    long long num = 0;

    for(size_t i = 0; i < strlen(str); ++i){

        num *= 10;
        num += str[i] - '0';

    }

    return num;

}

bool isPowerOfThree(const long long &num){

    long long powerThree = 1;
    while(num > powerThree) powerThree *= 3;
    return powerThree == num;

}

int main(){

    char str[1024];
    cin >> str;

    if(isPowerOfThree(convertToNumber(str))) cout << "Yes\n";
    else cout << "No\n";

}