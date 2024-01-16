#include <iostream>
#include <cstddef>
#include <new>

void GenerateAllStrings(size_t const n, char * const str, size_t const index = 1){

    if(index == n){

        str[index] = '\0';
        std::cout << str << ' ';
        return;

    }

    str[index] = '0';
    GenerateAllStrings(n, str, index + 1);

    if(str[index - 1] == '0'){

        str[index] = '1';
        GenerateAllStrings(n, str, index + 1);

    }

}

int main(){

    size_t n;
    std::cin >> n;

    char *str = new(std::nothrow) char[n];
    if(!str){

        std::cout << "Memory error\n";
        return -1;

    }

    str[0] = '0';
    GenerateAllStrings(n, str);
 
    str[0] = '1';
    GenerateAllStrings(n, str);

    delete[] str;

    return 0;

}