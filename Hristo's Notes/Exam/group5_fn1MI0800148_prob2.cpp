#include <iostream>
#include <cstring>

using std::cin;
using std::cout;

bool wordsAreSame(char *input, int startIndex, char word[6]){

    for(int i = 0; word[i] != '\0'; i++){

        if(input[startIndex + i] == '\0')
            return false;
        if(word[i] != input[startIndex + i])
            return false;

    }

    return true;

}

int largestPowerOfTenThatFits(int n){

    int power = 1;
    while(power * 10 <= n) power *= 10;
    return power;

}

void calculateExpr(char *input, char values[12][6]){

    const int plus = 10;
    int result = 0, temp = 0;
    bool addOrSubtract = true;
    for(int i = 0; input[i] != '\0'; i++){

        bool flag = false;
        for(int j = 0; j < 12; j++){

            if(input[i] == values[j][0] && wordsAreSame(input, i, values[j])){

                flag = true;
                i += strlen(values[j]) - 1;
                if(j > 9){
                    
                    result += (addOrSubtract) ? temp : -temp;
                    addOrSubtract = (j == plus);
                    temp = 0;

                }
                else
                    temp = temp * 10 + j;
                break;

            }

        }

        if(!flag)
            throw -1;

    }

    result += (addOrSubtract) ? temp : -temp;

    int index = 0;
    if(result < 0){

        input[index] = '-';
        result *= -1;
        index = 1;

    }
    int powerOfTen = largestPowerOfTenThatFits(result);
    while(result > 0){

        input[index] = '0' + result / powerOfTen;
        result = result % powerOfTen;
        powerOfTen /= 10;
        index++;

    }
    input[index] = '\0';

}

int main(){

    char values[12][6] = {
        "zero",
        "one",
        "two",
        "three",
        "four",
        "five",
        "six",
        "seven",
        "eight",
        "nine",
        "plus",
        "minus"
    };
    char *input = new char[1];
    cin >> input;

    try{
        calculateExpr(input, values);
        cout << input << '\n';
    }
    catch(const int ex){
        cout << "Input was incorrect\n";
    }
    
    
}