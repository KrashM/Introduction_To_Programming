#include <iostream>

using std::cin;
using std::cout;
using std::size_t;

#define MAX_SIZE 32

char getCharByNumber(const size_t &number){

	if(number <= 9) return '0' + number;
	if(10 <= number && number <= 35) return 'A' + (number - 10);
	return 'a' + (number - 36);

}

size_t getNumberByChar(const char &ch){

	if('0' <= ch && ch <= '9') return ch - '0';
	if('A' <= ch && ch <= 'Z') return 10 + ch - 'A';
	return 36 + ch - 'a';

}

void swap(char &a, char &b){

	char temp = a;
	a = b;
	b = temp;

}

size_t strlen(const char str[]){

    size_t i = 0;
    while(str[i] != '\0') i++;    
    return i;

}

void convertFromDecimal(size_t number, char result[], const size_t &k){

	size_t index = 0;

	while(number != 0){

		result[index++] = getCharByNumber(number % k);
		number /= k;

	}

    result[index] = '\0';

	for(size_t i = 0; i < index / 2; i++)
		swap(result[i], result[index - 1 - i]);

}

size_t convertToDecimal(const char number[], const size_t &k){

	size_t mult = 1, result = 0;
    const size_t size = strlen(number);

	for(int i = size - 1; i >= 0; i--){

		result += getNumberByChar(number[i]) * mult;
		mult *= k;

	}

	return result;

}

void convert(const char startingNumber[], char result[], const size_t &startingBase, const size_t &resultBase){

    convertFromDecimal(convertToDecimal(startingNumber, startingBase), result, resultBase);

}

int main(){

    char startingNumber[MAX_SIZE + 1], result[MAX_SIZE + 1];
    size_t baseOfStartingNumber, baseOfResult;

    cin >> startingNumber >> baseOfStartingNumber >> baseOfResult;

    convert(startingNumber, result, baseOfStartingNumber, baseOfResult);

    cout << result << '\n';

}