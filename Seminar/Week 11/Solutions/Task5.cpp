#include <iostream>

using std::cin;
using std::cout;
using std::size_t;

unsigned int minTiles(const unsigned int &n, const unsigned int &m){

    if(n == 0 || m == 0) return 0;
    if(n % 2 == 0 && m % 2 == 0) return minTiles(n / 2, m / 2);
    if(n % 2 == 0 && m % 2 == 1) return (n + minTiles(n / 2, m / 2));
    if(n % 2 == 1 && m % 2 == 0) return (m + minTiles(n / 2, m / 2));
    return (n + m - 1 + minTiles(n / 2, m / 2));

}

int main(){

    unsigned int n, m;
    cin >> n >> m;

    cout << minTiles(n, m) << '\n';

}