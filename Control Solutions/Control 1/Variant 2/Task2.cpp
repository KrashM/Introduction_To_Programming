#include <iostream>

using std::cin;
using std::cout;

size_t firstGreaterFactorial(const size_t &x){

    size_t fact = 1, i = 2;
    while(fact < x) fact *= i++;
    return i - 1;

}

int main(){

    size_t x;
    cin >> x;
    cout << firstGreaterFactorial(x) << '\n';

}