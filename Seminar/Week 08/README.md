<h1>1.Бройни системи и побитови операции</h1>

| Десетична (decimal) | Двоична (binary) | осмична (octal) | Шестнайсетична (hexadecimal) |
|---------------------|------------------|-----------------|------------------------------|
| 00                  | 0000             | 00              | 0                            |
| 01                  | 0001             | 01              | 1                            |
| 02                  | 0010             | 02              | 2                            |
| 03                  | 0011             | 03              | 3                            |
| 04                  | 0100             | 04              | 4                            |
| 05                  | 0101             | 05              | 5                            |
| 06                  | 0110             | 06              | 6                            |
| 07                  | 0111             | 07              | 7                            |
| 08                  | 1000             | 10              | 8                            |
| 09                  | 1001             | 11              | 9                            |
| 10                  | 1010             | 12              | A                            |
| 11                  | 1011             | 13              | B                            |
| 12                  | 1100             | 14              | C                            |
| 13                  | 1101             | 15              | D                            |
| 14                  | 1110             | 16              | E                            |
| 15                  | 1111             | 17              | F                            |

<h3>Преобразуване между бройни системи</h3>

Примери:

- Алгоритъм за преобразуване от произволна бройна система в дестична бройна система
- Алгоритъм за преобразуване от десетчина бройна система в произволна бройна система

<h3>Представяния на отрицателни числа</h3>

- One's complement (5) [101] -(flip)-> [010] (-5)
- Two's complement (5) [101] -(flip)-> [010] + [001] = [011] (-5)

<h3>Представяне на числа с плаваща запетая</h3>

- Fixed-Point arithmetic standard -> фиксирана запетая
- IEEE 754 arithmetic standard -> плаваща запетая

<h1>2.Побитови операции</h1>
прилагат върху един бит или набор от повече отделни битове на двоични числа

- Побитово И (**&**)
- Побитово ИЛИ  (**|**)
- Побитово НЕ (**~**)
- Побитово ИЗКЛЮЧВАЩО ИЛИ  (**^**)
- Побитово отместване  (**<<** )  ( **>>**)

|Оператор| Резултат  |
|--------|-----------|
| a      | 101010100 |
| b      | 100101110 |
| a & b  | 100000100 |
| a \| b | 101111110 |
| ~ a    | 010101011 |
| a ^ b  | 001111010 |
| a << 2 | 101010000 |
| a >> 2 | 001010101 |

Примери:

- Функция, която с побитови операции проверява дали число е четно

```c++
bool isEven(unsigned int n)
{
	return !(n & 1);
}
```

- Функция, която с побитови операции повдига 2 на степен k.

```c++
unsigned int powerOfTwo(unsigned int n)
{
	return (1 << n);
}
```

<h1>3.Изключения</h1>

<h3>3.1.Assert</h3>

- Ако условието е истина програмата продължава без проблем
- Ако условието е лъжа програмата приключва моментално и изписва информация, къде точно е приключила.

```c++
#include <cassert>

int main(){

    assert(true); // Програмата продължава
    assert(false); // Приключва програмата

}
```

<h3>3.2.Throw</h3>

- Терминира програмата след като "хвърля" аргумента.

```c++
int main(){

    throw 20; // terminate called after throwing an instance of 'int'

}
```

<h3>3.3.Try/Catch</h3>

- В try блока пишем код който потенциално може да хвърле грешка.
- В catch блока хващаме грешките хвърлени от try блока и ги обработваме.
- Можем да слагаме няколко catch блока един след друг с различни параметри.

```c++
#include <iostream>

int main(){

    try
    {
        throw 20;
    }
    catch(int e)
    {
        std::cout << "Exception occurred: " << e << '\n';
    }
    catch(char c)
    {
        ...
    }

}
```

- Специфициране на изключения

```c++
// Показваме че тази функция потенциално може да хвърли грешка от тип int.
int myFunction() throw(int);
```

- Стандартна библиотека за грешки

```c++
#include <iostream>
#include <exception>

int main()
{

    try
    {
        throw std::invalid_argument("Exception occurred");
    }
    catch(const std::invalid_argument &e)
    {
        std::cerr << e.what() << '\n';
    }

}
```

<h1>Задачи</h1>

**Задача 1** Напишете функция, която приема цяло число и връща броя на 1-ците в двоичния му запис.

*Вход: 189,  Изход: 6*

**Задача 2** Напишете функция, която валидира дали едно число е в интервала [10, 20]. Ако числото е в интервала програмата да изпечата "Happy number", а ако е извън него да се хвърли грешка със стойност -5.

*Вход: 12 Изход: Happy number*
*Вход: 45 Изход: -5*

**Задача 3** Да се напише програма, която при въведено число n, прави следните проверки:

- Ако 1вият бит на числото е 0 се хвърля грешка със стойност "Excuse me"
- Ако 3тият бит на числото е 1 се хвърля грешка със стойност 3
- Ако 6тият бит на числото е 1 се хвърля грешка със стойност -123

*Вход: 19 Изход: Excuse me*
*Вход: 34 Изход: -123*
*Вход: 6 Изход: 3*

**Задача 4** Напишете функция, която приема цяло число n и цяло число k и връща дали k в двоичен запис (разглеждайки го без водещите 0-ли) е част от двоичния запис на n.

*Вход: 15 3, Изход: true*
*Вход: 13 5 Изход: true*
*Вход: 13 7, Изход: false*

**Задача 5** Да се напише функция, която приема масив, в който всяко число се среща 2 пъти с изключение на едно число, което се среща веднъж.
Напишете функция, която приема такъв масив и връща кое е това число.
(Подсказка: използвайте побитови операции, за да постигнете линейно решение)

*Вход: [9 18 9 12 18 15 12], Изход: 15*

**Задача 6** Напишете функция, която приема число в произволна бройна система и го преобразува в друга произволна бройна система.

*Вход: A12I 19 20 Изход: 8CA7*

**Задача 7** Да се напише програма, която при въведени шестнайсетично и двоично число, намира разликата им в шестнайсетична, десетична и двоична бройна система.

*Вход: 0х9ЕЕ 0110 Изход: 0x9E8 2536 100111101000*