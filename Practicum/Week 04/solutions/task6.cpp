#include <iostream>

int main()
{
    unsigned int n;
    std::cin >> n;

    int min = INT16_MAX, max = INT16_MIN, sum = 0;
    unsigned int copy = n;

    while(copy != 0)
    {
        int curr;
        std::cin >> curr;

        if(curr < min)
        {
            min = curr;
        }

        if(curr > max)
        {
            max = curr;
        }

        sum += curr;
        copy--;
    }

    std::cout << "min = " << min << ", "
              << "max = " << max << ", "
              << "avg = " << (double)sum / n 
              << std::endl;
    return 0;
}
