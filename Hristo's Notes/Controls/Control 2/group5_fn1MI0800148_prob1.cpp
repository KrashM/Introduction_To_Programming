#include <iostream>
#include <cstring>

using std::cin;
using std::cout;

bool isDigit(char c){
    return c >= '0' && c <= '9';
}

bool isLetter(char c){
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

bool isValid(char c){
    return isLetter(c) || isDigit(c);
}

bool isBetterWord(char *sentence, int i, int j){
    
    if(i < 0) return j;
    int k;
    for(k = 0; sentence[i + k] == sentence[j + k]; k++);
    return sentence[i + k] > sentence[j + k];

}

char* minWord(char *sentence){

    int n = strlen(sentence), start = -1;
    bool newWord = true;
    for(int i = 0; i < n; i++){

        if(isValid(sentence[i])){

            if(newWord){

                if(isBetterWord(sentence, start, i)) start = i;
                newWord = false;

            }

        }
        else newWord = true;

    }

    for(int i = start; i < n; i++)
        sentence[i - start] = sentence[i];
    sentence[n - start] = '\0';

    return sentence;

}

void input(){

    char *sentence = new char[1];
    for(int i = 0; ; i++){

        sentence[i] = cin.get();
        if(sentence[i] == '\n'){

            sentence[i] = '\0';
            break;

        }

    }
    
    cout << minWord(sentence) << '\n';
    delete[] sentence;

}

int main(){

    input();

}

/*
me? why always me?
this sentence is false.
- What is C++? - A 37-year old programming language.
*/