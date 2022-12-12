#include <iostream>
using namespace std;

int findDifference(int a, int b);

int main(){

    int a, b;
    cin >> a >> b;

    try{ cout << findDifference(a, b) << '\n'; }
    catch(const int e){ cout << ((e == -1) ? "Bad input b is lesser than a!" : "No adjacent numbers!") << '\n'; }

}

bool numberIsAlternating(int n){

    char lastDigit;

    do
    {
        
        lastDigit = n % 10;
        n /= 10;
        if(n % 10 == lastDigit) return false;

    }while(n != 0);

    return true;
    

}

int findDifference(int a, int b){

    if(b < a) throw -1;

    int lowerNumber, upperNumber;
    bool lowerFlag = false, upperFlag = false;
    for(int i = a; i <= b; i++)
        if(numberIsAlternating(i)){
        
            lowerNumber = i;
            lowerFlag = true;
            break;
        
        }
    
    for(int i = b; i >= a; i--)
        if(numberIsAlternating(i)){

            upperNumber = i;
            upperFlag = true;
            break;

        }

    if(!(upperFlag && lowerFlag)) throw -2;
    
    return upperNumber - lowerNumber;

}