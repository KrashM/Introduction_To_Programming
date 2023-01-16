#include <iostream>

using std::cin;
using std::cout;
using std::swap;
using std::nothrow;

const unsigned color = 100'000, value = 10, coloredValues = 12, black = 5;

void input(unsigned *&cards, const size_t &size){

    for(size_t i = 0; i < size; ++i)
        cin >> cards[i];

}

const char *getColorName(const size_t &color){

    switch(color){

        case 1: return "YELLOW";
        case 2: return "GREEN";
        case 3: return "BLUE";
        case 4: return "RED";
        default: return "\0";
    
    }

}

const char *getValueString(const size_t &value){

    switch(value){

        case 0: return "0";
        case 1: return "1";
        case 2: return "2";
        case 3: return "3";
        case 4: return "4";
        case 5: return "5";
        case 6: return "6";
        case 7: return "7";
        case 8: return "8";
        case 9: return "9";
        case 10: return "+2";
        case 11: return "REVERSE";
        case 12: return "BLOCK";
        case 13: return "CHANGE COLOR";
        case 14: return "+4";
        default: return "\0";
    
    }

}

unsigned getValue(const unsigned &card){
    return card / value % 100;
}

unsigned getColor(const unsigned &card){
    return card / color;
}

bool compare(const unsigned &first, const unsigned &second){

    unsigned valueFirst = getValue(first), valueSecond = getValue(second);
    if(valueFirst != valueSecond) return valueFirst > valueSecond;
    return getColor(first) < getColor(second);

}

void sort(unsigned *&cards, const size_t &size){

    for(size_t i = 0; i < size - 1; ++i)
        for(size_t j = i + 1; j < size; ++j)
            if(compare(cards[i], cards[j]))
                swap(cards[i], cards[j]);

}

bool validate(const unsigned * const &cards, const size_t &size){

    unsigned value, color;
    for(size_t i = 0; i < size; ++i){

        value = getValue(cards[i]);
        color = getColor(cards[i]);

        if(value > 14) return false;
        if(color == 0 || color > black) return false;
        if(value <= coloredValues && color == black || value > coloredValues && color != black) return false;

    }

    return true;

}

void print(const unsigned * const &cards, const size_t &size){

    size_t color;

    for(size_t i = 0; i < size; ++i){

        color = getColor(cards[i]);
        if(i != 0) cout << ' ';

        if(color == 5) cout << '(' << getValueString(getValue(cards[i])) << ')';
        else cout << '(' << getColorName(getColor(cards[i])) << ' ' << getValueString(getValue(cards[i])) << ')';

    }

    cout << '\n';

}

void logic(){

    size_t n;
    cin >> n;

    unsigned *cards = new(nothrow) unsigned[n];
    if(!cards){

        cout << "Error allocating the memory\n";
        return;

    }

    input(cards, n);

    if(!validate(cards, n)){

        cout << "Not a valid input\n";
        delete[] cards;
        return;

    }

    sort(cards, n);
    print(cards, n);

}

int main(){
    logic();
}