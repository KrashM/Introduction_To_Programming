#include <iostream>

int main(){

    int r, x, y;
    std::cin >> r >> x >> y;

    int equation = x * x + y * y, distance = r * r;

    if(equation < distance){

        std::cout << "Inside\n";

    }
    else if(equation == distance){

        std::cout << "On the circle\n";

    }
    else std::cout << "Outside\n";

}