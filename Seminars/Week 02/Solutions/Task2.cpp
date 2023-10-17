#include <iostream>

int main(){

    int n, m;
    std::cin >> n >> m;

    // Начин с if - else
    if(n > m) std::cout << n << std::endl;
    else std::cout << m << std::endl;

    // Начин с тернарен оператор
    std::cout << (n > m ? n : m) << std::endl;

}