#include <iostream>

using std::cin;
using std::cout;
using std::nothrow;

struct elfPair{
    unsigned sections[4];
};

void input(elfPair *&elves, const size_t &size){

    for(size_t i = 0; i < size; ++i)
        for(size_t j = 0; j < 4; ++j)
            cin >> elves[i].sections[j];

}

bool isOverlapping(const elfPair &pair){

    return (pair.sections[0] <= pair.sections[2] && pair.sections[3] <= pair.sections[1])
        || (pair.sections[2] <= pair.sections[0] && pair.sections[1] <= pair.sections[3]);

}

size_t findDuplicatePairs(const elfPair * const &elves, const size_t &size){

    size_t result = 0;
    for(size_t i = 0; i < size; ++i)
        result += isOverlapping(elves[i]);
    return result;

}

bool validate(const elfPair * const &elves, const size_t &size){

    for(size_t i = 0; i < size; ++i)
        if(elves[i].sections[0] > elves[i].sections[1] || elves[i].sections[2] > elves[i].sections[3]) return false;
    return true;

}

void logic(){

    size_t n;
    cin >> n;

    elfPair *elves = new(nothrow) elfPair[n];

    if(!elves){

        cout << "Error with allocating the memory\n";
        return;

    }

    input(elves, n);
    if(!validate(elves, n)){

        cout << "Wrong input\n";
        delete[] elves;
        return;

    }
    
    cout << findDuplicatePairs(elves, n) << '\n';

    delete[] elves;

}

int main(){
    logic();
}