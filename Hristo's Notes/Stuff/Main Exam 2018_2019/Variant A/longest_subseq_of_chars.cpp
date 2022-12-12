#include<iostream>

unsigned longestSequence(const char *s);

int main(){

    std :: string input;
    std :: getline(std :: cin, input);

    const char *s = input.c_str();

    unsigned lenght = longestSequence(s);
    std :: cout << lenght;

    return 0;

}

unsigned longestSequence(const char *s){

    unsigned longest_lenght = 0;
    unsigned cur_count = 1;

    char prev = *++s;

    while(*s){

        if(prev == *++s) cur_count++;
        else cur_count = 1;

        prev = *s;

        if(cur_count > longest_lenght) longest_lenght = cur_count;

    }

    return longest_lenght;

}