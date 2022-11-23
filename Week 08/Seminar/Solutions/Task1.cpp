#include <iostream>

using std::cin;
using std::cout;
using std::size_t;

size_t countOnesInBinaryRepresentation(const size_t &n){

    size_t count = 0, validator = 1;
    while(validator <= n){
        
        count += ((n & validator) != 0);
        validator <<= 1;

    }
    return count;

}

int main(){

    int n;
    cin >> n;

    cout << countOnesInBinaryRepresentation(n) << '\n';

}