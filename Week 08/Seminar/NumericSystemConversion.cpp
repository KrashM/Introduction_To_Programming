#include <iostream>

using std::cin;
using std::cout;
using std::size_t;

#define MAX_SIZE 32

char getCharByNumber(const size_t &number){

	if(number <= 9) return '0' + number;
	if(10 <= number && number <= 35) return 'A' + (number - 10);
	else return 'a' + (number - 36);

}

size_t getNumberByChar(const char &ch){

	if('0' <= ch && ch <= '9') return ch - '0';
	if('A' <= ch && ch <= 'Z') return 10 + ch - 'A';
	else return 36 + ch - 'a';

}

void swap(char& a, char& b){

	char temp = a;
	a = b;
	b = temp;

}

void convertFromDecimal(size_t number, char result[], const size_t &k){

	size_t resultInd = 0, symbolIndex;

	while(number != 0){

        symbolIndex = number % k;
		result[resultInd++] = getCharByNumber(symbolIndex);
		number /= k;

	}

    result[resultInd] = '\0';

	for(size_t i = 0; i < resultInd / 2; i++)
		swap(result[i], result[resultInd - 1 - i]);

}

size_t convertToDecimal(const char number[], const size_t &size, const size_t &k){

	size_t mult = 1, result = 0;

	for(int i = size - 1; i >= 0; i--){

		result += getNumberByChar(number[i]) * mult;
		mult *= k;

	}

	return result;

}

void init(char buff[], const size_t &start){

	for(size_t i = start; i < MAX_SIZE; i++)
		buff[i] = ' ';

}

void print(const char buff[]){

	for(size_t i = 0; i < MAX_SIZE; i++)
		cout << buff[i];
	cout << '\n';

}

int main(){

    const size_t n = 123456;

	{

        char result[MAX_SIZE];
        init(result, 0);

		convertFromDecimal(n, result, 16);

		cout << n << " to hex: " << result << '\n';

	}

	{

		char buff[MAX_SIZE] = { 'A', '1', '2', 'I' };
		init(buff, 5);

		size_t result = convertToDecimal(buff, 4, 20);

		cout << buff << " to decimal: " << result << '\n';

	}

}