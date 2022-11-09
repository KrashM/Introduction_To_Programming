#include <iostream>

int mod(const char num[], const int size, const int a){

    int res = 0;
    for(int i = 0; i < size; i++)
        res = (res * 10 + num[i] - '0') % a;
    return res;

}

int main(){

    char num[] = "12316767678678";
    std::cout << mod(num, sizeof(num) - 1, 10) << '\n';

}