#include <iostream>
#include <math.h>

using std::cin;
using std::cout;
using std::sqrt;

bool isPrime(int n){

    for(int i = 2; i <= sqrt(n); i++){
        if(n % i == 0){
            return false;
        }
    }
    
    return true;

}

void printPairs(int n){

    for(int i = 2; i <= n / 2; i++){
        if(isPrime(i) && isPrime(n - i)){
            std::cout << i << ' ' << n - i << '\n';
        }
    }

}

int main(){

    int n;
    std::cin >> n;
    printPairs(n);

}