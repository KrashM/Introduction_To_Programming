#include <iostream>

using std::cin;
using std::cout;
using std::size_t;
using std::boolalpha;

bool bracketPairsAreClosed(const char *string, const size_t &size){

    int brackets = 0, curlyBrackets = 0, squareBrackets = 0;
    
    for(size_t i = 0; i < size; ++i){

        if(string[i] == '(') ++brackets;
        if(string[i] == ')') --brackets;
        if(string[i] == '[') ++squareBrackets;
        if(string[i] == ']') --squareBrackets;
        if(string[i] == '{') ++curlyBrackets;
        if(string[i] == '}') --curlyBrackets;

        if(brackets < 0 || squareBrackets < 0 || curlyBrackets < 0) return false;

    }

    return !brackets || !curlyBrackets || !squareBrackets;

}

int main(){

    size_t n;
    cin >> n;
    char *string = new char[n];
    cin >> string;

    cout << boolalpha << bracketPairsAreClosed(string, n) << '\n';

    delete[] string;

}