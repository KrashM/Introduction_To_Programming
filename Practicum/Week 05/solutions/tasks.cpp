#include <iostream>

// -----------Task 1-----------
int min(int a, int b)
{
    if (a < b) return a;
    else return b;
}

int max(int a, int b)
{
    if (a > b) return a;
    else return b;
}

int pow(int x, int y)
{
    int result = 1;
    for (int i = 1; i <= y; i++)
    {
        result *= x;
    }
    return result;
}

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}
// -----------Task 1-----------


//------ Bonus ------
double sqrt(double x) 
{
    double guess = x / 2.0;
    double prev_guess = 0.0;
    while (guess != prev_guess) {
        prev_guess = guess;
        guess = (guess + x / guess) / 2.0;
    }
    return guess;
}
//------ Bonus ------


// -----------Task 2-----------
bool isPrime(int x)
{
    if (x < 2) return false;

    bool prime = true;
    for (int i = 2; i * i <= x && prime; i++)
    {
        if (x % i == 0)
            prime = false;
    }
    return prime;
}

void printNPrimes(int n)
{
    int counter = 0;
    for (int i = 2; counter < n; i++)
    {
        if (isPrime(i))
        {
            std::cout << i << " ";
            counter++;
        }
    }
    std::cout << std::endl;
}

void printPrimeBreakdown(int x)
{
    int index = 2;
    while (x != 1)
    {
        if (x % index == 0)
        {
            std::cout << index << ' ';
            x /= index;
        }
        else
            index++;
    }
    std::cout << std::endl;
}
// -----------Task 2-----------

// -----------Task 3-----------
bool ascending(int x)
{
    bool asc = true;
    int lastDigit = 9;
    while (x != 0 && asc)
    {
        if (lastDigit >= x % 10)
            lastDigit = x % 10;
        else
            asc = false;
        x /= 10;
    }
    return asc;
}
// -----------Task 3-----------

// -----------Task 4-----------
int GCD(int a, int b)
{
    int biggestDivider = 1;
    for (int i = 2; i <= min(a, b); i++)
    {
        if (a % i == 0 && b % i == 0)
            biggestDivider = i;
    }
    return biggestDivider;
}
// -----------Task 4-----------

// -----------Task 5-----------
int LCM(int a, int b)
{
    return (a * b) / GCD(a, b);
}
// -----------Task 5-----------


// -----------Task 6-----------
long long append(int first, int second)
{
    // Alternative solution
    // int digits = 0;
    // long long temp = second;

    // while (temp != 0)
    // {
    //     digits++;
    //     temp /= 10;
    // }

    // return first * pow(10, digits) + second;    

    long long result = 0;
    long long step10 = 1;
    while (second != 0)
    {
        result += ( step10 * (second % 10) );
        second /= 10;
        step10 *= 10;
    }
    while (first != 0)
    {
        result += ( step10 * (first % 10) );
        first /= 10;
        step10 *= 10;
    }
    return result;
}
// -----------Task 6-----------

// -----------Task 7-----------
bool isLeapYear(int year)
{
    return year % 400 == 0 || (year % 4 == 0 && year % 100 != 0);
}

int getDaysInMonth(int year, int month)
{
    bool leapYear = isLeapYear(year);
    switch (month)
    { // Get the maximum days in a month
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12: return 31; break;

        case 4:
        case 6:
        case 9:
        case 11: return 30; break;

        case 2:{
            if (leapYear) return 29;
            else return 28;
        }
    }
}

bool validateYear(int year)
{
    return year <= 2500 && year >= 0;
}

bool validateMonth(int month)
{
    return month <= 12 && month >= 1;
}

bool validateDay(int year, int month, int day)
{
    return (day <= getDaysInMonth(year, month)) && (day > 0);
}

bool isDateValid(int year, int month, int day)
{
    if (!validateYear(year))
    {
        std::cout << "Invalid year" << std::endl;
        return false;
    }
    if (!validateMonth(month))
    {
        std::cout << "Invalid month" << std::endl;
        return false;
    }
    if (!validateDay(year, month, day))
    {
        std::cout << "Invalid day" << std::endl;
        return false;
    }
    return true;
}

void printDaySuffix(int day)
{
    switch (day)
    {
        case 1:
        case 21:
        case 31: std::cout << "st"; break;

        case 2:
        case 22: std::cout << "nd"; break;

        case 3:
        case 23: std::cout << "rd"; break;
        default: std::cout << "th"; break;
    }
}
void printMonth(int month)
{
    switch (month)
    { // Print the month name
    case 1: std::cout << "January"; break;
    case 2: std::cout << "February"; break;
    case 3: std::cout << "March"; break;
    case 4: std::cout << "April"; break;
    case 5: std::cout << "May"; break;
    case 6: std::cout << "June"; break;
    case 7: std::cout << "July"; break;
    case 8: std::cout << "August"; break;
    case 9: std::cout << "September"; break;
    case 10: std::cout << "October"; break;
    case 11: std::cout << "November"; break;
    case 12: std::cout << "December"; break;
    }
}
// -----------Task 7-----------

void task1()
{
    int a, b;
    std::cout << "Enter 2 numbers" << std::endl;
    std::cin >> a >> b;
    std::cout << "Min: " << min(a, b) << std::endl;
    std::cout << "Max: " << max(a, b) << std::endl;
    std::cout << a << "^" << b << " : " << pow(a, b) << std::endl;
    swap(a, b);
    std::cout << "The numbers have been swapped" << std::endl;
    std::cout << a << " " << b << std::endl;
}

void task2()
{
    int x;
    std::cout << "Enter a number" << std::endl;
    std::cin >> x;
    std::cout << "isPrime: " << std::boolalpha << isPrime(x) << std::endl;

    std::cout << std::endl << "Prime breakdown of " << x << std::endl;
    printPrimeBreakdown(x);

    std::cout << std::endl << "First 10 prime numbers" << std::endl;
    printNPrimes(10);
}

void task3()
{
    int x;
    std::cout << "Enter a number" << std::endl;
    std::cin >> x;
    std::cout << x << " is ascending: " << std::boolalpha << ascending(x) << std::endl;
}

void task4()
{
    int a, b;
    std::cout << "Enter 2 numbers" << std::endl;
    std::cin >> a >> b;
    std::cout << "GCD : " << GCD(a, b) << std::endl;
}

void task5()
{
    int a, b;
    std::cout << "Enter 2 numbers" << std::endl;
    std::cin >> a >> b;
    std::cout << "LCM : " << LCM(a, b) << std::endl;
}

void task6()
{
    int a, b;
    std::cout << "Enter 2 numbers in the range ( 0, INT_MAX ]" << std::endl;
    std::cin >> a >> b;
    if (a <= 0) return;
    if (b <= 0) return;
    std::cout << append(a, b) << std::endl;
}

void task7()
{
    int year, month, day;
    std::cout << "Enter a year in the range [ 0, 2500 ]: ";
    std::cin >> year;
    std::cout << "Enter month: ";
    std::cin >> month;
    std::cout << "Enter day: ";
    std::cin >> day;
    if (!isDateValid(year, month, day))
        return;

    std::cout << "Date is valid" << std::endl;
    //---------------Bonus-----------------------------
    if (isLeapYear(year))
        std::cout << "Leap year ";
        
    std::cout << day;
    printDaySuffix(day);
    std::cout << " ";

    printMonth(month);
    std::cout << " " << year << std::endl;
    //---------------Bonus-----------------------------
}

void taskSqrt()
{
    double x;
    std::cout << "Enter a number: ";
    std::cin >> x;
    std::cout << "sqrt(" << x << ") = " << sqrt(x) << std::endl;
}

void input()
{
    bool running = true;
    char task;
    while (running)
    {
        std::cout << "Select task 1-7: ";
        std::cin >> task;
        switch (task)
        {
            case '1': task1(); break;
            case '2': task2(); break;
            case '3': task3(); break;
            case '4': task4(); break;
            case '5': task5(); break;
            case '6': task6(); break;
            case '7': task7(); break;
            //---------------Bonus-----------------------------
            case 's': taskSqrt(); break;
            //---------------Bonus-----------------------------
            case 'e': running = false; break;
            default: std::cout << "Invalid input!" << std::endl; break;
        }
    }
}

int main()
{
    input();
}