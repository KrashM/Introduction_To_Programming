#include <iostream>

void printInfo(const char str[], const unsigned int size){

    unsigned int upper = 0, lower = 0, digits = 0;
    for(unsigned int i = 0; i < size; i++)
        if(str[i] >= 'A' && str[i] <= 'Z') upper++;
        else if(str[i] >= 'a' && str[i] <= 'z') lower++;
        else if(str[i] >= '0' && str[i] <= '9') digits++;
    
    std::cout << "Uppercase: " << upper << "; Lowercase: " << lower << "; Digits: " << digits << ";\n";

}

int main(){

    char str[] = "Aaab1Ba5Bab2b";
    printInfo(str, sizeof(str) - 1);

}