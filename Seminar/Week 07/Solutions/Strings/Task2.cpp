#include <iostream>

int calcMaxValue(const char str[], const int size){

    int res = str[0] - '0';
 
    for(int i = 1; i < size; i++)
        if(str[i] == '0' || str[i] == '1' || res < 2 ) res += (str[i] - '0');
        else res *= (str[i]-'0');
 
    return res;

}

int main(){

    const char str[] = "01891";
    std::cout << calcMaxValue(str, sizeof(str) - 1) << '\n';
    
}