// Решението е по идея на Иван Димов от група 5.

#include <iostream>
#include <cstdlib>
#include <ctime>

size_t const HISTORY_CAPACITY = 50;
size_t const NUMBER_OF_DIGITS = 4;
unsigned const MAX_NUMBER = 9999;
unsigned const MIN_NUMBER = 1000;

bool IsNumberValid(unsigned number){

	if(number < MIN_NUMBER || number > MAX_NUMBER) return false;

	bool used[10] = { false, };

	while(number){

		if(used[number % 10]) return false;
		used[number % 10] = true;
		number /= 10;

	}

	return true;

}

unsigned GenerateNumber(){

	unsigned cpuNumber;

	do cpuNumber = MIN_NUMBER + (std::rand() % (MAX_NUMBER - MIN_NUMBER + 1));
	while (!IsNumberValid(cpuNumber));

	return cpuNumber;

}

void GetCowsAndBulls(unsigned number, unsigned guess, unsigned &cows, unsigned &bulls){

	cows = bulls = 0;
	unsigned numberDigits[NUMBER_OF_DIGITS], guessDigits[NUMBER_OF_DIGITS];
    size_t index = 0;

	while(number){

		numberDigits[index] = number % 10;
		guessDigits[index++] = guess % 10;
		number /= 10;
		guess /= 10;

	}

	for(size_t i = 0; i < NUMBER_OF_DIGITS; ++i){

		for(size_t j = 0; j < NUMBER_OF_DIGITS; ++j){

			if (numberDigits[i] == guessDigits[j]){

                bulls += i == j;
                cows += i != j;
				break;

			}

		}

	}

}

//			  CPU							You
//+------------------------+    +------------------------+
//| GUESSES | COWS | BULLS |	| GUESSES | COWS | BULLS |
//| ---------------------- |	| ---------------------- |
//|   1234  |  4   |   2   |	|   1234  |  4   |   2   |
//+------------------------+    +------------------------+
void PrintTable(size_t const index, unsigned const userGuesses[], unsigned const userCows[], unsigned const userBulls[], unsigned const cpuGuesses[], unsigned const cpuCows[], unsigned const cpuBulls[]){

	std::cout << "            CPU                           YOU\n";
	std::cout << "+------------------------+	+------------------------+\n";
	std::cout << "| GUESSES | COWS | BULLS |	| GUESSES | COWS | BULLS |\n";
	std::cout << "| ---------------------- |	| ---------------------- |\n";

	for(size_t i = 0; i <= index; ++i){

		std::cout << "|   " << cpuGuesses[i] << "  |  " << cpuCows[i] << "   |   " << cpuBulls[i] << "   |	|   ";
		std::cout << userGuesses[i] << "  |  " << userCows[i] << "   |   " << userBulls[i] << "   |\n";

		if(i != index) std::cout << "| ---------------------- |      | ---------------------- |\n";

	}

	std::cout << "+------------------------+      +------------------------+\n";

}

size_t GenerateArray(unsigned guess, unsigned cows, unsigned bulls, unsigned arr[], bool const easy){

	unsigned cowsTmp, bullsTmp;
    size_t index = 0;

	for(unsigned i = MIN_NUMBER; i <= MAX_NUMBER; ++i){

		if(!IsNumberValid(i)) continue;

        GetCowsAndBulls(i, guess, cowsTmp, bullsTmp);

        if (cowsTmp == cows && bullsTmp == bulls) arr[index++] = i;
        else if (!(i % 2) && easy) arr[index++] = i;

	}

	return index;

}

unsigned ChangeArrayBasedOnResult(unsigned const arr[], size_t const size, unsigned const guess, unsigned const cows, unsigned const bulls, unsigned newArr[], bool const easy){

	unsigned cowsTmp, bullsTmp;
    size_t index = 0;

	for(size_t i = 0; i < size; ++i){

		GetCowsAndBulls(arr[i], guess, cowsTmp, bullsTmp);

		if(cowsTmp == cows && bullsTmp == bulls) newArr[index++] = arr[i];
		else if(!(i % 2) && easy) newArr[index++] = arr[i];

	}

	return index;

}

bool ValidateBullsAndCows(unsigned const bulls, unsigned const cows){
	return cows + bulls <= NUMBER_OF_DIGITS;
}

int HasWonRound(unsigned const userBulls, unsigned const userCows, unsigned const computerBulls, unsigned const size){

	if(!ValidateBullsAndCows(userBulls, userCows)){

		std::cout << "Invalid number for bulls and cows, so I win this round";
		return -1;

	}
	if(!size){

		std::cout << "You cheated this round, so I win!";
		return -1;

	}
	if(userBulls == NUMBER_OF_DIGITS && computerBulls == NUMBER_OF_DIGITS) {

		std::cout << "We both guess so we tie";
		return 0;

	}
	if(computerBulls == NUMBER_OF_DIGITS){

		std::cout << "Urayyyyy, I won. Good luck next time";
		return -1;

	}
	if(userBulls == NUMBER_OF_DIGITS){

		std::cout << "Urayyyyy, You won";
		return 1;

	}

	return INT32_MIN;

}

unsigned GameLoop(unsigned const difficulty, unsigned const rounds){

	unsigned userGuessesHistory[HISTORY_CAPACITY], userCowsHistory[HISTORY_CAPACITY], userBullsHistory[HISTORY_CAPACITY], cpuGuessesHistory[HISTORY_CAPACITY], cpuCowsHistory[HISTORY_CAPACITY], cpuBullsHistory[HISTORY_CAPACITY];
    unsigned potentialNumbers[MAX_NUMBER - MIN_NUMBER], potentialNumbersNew[MAX_NUMBER - MIN_NUMBER];
	unsigned numberOfCowsInComputerNumber, numberOfBullsInComputerNumber, numberOfCowsInUserNumber, numberOfBullsInUserNumber;
	unsigned computerNumber, userGuess, computerGuess, counter = 0;
	unsigned cpuWins = 0, userWins = 0;
	bool medium = false, easy = false;
    size_t size;
	
    easy = difficulty == 2 && (medium = difficulty >= 1);

	while(cpuWins != rounds && userWins != rounds){

		if(!counter){

			computerGuess = GenerateNumber();
			computerNumber = GenerateNumber();

		}

		std::cout << "\nIt's my turn to guess: " << computerGuess << "\nCows: ";
		std::cin >> numberOfCowsInUserNumber;

		std::cout << "\nBulls: ";
		std::cin >> numberOfBullsInUserNumber;

		if(!counter) size = GenerateArray(computerGuess, numberOfCowsInUserNumber, numberOfBullsInUserNumber, potentialNumbers, medium || easy);
		else{

			size = ChangeArrayBasedOnResult(potentialNumbers, size, computerGuess, numberOfCowsInUserNumber, numberOfBullsInUserNumber, potentialNumbersNew, (easy || medium && counter < NUMBER_OF_DIGITS));
			for(size_t i = 0; i <= size; ++i) potentialNumbers[i] = potentialNumbersNew[i];

		}

		std::cout << "\nIt's your turn guess: ";
		std::cin >> userGuess;

		if(!IsNumberValid(userGuess)){

			std::cout << "The number is invalid, so your turn is skipped\n";
			numberOfBullsInComputerNumber = numberOfCowsInComputerNumber = 0;

		}

		GetCowsAndBulls(computerNumber, userGuess, numberOfCowsInComputerNumber, numberOfBullsInComputerNumber);
		std::cout << "\nCows: " << numberOfCowsInComputerNumber << " Bulls: " << numberOfBullsInComputerNumber << "\n";

		int result = HasWonRound(numberOfBullsInUserNumber, numberOfCowsInUserNumber, numberOfBullsInComputerNumber, size);

		if(result == INT32_MIN){

			if(size == 1) computerGuess = potentialNumbers[0];
			else computerGuess = potentialNumbers[std::rand() % size];

            userBullsHistory[counter] = numberOfBullsInComputerNumber;
            userCowsHistory[counter] = numberOfCowsInComputerNumber;
			userGuessesHistory[counter] = userGuess;

            cpuBullsHistory[counter] = numberOfBullsInUserNumber;
            cpuCowsHistory[counter] = numberOfCowsInUserNumber;
            cpuGuessesHistory[counter] = computerGuess;

			PrintTable(counter, userGuessesHistory, userCowsHistory, userBullsHistory, cpuGuessesHistory, cpuCowsHistory, cpuBullsHistory);

			++counter;

		}
		else{

			if(result == 1) ++userWins;
			else if(result == -1) ++cpuWins;

			counter = 0;

		}

	}

	return cpuWins;

}

int main(){

	std::srand(time(nullptr));

	unsigned difficulty, rounds;

	std::cout << "Choose difficulty:\n1. Easy\n2. Medium\n3. Hard\nType the number of the difficulty: ";
	std::cin >> difficulty;

	std::cout << "\nChoose number of rounds for one to win: ";
	std::cin >> rounds;

	if(difficulty < 1 || difficulty > 3){

		std::cout << "Not a valid number for difficulty";
		return -1;

	}

	unsigned const cpuWins = GameLoop(difficulty, rounds);

	if(cpuWins == rounds) std::cout << "I win this game, better luck next time";
    else std::cout << "You win this game, congratulations!!";

    return 0;

}