#include <iostream>

using std::cin;
using std::cout;
using std::size_t;

void specialFuncRightToLeft(const int &n){

    if(!(n & 1)) throw "Excuse me";
    if((n & 1<<2) != 0) throw 3;
    if((n & 1<<5) != 0) throw -123;

}

int main(){

    int n;
    cin >> n;

    try{

        specialFuncRightToLeft(n);

    }
    catch(const char e[]){ cout << e << '\n'; }
    catch(const int &e){ cout << e << '\n'; }

}