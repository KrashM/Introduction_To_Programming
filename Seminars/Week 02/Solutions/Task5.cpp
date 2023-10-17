#include <iostream>

int main(){

    int r, x, y;
    std::cin >> r >> x >> y;

    int equation = x * x + y * y, distance = r * r;

    if(equation < distance){

        std::cout << "Inside" << std::endl;

    }
    else if(equation == distance){

        std::cout << "On the circle" << std::endl;

    }
    else std::cout << "Outside" << std::endl;

}