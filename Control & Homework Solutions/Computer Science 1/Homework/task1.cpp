#include <iostream>
#include <cstddef>
#include <cstring>

unsigned const FULL_HOUR = 10;
unsigned const HALF_HOUR = 5;

bool IsValidActivity(char const * const str){
    return (str[0] == 'h' && str[1] == 'w')
        || (str[0] == 'h' && str[1] == 'f')
        || (str[0] == 'h' && str[1] == 'm')
        || (str[0] == 's' && str[1] == 't');
}

bool Validate(char const * const str){

    size_t const length = strlen(str);
    if(length & 1) return false;

    for(size_t i = 0; i < length; i += 2)
        if(!IsValidActivity(str + i)) return false;

    return true;

}

unsigned CalculateTimeSpentForHomework(char const * const str){

    unsigned time = 0;

    for(size_t i = 0; str[i]; i += 2)
        if(str[i] == 'h' && str[i + 1] == 'w') time += FULL_HOUR;
        else if(str[i] == 's' && str[i + 1] == 't') time += HALF_HOUR;

    return time;

}

int main(){

    size_t const STRING_CAPACITY = 27, SIZE = 5;
    unsigned N, totalTime = 0;
    std::cin >> N;
    std::cin.ignore();

    char strings[SIZE][STRING_CAPACITY];

    for(size_t i = 0; i < SIZE; ++i){

        std::cin.getline(strings[i], STRING_CAPACITY);
        if(!Validate(strings[i])){

            std::cout << "Incorrect input!\n";
            return -1;

        }

    }

    for(size_t i = 0; i < SIZE; ++i)
        totalTime += CalculateTimeSpentForHomework(strings[i]);

    if(N * FULL_HOUR <= totalTime) std::cout << "You got it!\n";
    else std::cout << "You should work more\n";

    return 0;

}

/*
10
hwhwhwhfhfhfhfhmhmhfhmhmhm
stststststhfhfhfhfhfhfhfhf
sthmhmhmhmhwhwhfhfhfhfhfhf
ststhwhmhmhmhmhmhfhfhfhfhf
hfhfhfhfhfhfhfhfststhfhfhf
*/