#include <iostream>

int main(){

    unsigned int n;
    std::cin >> n;

    if(n % 2 == 1){

        std::cout << "Weird" << std::endl;

    }
    else if(n >= 2 && n <= 5){

        std::cout << "Not weird" << std::endl;

    }
    else if(n >= 6 && n <= 20){

        std::cout << "Weird" << std::endl;

    }
    else if(n % 2 == 0 && n >= 20){

        std::cout << "Not weird" << std::endl;

    }

}