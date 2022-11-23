#include <iostream>

using std::cin;
using std::cout;
using std::size_t;
using std::boolalpha;

bool kIsPartOfN(const int &n, const int &k){

    if(k > n) return false;

    int mask = 1;

    while(mask < k){

        if(n & mask ^ k & mask) return false;
        mask <<= 1;

    }

    return true;

}

int main(){

    int n, k;
    cin >> n >> k;

    cout << boolalpha << kIsPartOfN(n, k) << '\n';

}