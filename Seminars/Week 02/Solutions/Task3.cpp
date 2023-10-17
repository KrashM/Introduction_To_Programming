#include <iostream>

int main(){

    int points;
    std::cin >> points;

    if(points > 85 && points <= 100){

        std::cout << "6" << std::endl;

    }
    else if(points > 70 && points <= 85){

        std::cout << "5" << std::endl;

    }
    else if(points > 50 && points <= 70){

        std::cout << "4" << std::endl;

    }
    else if(points > 30 && points <= 50){

        std::cout << "3" << std::endl;

    }
    else if(points > 0 && points <= 30){

        std::cout << "2" << std::endl;

    }
    else{

        std::cout << "Incorrect number of points!" << std::endl;

    }

}