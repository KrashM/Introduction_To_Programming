#include <iostream>

int main(){

    int n, m, l, k;
    std::cin >> n >> m >> l >> k;

    int min = n;

    if(min > m) min = m;
    if(min > l) min = l;
    if(min > k) min = k;

    std::cout << n + m + l + k - min + 1 << std::endl;

}