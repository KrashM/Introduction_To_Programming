#include <iostream>
#include <cstring>

using std::cin;
using std::cout;

void shrink(char* &number, int &size){

    int index = 0;
    while(number[index] == '0') index++;

    int newSize = strlen(number) - index;

    char *copy = new char[newSize];
    for(int i = 0; i < newSize; i++)
        copy[i] = number[index + i];
    copy[newSize] = '\0';
    delete[] number;
    number = copy;
    size = newSize;

}

void addition(){

    char *number = new char[100];
    cin >> number;

    bool isFirst = true;
    int size = strlen(number), counter = 0;
    
    while(size > 0 && number[0] > 0){

        char *adding = new char[size];
        adding[size] = '\0';
        int index = size - 1;

        while(index >= 0){

            if(number[index] != '0'){

                adding[index] = '1';
                number[index]--;

            }
            else adding[index] = '0';

            index--;

        }

        if(isFirst){

            cout << adding;
            isFirst = false;

        }
        else cout << " + " << adding;

        shrink(number, size);

    }
    cout << '\n';

}

int main(){

    addition();

}