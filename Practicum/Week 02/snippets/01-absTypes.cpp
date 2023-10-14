#include <iostream>
#include <cmath>
#include <cstdlib>

int main() {
    double x = -3.14;

    // Using abs from cmath
    std::cout << "abs(" << x << ") = " << abs(x) << '\n';

    // Using abs from std
    std::cout << "abs(" << x << ") = " << std::abs(x) << '\n';

    // Using fabs from cstdlib
    std::cout << "fabs(" << x << ") = " << fabs(x) << '\n';

    return 0;
}
