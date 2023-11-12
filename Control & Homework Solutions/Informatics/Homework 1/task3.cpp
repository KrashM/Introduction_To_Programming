#include <iostream>

bool IsLeapYear(const unsigned short year)
{
    return year % 4 == 0 && (year % 100 != 0 || year % 400 == 0);
}

bool ValidDate(const unsigned short day, const unsigned short month, const unsigned short year)
{
    if(month > 12)
    {
        return false;
    }

    switch(month)
    {
        case 1: case 3: case 5: case 7: case 8: case 10: case 12: 
        {
            if(day == 0 || day > 31)
            {
                return false;
            }
        } break;
        case 4: case 6: case 9: case 11: 
        {
            if(day == 0 || day > 30)
            {
                return false;
            }
        } break;
        case 2:  
        {
            if(day == 0 || day > 29)
            {
                return false;
            }
            if(!IsLeapYear(year) && day == 29)
            {
                return false;
            }
        } break;
    }
    return true;
}

bool Suitable(const unsigned short currDay, const unsigned short currMonth, const unsigned short currYear,
              const unsigned short day,     const unsigned short month,     const unsigned short year)
{
    if(currYear > year || (currYear == year && currMonth > month) || (currMonth == month && currDay > day))
    {
        return false;
    }
    return true;
}

bool OddNumberOfOnes(unsigned int num)
{
    num ^= num >> 16;
    num ^= num >> 8;
    num ^= num >> 4;
    num ^= num >> 2;
    num ^= num >> 1;
    return num & 1;
}

void ProcessLeapYear(unsigned short& year, unsigned short& daysToAdd)
{
    if(daysToAdd <= 365) return;

    int temp = daysToAdd / 1461; // 1461 = 366 + 3 * 365
        
    if(temp > 0) 
    {
        daysToAdd -= temp * 366;
        daysToAdd -= temp * 3 * 365;

        year += 4 * temp;
    }
    else
    {
        daysToAdd -= 366;
        year += 1;
    }

    temp = daysToAdd / 365;
    daysToAdd -= temp * 365;
    year += temp;

}

void CorrectYear(unsigned short& year, unsigned short& daysToAdd)
{
    if(IsLeapYear(year))
    {
        ProcessLeapYear(year, daysToAdd);
    }
    else if(IsLeapYear(year + 1))
    {
        daysToAdd -= 365;
        year += 1;

        ProcessLeapYear(year, daysToAdd);
    }
    else if(IsLeapYear(year + 2))
    {
        daysToAdd -= 365;
        year += 1;

        if(daysToAdd <= 365) return;

        daysToAdd -= 365;
        year += 1;
        
        ProcessLeapYear(year, daysToAdd);
    }
    else if(IsLeapYear(year + 3))
    {
        daysToAdd -= 365;
        year += 1;

        if(daysToAdd <= 365) return;

        daysToAdd -= 365;
        year += 1;

        if(daysToAdd <= 365) return;

        daysToAdd -= 365;
        year += 1;
        
        ProcessLeapYear(year, daysToAdd);
    }
}

void CorrectDate(unsigned short& day, unsigned short& month, unsigned short& year)
{
    switch(month)
    {
        case 1: case 3: case 5: case 7: case 8: case 10: case 12: 
        {
            if(day > 31)
            {
                day -= 31;
                month++;

                if(month == 13)
                {
                    year++;
                    month = 1;
                }
            }
        } break;
        case 4: case 6: case 9: case 11: 
        {
            if(day > 30)
            {
                day -= 30;
                month++;
            }
        } break;
        case 2:  
        {
            bool leapYear = IsLeapYear(year);
            if(day > leapYear ? 29 : 28)
            {
                day -= leapYear ? 29 : 28;
                month++;
            }
        } break;
    }
}

int main()
{
    const unsigned short mask1 = (1 << 5) - 1;    //   31 -> 11111
    const unsigned short mask2 = (1 << 4) - 1;    //   15 -> 1111
    const unsigned short mask3 = (1 << 9) - 1;    //  511 -> 111111111
    const unsigned short mask4 = (1 << 13) - 1;   // 8191 -> 1111111111111
    const unsigned short mask5 = 1;               //    1 -> 1

    const unsigned short currDay = 1, currMonth = 11, currYear = 2023;

    unsigned number;
    std::cin >> number;

    if(OddNumberOfOnes(number))
    {
        std::cout << "Invalid" << std::endl;
        return -1;
    }

    // date of manufacture
    unsigned short day, month, year;

    day = mask1 & number;
    number >>= 5;

    month = mask2 & number;
    number >>= 4;

    year = 1900 + (mask3 & number);
    number >>= 9;

    std::cout << day << ' ' << month << ' ' << year << '\n';

    if(!ValidDate(day, month, year))
    {
        std::cout << "Invalid" << std::endl;
        return -1;
    }

    // expiration date in days
    unsigned short daysLeft = mask4 & number;
    number >>= 13;

    unsigned short parityBit = mask5 & number;

    unsigned short daysToAdd = daysLeft;
    if(daysToAdd > 365)
    {
        CorrectYear(year, daysToAdd);
    }
    day += daysToAdd;  // daysToAdd <= 365

    CorrectDate(day, month, year);
    CorrectDate(day, month, year);
    CorrectDate(day, month, year);
    CorrectDate(day, month, year);
    CorrectDate(day, month, year);
    CorrectDate(day, month, year);
    CorrectDate(day, month, year);
    CorrectDate(day, month, year);
    CorrectDate(day, month, year);
    CorrectDate(day, month, year);
    CorrectDate(day, month, year);
    CorrectDate(day, month, year);

    if(!Suitable(currDay, currMonth, currYear, day, month, year))
    {
        std::cout << "Too old" << std::endl;
        return 1;
    }

    std::cout << "Good" << std::endl;
    return 0;
}
