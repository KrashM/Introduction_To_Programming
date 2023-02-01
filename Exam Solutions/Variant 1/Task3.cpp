#include <iostream>

using std::cin;
using std::cout;
using std::nothrow;

struct Polynom{

    size_t size;
    double *coeficients;

};

Polynom sum_poly(Polynom a, Polynom b){

    if(a.size < b.size) return sum_poly(b, a);

    Polynom c;
    c.size = a.size;

    c.coeficients = new(nothrow) double[c.size];
    if(!c.coeficients){

        c.size = 0;
        return c;

    }

    for(size_t i = 0; i < b.size; ++i)
        c.coeficients[i] = a.coeficients[i] + b.coeficients[i];
    
    for(size_t i = b.size; i < a.size; ++i)
        c.coeficients[i] = a.coeficients[i];

    return c;

}

int main(){

    Polynom a;
    Polynom b;

    cin >> a.size;

    a.coeficients = new(nothrow) double[a.size];
    if(!a.coeficients) return 1;

    for(size_t i = 0; i < a.size; ++i)
        cin >> a.coeficients[i];

    cin >> b.size;

    b.coeficients = new(nothrow) double[b.size];
    if(!b.coeficients){
        
        delete[] a.coeficients;
        return 1;

    }

    for(size_t i = 0; i < b.size; ++i)
        cin >> b.coeficients[i];

    Polynom c = sum_poly(a, b);

    for(size_t i = 0; i < c.size; ++i)
        cout << c.coeficients[i] << ' ';
    cout << '\n';

    delete[] a.coeficients;
    delete[] b.coeficients;
    delete[] c.coeficients;

}