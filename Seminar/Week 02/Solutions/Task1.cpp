#include <iostream>

int main(){

    int n;
    std::cin >> n;

    switch(n){

        case 0:
            std::cout << "N is 0\n";
            break;
        case 1:
            std::cout << "N is 1\n";
            break;
        case 2:
            std::cout << "N is 2\n";
            break;
        case 3:
            std::cout << "N is 3\n";
            break;
        case 4:
            std::cout << "N is 4\n";
            break;
        case 5:
            std::cout << "N is 5\n";
            break;
        case 6:
            std::cout << "N is 6\n";
            break;
        case 7:
            std::cout << "N is 7\n";
            break;
        case 8:
            std::cout << "N is 8\n";
            break;
        case 9:
            std::cout << "N is 9\n";
            break;
        
        default:
            std::cout << "N is not a digit\n";
            break;

    }

}