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
                

                //--------------------------------Bonus----------------------------------------
                if(isLeapYear) std::cout << "Leap year " ; //If it is a leap year print it
                
                if( day < 10 ){ //if day is < 10 print a zero before the day
                    std::cout << '0' ; 
                }
                std::cout << day ;
                if ( day == 11 || day == 12 || day == 13){
                    std::cout << "th"; //If the day is 11,12 or 13 print "th"
                }
                else{
                    switch ( day % 10 ){  //Print day suffix
                        case 1: std::cout << "st" ; break;
                        case 2: std::cout << "nd" ; break;
                        case 3: std::cout << "rd" ; break;
                        default: std::cout << "th" ; break;    
                    }   
                }
                std::cout<<' ';  //Print space
                switch ( month ){  //Print the month name 
                    case 1: std::cout << "January" ; break;
                    case 2: std::cout << "February" ; break;
                    case 3: std::cout << "March" ; break;
                    case 4: std::cout << "April" ; break;
                    case 5: std::cout << "May" ; break;
                    case 6: std::cout << "June" ; break;
                    case 7: std::cout << "July" ; break;
                    case 8: std::cout << "August" ; break;
                    case 9: std::cout << "September" ; break;
                    case 10: std::cout << "October" ; break;
                    case 11: std::cout << "November" ; break;
                    case 12: std::cout << "December" ; break;
                }
                std::cout << ' ' << year << std::endl;  //Print space and the year
                //--------------------------------Bonus----------------------------------------
            }
        }
    }
}