#include <iostream>

using std::cin;
using std::cout;
using std::boolalpha;

bool hasEqualFactorial(unsigned int x){

    unsigned int factorial = 1;
    for(unsigned int i = 2; factorial < x; i++) factorial *= i;
    return factorial == x;
    
}

int main(){

    unsigned int x;
    cin >> x;
    cout << boolalpha << hasEqualFactorial(x) << '\n';

}