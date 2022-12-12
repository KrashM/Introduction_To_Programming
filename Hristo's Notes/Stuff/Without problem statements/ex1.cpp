#include <iostream>
#include <exception>
#include <cstring>

size_t numberOfDigits(const size_t &n){

    size_t digits = 1, powTen = 1;
    while((powTen *= 10) < n) digits++;
    return digits;

}

const char *itoa(const size_t &n){

    const size_t size = numberOfDigits(n);
    size_t powTen = 1;
    char *intString = new char[size + 1];
    intString[size] = '\0';
    for(size_t i = 0; i < size; i++){
        
        intString[size - i - 1] = '0' + (n / powTen) % 10;
        powTen *= 10;
    
    }

    return intString;

}

bool isValidFormat(const char *string){

    for(size_t i = 0; string[i] != '\0'; i++)
        if(string[i] >= '0' && string[i] <= '9') return false;
    return true;

}

void resize(char *string, size_t &size, const size_t &&places){

    char *temp = new char[size + places];
    for(size_t i = 0; i < size; i++)
        temp[i] = string[i];
    delete[] string;
    size += places;
    string = temp;

}

const char* RLE(const char *string){

    if(!isValidFormat(string)) throw std::invalid_argument("String is invalid");
    size_t size = 1, count = 1;
    char *newString = new char[size];
    newString[0] = '\0';
    
    for(size_t i = 0; string[i] != '\0'; i++){

        if(string[i] == string[i + 1]) count++;
        else{

            std::cout << string[i] << ' ' << count << '\n';

            const size_t digits = numberOfDigits(count);
            resize(newString, size, digits + 1);
            newString[size - digits - 2] = string[i];
            newString[size - digits - 1] = '\0';
            if(count > 1) strcat(newString, itoa(count));
            count = 1;

        }

    }

    return newString;

}

int main(){

    char *input = new char[1];
    std::cin >> input;

    std::cout << RLE(input) << '\n';

    delete[] input;

}