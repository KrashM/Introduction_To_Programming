#include <iostream>

using std::cin;
using std::cout;
using std::size_t;

void swap(char &a, char &b){

    char temp = a;
    a = b;
    b = temp;

}

int main(){

    size_t n;
    cin >> n;

    char *string = new char[n + 1];
    cin >> string;
    
    for(size_t i = 0; i < n / 2; ++i) swap(string[i], string[n - i - 1]);

    cout << string << '\n';

    delete[] string;

}