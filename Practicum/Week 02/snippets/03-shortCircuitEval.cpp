#include <iostream>

int main() {
    int x = 5;
    int y = 0;

    if (y != 0 && (x /= 2)) { // the first expression is false, so the second one will not evaluate
        std::cout << "This won't print because of short circuit evaluation\n";
        // because the first statement is false, because of the AND operator the entire expression can't be true
    }

    std::cout << "x = " << x << std::endl;

    if (y == 0 || (x /= 2)) { // the first expression is true, so the second one will not evaluate
        std::cout << "This will print because of short circuit evaluation\n";
        // naturally if the first statement is true, then it doesn't matter what the next statements are, because of the OR operator
    }

    std::cout << "x = " << x << std::endl;

    if ((x /= 2) || y == 0) { 
        std::cout << "This will print because of short circuit evaluation\n";
    }

    std::cout << "x = " << x << std::endl;

    return 0;
}