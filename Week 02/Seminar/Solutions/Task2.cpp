#include <iostream>

int main(){

    int n, m;
    std::cin >> n >> m;

    // Начин с if - else
    if(n > m) std::cout << n << '\n';
    else std::cout << m << '\n';

    // Начин с тернарен оператор
    std::cout << (n > m ? n : m) << '\n';

}