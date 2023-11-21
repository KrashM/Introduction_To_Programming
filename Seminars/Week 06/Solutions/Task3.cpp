#include <iostream>

int min(const int a, const int b){
    return (a < b) ? a : b;
}

int gcd(const int a, const int b){

    int result = min(a, b);
    while(result > 0){

        if(a % result == 0 && b % result == 0) break;
        result--;
    
    }
    
    return result;

}

int main(){

    const unsigned int SIZE = 4;
    int arr[SIZE] = {9, 18, 27, 15};
    int greatestCommonDenominator = gcd(arr[0], arr[1]);

    for(unsigned int i = 2; i < SIZE; i++)
        greatestCommonDenominator = gcd(greatestCommonDenominator, arr[i]);

    std::cout << greatestCommonDenominator << '\n';

}