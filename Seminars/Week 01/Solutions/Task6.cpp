#include <iostream>
#include <cmath> // Библиотека за математически функции(abs, sqr, sqrt...)

int main(){

    int n, m;
    std::cin >> n >> m;

    std::cout << n + m << '\n';
    std::cout << abs(n - m) << '\n';
    std::cout << n % m << '\n';
    std::cout << n / m << '\n';
    std::cout << n * 1.0 / m << '\n';
    std::cout << floor(n * 1.0 / m) << '\n';
    std::cout << ceil(n * 1.0 / m) << '\n';
    std::cout << pow(n,2) + sqrt(m) << '\n';

}