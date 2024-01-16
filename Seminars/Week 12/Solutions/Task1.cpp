#include <iostream>

unsigned MinTiles(unsigned const n, unsigned const m){

    if(n == 0 || m == 0) return 0;
    if(n % 2 == 0 && m % 2 == 0) return MinTiles(n / 2, m / 2);
    if(n % 2 == 0 && m % 2 == 1) return (n + MinTiles(n / 2, m / 2));
    if(n % 2 == 1 && m % 2 == 0) return (m + MinTiles(n / 2, m / 2));
    return (n + m - 1 + MinTiles(n / 2, m / 2));

}

int main(){

    unsigned n, m;
    std::cin >> n >> m;

    std::cout << MinTiles(n, m) << '\n';

    return 0;

}