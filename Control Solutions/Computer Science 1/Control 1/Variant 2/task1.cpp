#include <iostream>

void Swap(unsigned &a, unsigned &b){

    unsigned c = a;
    a = b;
    b = c;
    
}

int main(){

    unsigned a, b, c;
    std::cin >> a >> b >> c;

    if(!a || !b || !c){

        std::cout << "Invalid input\n";
        return -1;

    }

    if(a > b) Swap(a, b);
    if(b > c) Swap(b, c);
    if(a > b) Swap(a, b);

    std::cout << a << ' ' << b << ' ' << c << '\n';

    return 0;

}