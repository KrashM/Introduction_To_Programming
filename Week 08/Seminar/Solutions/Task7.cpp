#include <iostream>
#include <cstring>

using std::cin;
using std::cout;
using std::size_t;

// Максималните капацитети за бинарно и шеснайсетично число
#define MAX_SIZE_BINARY 32
#define MAX_SIZE_HEX 10

size_t pow(const size_t &n, const size_t &pow){

    size_t result = 1;
    for(size_t i = 0; i < pow; i++) result *= n;
    return result;

}

// Взимаме цифра в шеснайсетична и го правим в десетична
size_t convertHexDigitToDecimal(const char &decimal){

    if(decimal >= 'A' && 'F' >= decimal) return 10 + decimal - 'A';
    return decimal - '0';

}

// Взимаме цифра от десетична и го правим в шеснайсетична
char convertDecimalDigitToHex(const size_t &decimal){

    if(decimal < 10) return '0' + decimal;
    return 'A' + decimal - 10;

}

// Превръщаме число от десетична в шеснайсетична
void convertDecimalToHex(size_t n, char result[]){

    // Почваме да го пълним отзад напред
    size_t index = MAX_SIZE_HEX - 1;
    while(n != 0){

        result[index--] = convertDecimalDigitToHex(n % 16);
        n /= 16;

    }

    // Подравняваме числото, за да нямаме водещи нули
    for(size_t i = 0; i < MAX_SIZE_HEX - index; i++) result[i + 2] = result[index + i + 1];

    // Форматиране за шеснайсетичните числа
    result[0] = '0';
    result[1] = 'x';
    result[MAX_SIZE_HEX - index + 2] = '\0';

}

// Превръщаме число от десетична в шеснайсетична
void convertDecimalToBinary(size_t n, char result[]){

    // Почваме да го пълним отзад напред
    size_t index = MAX_SIZE_BINARY - 1;
    while(n != 0){

        result[index--] = '0' + n % 2;
        n /= 2;

    }

    // Подравняваме числото, за да нямаме водещи нули
    for(size_t i = 0; i < MAX_SIZE_BINARY - index; i++) result[i] = result[index + i + 1];

    result[MAX_SIZE_BINARY - index] = '\0';

}

// Превръща число от шеснайсетична в десетична
size_t convertHexToDecimal(const char number[]){

    const size_t len = strlen(number);
    size_t result = 0;
    for(size_t i = 2; i < len; i++)
        result += pow(16, len - i - 1) * convertHexDigitToDecimal(number[i]);
    return result;

}

// Превръща число от двоична в десетична
size_t convertBinaryToDecimal(const char number[]){

    const size_t len = strlen(number);
    size_t result = 0;
    for(size_t i = 0; i < len; i++)
        result += pow(2, len - i - 1) * (number[i] - '0');
    return result;

}

int main(){

    char hexNumber[MAX_SIZE_HEX + 1], binaryNumber[MAX_SIZE_BINARY + 1];
    cin >> hexNumber >> binaryNumber;
    
    // Намираме резултатът в десетична бройна система
    size_t result = convertHexToDecimal(hexNumber) - convertBinaryToDecimal(binaryNumber);
    
    // Конвертираме резултатът в шеснайсетична и двоична бройна система
    convertDecimalToHex(result, hexNumber);
    convertDecimalToBinary(result, binaryNumber);
    
    cout << hexNumber << '\n';
    cout << result << '\n';
    cout << binaryNumber << '\n';

}