#include <iostream>

unsigned int maxDistanceBetweenTwoUpperCase(const char str[], const unsigned int size){

    bool count = false;
    unsigned int maxDistance, currDistance;
    maxDistance = currDistance = 0;

    for(unsigned int i = 0; i < size; i++){

        currDistance += count;
        if(str[i] >= 'A' && str[i] <= 'Z'){

            if(count) currDistance--;
            if(currDistance > maxDistance) maxDistance = currDistance;
            currDistance = 0;
            count = !count;

        }

    }

    return maxDistance;

}

int main(){

    char str[] = "jwislaowAkslawofOlsaQlkasG";
    std::cout << maxDistanceBetweenTwoUpperCase(str, sizeof(str) - 1) << '\n';

}