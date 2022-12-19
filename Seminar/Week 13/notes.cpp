#include <iostream>

using std::cin;
using std::cout;

#define DEBUG 1

#if DEBUG == 1
#define LOG(x) cout << x << '\n'
#else
#define LOG(x)
#endif
#define AREA(a, b) (a * b)

void test(const char *function = __builtin_FUNCTION()){

    LOG(function);

}

int main(){

    LOG(AREA(3, 4));
    LOG(__FUNCTION__);
    LOG(__LINE__);
    test();

}