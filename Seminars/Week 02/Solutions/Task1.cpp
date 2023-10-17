#include <iostream>

int main(){

    int n;
    std::cin >> n;

    switch(n){

        case 0:
            std::cout << "N is 0" << std::endl;
            break;
        case 1:
            std::cout << "N is 1" << std::endl;
            break;
        case 2:
            std::cout << "N is 2" << std::endl;
            break;
        case 3:
            std::cout << "N is 3" << std::endl;
            break;
        case 4:
            std::cout << "N is 4" << std::endl;
            break;
        case 5:
            std::cout << "N is 5" << std::endl;
            break;
        case 6:
            std::cout << "N is 6" << std::endl;
            break;
        case 7:
            std::cout << "N is 7" << std::endl;
            break;
        case 8:
            std::cout << "N is 8" << std::endl;
            break;
        case 9:
            std::cout << "N is 9" << std::endl;
            break;
        
        default:
            std::cout << "N is not a digit" << std::endl;
            break;

    }

}