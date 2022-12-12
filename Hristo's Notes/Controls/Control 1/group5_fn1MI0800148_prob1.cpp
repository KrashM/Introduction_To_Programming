#include <iostream>
using namespace std;

bool canCotanateInTheMiddle(unsigned n, unsigned k);

int main(){

    unsigned n, k;
    cin >> n >> k;

    try{

        if(canCotanateInTheMiddle(n, k)) cout << "True\n";
        else cout << "False\n";

    }
    catch(const int e){ cout << e << '\n'; }

}

unsigned pow(unsigned n, unsigned power){ if(power == 0) return 1; if(power == 1) return n; return n * pow(n, power - 1); }

unsigned getNumberOfDigits(unsigned n){

    if(n == 0) return 1;

    unsigned digits = 0;
    while(n != 0){ digits++; n /= 10; }
    return digits;

}

bool canCotanateInTheMiddle(unsigned n, unsigned k){

    unsigned copyOfK = k, numberOfDigitsN = getNumberOfDigits(n), numberOfDigitsK = getNumberOfDigits(k);

    if(numberOfDigitsN - 2 < numberOfDigitsK) throw -1;

    unsigned powOfTenOfN = pow(10, numberOfDigitsN - 1), powOfTenOfK = pow(10, numberOfDigitsK - 1);

    
    n = n % powOfTenOfN;
    n /= 10;
    numberOfDigitsN -= 2;
    powOfTenOfN /= 100;

    unsigned currSubseqLength = 0;

    for(unsigned i = 0; i < numberOfDigitsN; i++){

        if(currSubseqLength == numberOfDigitsK) return true;

        if(n / powOfTenOfN % 10 == k / powOfTenOfK % 10) currSubseqLength++;
        else{
            
            currSubseqLength = 0;
            powOfTenOfK = pow(10, numberOfDigitsK);

        }

        powOfTenOfK /= 10;
        powOfTenOfN /= 10;

    }
    if(currSubseqLength == numberOfDigitsK) return true;

    return false;

}