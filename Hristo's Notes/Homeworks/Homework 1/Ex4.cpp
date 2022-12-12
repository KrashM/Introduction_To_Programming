#include <iostream>
#include <time.h>
using namespace std;

const unsigned numberOfDigits = 4;

unsigned * generateNumber();
void bullsAndCows(unsigned *computersDigits, unsigned guess, unsigned &bulls, unsigned &cows);
void game(unsigned *computersDigits);

int main(){

    unsigned *computersDigits = generateNumber();

    try{ game(computersDigits); }
    catch(const int e){ cout << e << '\n'; }

}

// Обръща масива в число.
unsigned convertDigitsToNumber(unsigned *digits){

    unsigned number = 0;
    for(unsigned i = 0; i < numberOfDigits; i++) number = number * 10 + digits[i];

    return number;

}

// Проверяваме дали има такава цифра в числото.
int isDigitInsideNumber(unsigned *digits, unsigned numberOfSetDigits, unsigned digit){

    for(unsigned i = 0; i < numberOfSetDigits; i++) if(digit == digits[i]) return i;
    return -1;

}

// Генератор на случайно 4 цифрено число.
unsigned * generateNumber(){
    
    srand(time(NULL));
    static unsigned digits[numberOfDigits];

    for(unsigned i = 0; i < numberOfDigits; i++){

        // Generate digits until we find one that does not exist in generated number yet and then add it
        unsigned digit;
        do{ digit = (rand() % 9) + 1; }while(isDigitInsideNumber(digits, i, digit) != -1);
        digits[i] = digit;

    }

    return digits;
    
}

// Проверява колко бика и крави има.
void bullsAndCows(unsigned *computersDigits, unsigned guess, unsigned &bulls, unsigned &cows){

    // We start from the last digit going forward
    unsigned indexOfDigit = 3;
    while(guess != 0){

        // Check if the digit is inside the number to guess and return its index if it is in there or -1 if it is not
        int isCurrentDigitInNumber = isDigitInsideNumber(computersDigits, numberOfDigits, guess % 10);

        // If both indexes match it is a bull
        if(isCurrentDigitInNumber == indexOfDigit) bulls++;
        // If only the number is present but not on the same index then it is a cow
        else if(isCurrentDigitInNumber != -1) cows++;

        guess /= 10;
        indexOfDigit--;

    }

}

void game(unsigned *computersDigits){

    const unsigned attempts = 15;

    unsigned computersNumber = convertDigitsToNumber(computersDigits);

    for(unsigned i = 0; i < attempts; i++){

        unsigned guess;
        cin >> guess;

        if(guess < 1000 || guess > 9999) throw -1;

        if(guess == computersNumber){
            
            cout << "You win!\n";
            return;
            
        }

        unsigned bulls = 0, cows = 0;
        bullsAndCows(computersDigits, guess, bulls, cows);

        cout << "Bulls: " << bulls << "\nCows: " << cows << '\n';

    }

    cout << "You lost!\n";

}