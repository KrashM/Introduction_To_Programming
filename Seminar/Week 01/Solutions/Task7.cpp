#include <iostream>
using namespace std;

int main(){

    int a = 34, b = 12;

    // Вариант с помощна променлива
    int temp;
    temp = a;
    a = b;
    b = temp;

    cout << a << ' ' << b << '\n';

    // Вариант с аритметични операции
    a += b;
    b = a - b;
    a -= b;

    cout << a << ' ' << b << '\n';

}