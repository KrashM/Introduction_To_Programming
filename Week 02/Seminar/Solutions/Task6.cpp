#include <iostream>

int main(){

    int hh, mm;
    std::cin >> hh >> mm;

    mm += 15;
    if(mm >= 60){

        hh++;
        mm -= 60;

    }
    if(hh == 24) hh -= 24;

    std::cout << (hh < 10 ? '0' : '\0') << hh << ':' << (mm < 10 ? '0' : '\0') << mm << '\n';

}