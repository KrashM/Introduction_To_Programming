#include <iostream>

char Relation(unsigned a, unsigned b){
    return a < b ? '<' : a > b ? '>' : '=';
}

int main(){

    unsigned a, b, c;
    std::cin >> a >> b >> c;

    if(!a || !b || !c){

        std::cout << "Invalid input\n";
        return -1;

    }

    std::cout << a << ' ' << Relation(a, b) << ' ' << b << ' ' << Relation(b, c) << ' ' << c << ' ' << Relation(c, a) << ' ' << a << '\n';

    return 0;

}