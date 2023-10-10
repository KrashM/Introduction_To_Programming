#include <iostream>

int main(){

    int a = 34, b = 12;

    // Вариант с помощна променлива
    int temp;
    temp = a;
    a = b;
    b = temp;

    std::cout << a << ' ' << b << '\n';

    // Вариант с аритметични операции
    a += b;
    b = a - b;
    a -= b;

    std::cout << a << ' ' << b << '\n';

}