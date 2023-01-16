#include <iostream>

using std::cin;
using std::cout;

const size_t size = 13;
const unsigned currency[] = { 10000, 5000, 2000, 1000, 500, 200, 100, 50, 20, 10, 5, 2, 1 };

void logic(){

    size_t count;
    double bill, payment;
    unsigned change;
    cin >> bill >> payment;

    if(payment < 0 || bill < 0){

        cout << "Invalid input\n";
        return;

    }

    if(payment < bill){

        cout << "You have payed less\n";
        return;

    }

    if(payment == bill){

        cout << "Alright\n";
        return;

    }

    change = (unsigned)(payment - bill) * 100 + (unsigned)((payment - bill) * 100) % 100;

    for(size_t i = 0; i < size && change != 0; ++i){

        count = change / currency[i];
        change %= currency[i];

        if(count == 0) continue;

        if(currency[i] < 100) cout << count << '-' << currency[i] << " st\n";
        else cout << count << '-' << currency[i] / 100 << " lv\n";

    }

}

int main(){
    logic();
}