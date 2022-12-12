#include <iostream>
using namespace std;

int findSumInRange(int a, int b);

int main(){

    int a, b;

    cin >> a >> b;

    try{ cout << findSumInRange(a, b) << '\n'; }
    catch(const int e){ cout << e << '\n'; }

}

// Намирам колко цифри има n.
unsigned getLength(int n){

    unsigned powTen = 1, length = 1;
    while(powTen * 10 < n){ powTen *= 10; length++; }
    return length;

}

// Следващите две функции, проверяват дали всеки две последователни цифри са с различна четност.
bool isOddEven(int n, unsigned length){

    for(unsigned i = 0; i < length; i++){

        if(i % 2 == 0 && (n % 10) % 2 == 1) return false;
        if(i % 2 == 1 && (n % 10) % 2 == 0) return false;

        n /= 10;

    }

    return true;

}

bool isEvenOdd(int n, unsigned length){

    for(unsigned i = 0; i < length; i++){

        if(i % 2 == 0 && (n % 10) % 2 == 0) return false;
        if(i % 2 == 1 && (n % 10) % 2 == 1) return false;

        n /= 10;

    }
    
    return true;

}

int findSumInRange(int a, int b){

    if(b < a) throw -1;
    int sum = 0;
    for(int i = a; i <= b; i++){
        
        unsigned length = getLength(i);
        sum += (isEvenOdd(i, length) || isOddEven(i, length)) ? i : 0;
        
    }
    return sum;

}