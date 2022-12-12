#include <iostream>

using std::cin;
using std::cout;

int findValue(char *letters, int values[], char search, int n){

    int i;
    for(i = 0; letters[i] != search && i < n; i++);
    if(i == n) return 0;
    return values[i];

}

int calculate(char *expression, char *letters, int values[], int n){

    const char multiplicationChar = '.', additionChar = '+';
    int result = 0, tempSum = 0, numberOfAdders = 1;
    bool multiplication = false;

    for(int i = 0; expression[i] != '\0'; i++)
        if(expression[i] == additionChar)
            numberOfAdders++;

    int adders[numberOfAdders], index = 0;

    for(int i = 0; expression[i] != '\0'; i++){

        if(expression[i] == additionChar){

            adders[index] = tempSum;
            index++;
            tempSum = 0;

        }
        else if(expression[i] == multiplicationChar) multiplication = true;
        else if(multiplication){

            tempSum *= findValue(letters, values, expression[i], n);
            multiplication = false;

        }
        else tempSum += findValue(letters, values, expression[i], n);

    }

    adders[index] = tempSum;

    for(int i = 0; i < numberOfAdders; i++) result += adders[i];
    
    return result;
    
}

void input(){

    int n;
    cout << "Input n: ";
    cin >> n;

    int values[n];
    char *letters = new char[n], *expression = new char[1];

    for(int i = 0; i < n; i++){

        cout << "Input letter " << i + 1 << ": ";
        cin >> letters[i];
        cout << "Input value " << i + 1 << ": ";
        cin >> values[i];

    }

    cin >> expression;

    cout << calculate(expression, letters, values, n) << '\n';

}

int main(){

    input();

}

/*
4
b
5
c
3
a
2
d
42
a.b+b.c+d+a.c

6
d
3
e
2
h
3
l
1
o
5
r
10
h.e.l.l.o+w.o.r.l.d
*/