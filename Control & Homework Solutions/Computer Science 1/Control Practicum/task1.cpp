#include <iostream>
#include <cstddef>
#include <new>

size_t Log10(size_t n){

    size_t result = 0;
    while(n){

        ++result;
        n /= 10;

    }

    return result;

}

bool IsLetter(char const ch){
    return ('a' <= ch && ch <= 'z') || ('A' <= ch && ch <= 'Z');
}

bool Validate(char const *str){

    while(*str){

        if(!IsLetter(*str)) return false;
        ++str;

    }

    return true;

}

void PutIntInsideStr(char *str, size_t const n){

    size_t powerOfTen = 1;

    while(n >= powerOfTen * 10) powerOfTen *= 10;

    while(powerOfTen){

        *str = '0' + n / powerOfTen % 10;
        powerOfTen /= 10;
        ++str;

    }

}

size_t FindSize(char const * const str){

    size_t size = 0, counter;

    while(str[size]){

        for(counter = 0; str[size] == str[size + counter]; ++counter);
        if(counter >= 4) counter = 3 + Log10(counter);
        size += counter;

    }

    return size;

}

char *RLECompress(char const * const str){

    size_t read = 0, write = 0;

    char *result = new(std::nothrow) char[FindSize(str) + 1];
    if(!result) return nullptr;

    while(str[read]){

        size_t counter = 0;

        while(str[read] == str[read + counter]) ++counter;

        if(counter >= 4){

            result[write++] = '(';
            PutIntInsideStr(result + write, counter);
            write += Log10(counter);
            result[write++] = str[read + counter - 1];
            result[write++] = ')';

        }
        else{

            for(size_t i = 0; i < counter; ++i)
                result[write++] = str[read];

        }

        read += counter;

    }

    result[write] = '\0';

    return result;

}

int main(){

    size_t const CAPACITY = 101;
    char str[CAPACITY];
    std::cin.getline(str, CAPACITY);

    if(!Validate(str)){

        std::cout << "Wrong input\n";
        return -1;

    }

    char *compressed = RLECompress(str);

    if(!compressed){

        std::cout << "Memory error\n";
        return -1;

    }

    std::cout << compressed << '\n';

    delete[] compressed;

    return 0;

}

/*
abcDDDDDaaaaaaabccadddd
*/