#include <iostream>

int main() {
    
    bool number1_bit0, number1_bit1, number1_bit2, number1_bit3;
    bool number2_bit0, number2_bit1, number2_bit2, number2_bit3;
    bool carry_over = 0;
    bool sum_bit0, sum_bit1, sum_bit2, sum_bit3, sum_bit4;

    std::cin >> number1_bit3 >> number1_bit2 >> number1_bit1 >> number1_bit0;
    std::cin >> number2_bit3 >> number2_bit2 >> number2_bit1 >> number2_bit0;

    sum_bit0 = number1_bit0 ^ number2_bit0;
    carry_over = number1_bit0 & number2_bit0;

    sum_bit1 = number1_bit1 ^ number2_bit1 ^ carry_over;
    carry_over = (number1_bit1 & number2_bit1) | (number1_bit1 & carry_over) | (number2_bit1 & carry_over);

    sum_bit2 = number1_bit2 ^ number2_bit2 ^ carry_over;
    carry_over = (number1_bit2 & number2_bit2) | (number1_bit2 & carry_over) | (number2_bit2 & carry_over);

    sum_bit3 = number1_bit3 ^ number2_bit3 ^ carry_over;
    carry_over = (number1_bit3 & number2_bit3) | (number1_bit3 & carry_over) | (number2_bit3 & carry_over);

    sum_bit4 = carry_over;

    std::cout << sum_bit4 << sum_bit3 << sum_bit2 << sum_bit1 << sum_bit0 << std::endl;

   return 0;
}