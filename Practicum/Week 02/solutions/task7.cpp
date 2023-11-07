#include <iostream>

int main(){

    int day, month, year;
    std::cin >> year >> month >> day;

    if (month == 1 || month == 2) {

        month += 12;
        year -= 1;

    }

    int K = year % 100;
    int J = year / 100;
    int day_of_week = (day + 13 * (month + 1) / 5 + K + K / 4 + J / 4 - 2 * J) % 7;

    std::cout << "The day of the week for " << day << "/" << month << "/" << year << " is ";

    switch(day_of_week){

        case 0:
            std::cout << "Saturday\n";
            break;

        case 1:
            std::cout << "Sunday\n";
            break;

        case 2:
            std::cout << "Monday\n";
            break;

        case 3:
            std::cout << "Tuesday\n";
            break;

        case 4:
            std::cout << "Wednesday\n";
            break;

        case 5:
            std::cout << "Thursday\n";
            break;

        case 6:
            std::cout << "Friday\n";
            break;

    }

    return 0;

}