#include <iostream>

int main() {
    const int SIZE1 = 10;
    const int SIZE2 = 7;

    char str1[] = "klaviatura";
    char str2[] = "monitor";

    int index1 = -1, index2 = -1;

    for (std::size_t i = 0; i < SIZE1; i++)
    {
        for (std::size_t j = 0; j < SIZE2; j++)
        {
            if(str1[i] == str2[j]) {
                index1 = i;
                index2 = j;
                break;
            }
        }
        if(index1 != -1) break;
    }

    if(index1 == -1) return 1;
    
    for (size_t i = 0; i < SIZE2; i++)
    {
        if(i == index2) {
            std::cout << str1;
        } else {
            for (size_t j = 0; j < index1; j++)
            {
                std::cout << ' ';
            }
            std::cout << str2[i];
        }

        std::cout << '\n';
    }
    
    
    return 0;
}