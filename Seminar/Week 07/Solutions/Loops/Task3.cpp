#include <iostream>

int main(){

    int n, m, handshakes = 0, hellos = 0;
    std::cin >> n >> m;

    for(int i = 0; i < n; i++) handshakes += i;
    for(int i = n; i < n + m; i++) hellos += 2 * i;

    std::cout << handshakes << ' ' << hellos << '\n';

}