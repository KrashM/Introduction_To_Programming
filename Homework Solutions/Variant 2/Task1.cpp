#include <iostream>
#include <cstring>

using std::cin;
using std::cout;
using std::swap;

const size_t MAX_STRINGS = 50, MAX_LENGTH = 31;

void sort(char strings[][MAX_LENGTH], const size_t size){

    for(size_t i = 0; i < size - 1; ++i)
        for(size_t j = i + 1; j < size; ++j)
            if(strcasecmp(strings[i], strings[j]) > 0)
                swap(strings[i], strings[j]);

}

void logic(){

    char strings[MAX_STRINGS][MAX_LENGTH];

    size_t n;
    cin >> n;
    cin.ignore();

    if(n > 50){
        
        cout << "Size overflow\n";
        return;

    }

    for(size_t i = 0; i < n; ++i)
        cin.getline(strings[i], MAX_LENGTH);
    cout << "\n";
    
    sort(strings, n);

    for(size_t i = 0; i < n; ++i)
        cout << strings[i] << '\n';

}

int main(){
    logic();
}

/*
9
Hello World
Hello Alex
This is a veeery long sentence
it was a pleasure to burn
7 things you should learn NOW
In the beginning
the universe was created
In a hole in the ground
there lived a hobbit

*/