#include <iostream>

int main(){
    int year, month, day;
    std::cout << "Enter year: " << std::endl;  //Enter year
    std::cin >> year;
    if( year > 2500 || year < 0)std::cout << "Invalid Date" << std::endl;  //Validate year
    else{  //Correct year
        std::cout << "Enter month: " << std::endl;  //Enter month
        std::cin >> month;
        if( month > 12 || month < 1)std::cout << "Invalid Date" << std::endl;  //Validate month
        else {  //Correct month
            std::cout << "Enter day: " << std::endl;  //Enter day
            std::cin >> day;
            int maxDaysInMonth = 0;
            bool isLeapYear=false;
            switch(month){  //Get the maximum days in a month
                case 1:
                case 3:
                case 5:
                case 7:
                case 8:
                case 10:
                case 12:maxDaysInMonth = 31;break;
                case 4:
                case 6:
                case 9:
                case 11:maxDaysInMonth=30;break;
                case 2:{
                    if( year % 400 == 0 || ( year % 4 == 0 && year % 100 != 0 ) ){  //Check if the year is leap year
                        maxDaysInMonth=29;
                        isLeapYear=true;
                    }
                    else{  //The year is not leap year
                        maxDaysInMonth = 28;
                        isLeapYear=false;
                    }
                }
            }
            if( day < 1 || day > maxDaysInMonth )std::cout << "Invalid Date" << std::endl;  //Validate day
            else {  //Correct day
                //--------------------------------Solution----------------------------------------
                std::cout << "The date is valid" << std::endl;
                //--------------------------------Solution----------------------------------------
               
            }
        }
    }
}