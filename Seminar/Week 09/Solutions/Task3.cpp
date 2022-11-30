#include <iostream>

using std::cin;
using std::cout;
using std::size_t;

size_t romanToDecimal(const char symbol){

    if(symbol == 'I') return 1;
    if(symbol == 'V') return 5;
    if(symbol == 'X') return 10;
    if(symbol == 'L') return 50;
    if(symbol == 'C') return 100;
    if(symbol == 'D') return 500;
    if(symbol == 'M') return 1000;

    return 0;

}

size_t convertRomanNumberToDecimal(const char *string, const size_t &size){

    size_t result = 0, current, next;

    for(size_t i = 0; i < size - 1; ++i){

        current = romanToDecimal(string[i]);
        next = romanToDecimal(string[i + 1]);
        if(current < next) result -= current;
        else result += current;

    }

    result += romanToDecimal(string[size - 1]);

    return result;

}

int main(){

    size_t n;
    cin >> n;

    char *string = new char[n];
    cin >> string;

    cout << convertRomanNumberToDecimal(string, n) << '\n';

    delete[] string;

}