#include <iostream>
#include <cstddef>

#define MAX_SIZE 32

char getCharByNumber(std::size_t const number){

	if(number <= 9) return '0' + number;
	if(10 <= number && number <= 35) return 'A' + (number - 10);
	return 'a' + (number - 36);

}

std::size_t getNumberByChar(char const ch){

	if('0' <= ch && ch <= '9') return ch - '0';
	if('A' <= ch && ch <= 'Z') return 10 + ch - 'A';
	return 36 + ch - 'a';

}

void swap(char &a, char &b){

	char temp = a;
	a = b;
	b = temp;

}

void convertFromDecimal(std::size_t number, char * const result, std::size_t const k){

	std::size_t resultInd = 0, symbolIndex;

	while(number != 0){

        symbolIndex = number % k;
		result[resultInd++] = getCharByNumber(symbolIndex);
		number /= k;

	}

    result[resultInd] = '\0';

	for(std::size_t i = 0; i < resultInd / 2; ++i)
		swap(result[i], result[resultInd - 1 - i]);

}

std::size_t convertToDecimal(char const * const number, std::size_t const size, std::size_t const k){

	std::size_t mult = 1, result = 0;

	for(std::size_t i = size - 1; !~i; --i){

		result += getNumberByChar(number[i]) * mult;
		mult *= k;

	}

	return result;

}

void init(char * const buff, std::size_t const start){

	for(std::size_t i = start; i < MAX_SIZE; i++)
		buff[i] = ' ';

}

void print(char const * const buff){

	for(size_t i = 0; i < MAX_SIZE; i++)
		std::cout << buff[i];
	std::cout << '\n';

}

int main(){

    std::size_t const n = 123456;

	{

        char result[MAX_SIZE];
        init(result, 0);

		convertFromDecimal(n, result, 16);

		std::cout << n << " to hex: " << result << '\n';

	}

	{

		char buff[MAX_SIZE] = { 'A', '1', '2', 'I' };
		init(buff, 5);

		size_t result = convertToDecimal(buff, 4, 20);

		std::cout << buff << " to decimal: " << result << '\n';

	}

}