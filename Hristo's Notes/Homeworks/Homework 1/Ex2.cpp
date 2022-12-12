#include <iostream>
using namespace std;

const unsigned numberOfDigitsInACode = 8;

void determineMarmalads(unsigned numberOfDigits);

int main(){

    unsigned numberOfDigits;
    cin >> numberOfDigits;

    determineMarmalads(numberOfDigits);

}

// Тази задача я разгледахме на допълнителното
void determineMarmalads(unsigned numberOfDigits){

    unsigned blueberry = 0, peach = 0, hip = 0;

    for(unsigned i = 0; i < numberOfDigits / numberOfDigitsInACode; i++){

        unsigned digit, type = 0;
        for(unsigned j = 0; j < numberOfDigitsInACode; j++){

            cin >> digit;
            // Check only the digits from 4th to 7th place inclusively e.g. the type of marmalad
            if(j > 2 && j < 7) type = type * 10 + digit;

        }

        if(type % 7 == 0) blueberry++;
        else if(type % 13 == 0) peach++;
        else if(type % 17 == 0) hip++;

    }

    cout << "Blueberry marmalad: " << blueberry << "\nPeach marmalad: " << peach << "\nHip marmalad: " << hip << '\n';

}