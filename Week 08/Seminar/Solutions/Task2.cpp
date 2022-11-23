#include <iostream>

using std::cin;
using std::cout;
using std::size_t;

void validate(const int &n){
    if(n < 10 || 20 < n) throw -5;
}

int main(){

    int n;
    cin >> n;

    try{

        validate(n);
        cout << "Happy number\n";

    }
    catch(const int &e){ cout << e << '\n'; }

}