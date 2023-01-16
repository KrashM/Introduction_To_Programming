#include <iostream>

using std::max;
using std::cin;
using std::cout;

const size_t MAX_ELVES = 100, MAX_MEALS = 20;

void logic(){

    unsigned maxCal = 0, cals, current;
    size_t n, meals, maxIndex;
    cin >> n;

    if(n > MAX_ELVES){

        cout << "Size overflow\n";
        return;

    }

    for(size_t i = 0; i < n; ++i){

        cin >> meals;

        if(meals > MAX_MEALS){

            cout << "Size overflow\n";
            return;

        }

        current = 0;
        for(size_t j = 0; j < meals; ++j){

            cin >> cals;
            current += cals;

        }

        if(maxCal < current){

            maxCal = current;
            maxIndex = i + 1;

        }

    }

    cout << "Elf number " << maxIndex << " has max calories - " << maxCal << '\n';

}

int main(){
    logic();
}