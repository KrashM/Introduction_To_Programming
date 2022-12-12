#include <iostream>
using namespace std;

unsigned f(unsigned x, unsigned index);

int main(){

    unsigned x;
    cin >> x;

    const unsigned fIndex = 35;

    cout << f(x, fIndex) << '\n';

}

// Тази задача я разгледахме на допълнителното
unsigned f(unsigned x, unsigned index){

    if(index == 1) return x;
    if(x % 2 == 0) return f(x / 2, --index);
    return f(3 * x + 1, --index);

}