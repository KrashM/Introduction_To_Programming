#include <iostream>

int main(){

    int n;
    unsigned count = 0, mask = 1;

    std::cin >> n;
    
    count += !!(n & mask);
    mask <<= 1;
    count += !!(n & mask);
    mask <<= 1;
    count += !!(n & mask);
    mask <<= 1;
    count += !!(n & mask);
    mask <<= 1;
    count += !!(n & mask);
    mask <<= 1;
    count += !!(n & mask);
    mask <<= 1;
    count += !!(n & mask);
    mask <<= 1;
    count += !!(n & mask);
    mask <<= 1;
    count += !!(n & mask);
    mask <<= 1;
    count += !!(n & mask);
    mask <<= 1;
    count += !!(n & mask);
    mask <<= 1;
    count += !!(n & mask);
    mask <<= 1;
    count += !!(n & mask);
    mask <<= 1;
    count += !!(n & mask);
    mask <<= 1;
    count += !!(n & mask);
    mask <<= 1;
    count += !!(n & mask);
    mask <<= 1;
    count += !!(n & mask);
    mask <<= 1;
    count += !!(n & mask);
    mask <<= 1;
    count += !!(n & mask);
    mask <<= 1;
    count += !!(n & mask);
    mask <<= 1;
    count += !!(n & mask);
    mask <<= 1;
    count += !!(n & mask);
    mask <<= 1;
    count += !!(n & mask);
    mask <<= 1;
    count += !!(n & mask);
    mask <<= 1;
    count += !!(n & mask);
    mask <<= 1;
    count += !!(n & mask);
    mask <<= 1;
    count += !!(n & mask);
    mask <<= 1;
    count += !!(n & mask);
    mask <<= 1;
    count += !!(n & mask);
    mask <<= 1;
    count += !!(n & mask);
    mask <<= 1;
    count += !!(n & mask);
    mask <<= 1;
    count += !!(n & mask);

    std::cout << count << '\n';

    return 0;

}