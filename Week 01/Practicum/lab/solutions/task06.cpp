#include <iostream>

const int SONG_LENGTH = 3;
const int MINUTES_IN_AN_HOUR = 60;
const int FIRST_TWO_DIGIT_NUMBER = 10;

int main ()
{
    int hourPerformanceBeginning, minutesPerformanceBeginning;
    int songsCount;

    std::cin >> hourPerformanceBeginning >> minutesPerformanceBeginning;
    std::cin >> songsCount;

    int performanceBeginningInMinutes = hourPerformanceBeginning * MINUTES_IN_AN_HOUR + minutesPerformanceBeginning;
    
    performanceBeginningInMinutes += songsCount * SONG_LENGTH;

    int hourPerformanceEnding = performanceBeginningInMinutes / MINUTES_IN_AN_HOUR;
    int minutesPerformanceEnding = performanceBeginningInMinutes % MINUTES_IN_AN_HOUR;

    std::cout << "Preslava's performance will end at ";
    std::cout << (hourPerformanceEnding < FIRST_TWO_DIGIT_NUMBER ? "0" : "");
    std::cout << hourPerformanceEnding << ":";
    std::cout << (minutesPerformanceEnding < FIRST_TWO_DIGIT_NUMBER ? "0" : "");
    std::cout << minutesPerformanceEnding << std::endl;

    return 0;
}