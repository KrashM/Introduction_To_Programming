<h1>Символни низове</h1>

<h1>1. Декларация и инициализация на C-style низове</h1>

**!Важно!** Низовете от този вид винаги завършват с терминиращ знак, а именно '\0'.
Ако се чудите защо изречението ви завършва с някакви странни емоджита, или символи, това е защо :).

```c++
// Тромав и гаден синтаксис.
char str[6] = { 'H', 'e', 'l', 'l', 'o', '\0' };
// По кратък и хубав запис на същото нещо.
char str[] = "Hello";
```

<h1>2. Представяне в паметта</h1>

![](https://www.tutorialspoint.com/cplusplus/images/string_representation.jpg)

*Терминиращата нула* накрая е нужна, за да е ясно, къде свършва низът. Ако тя липсва няма да знаем, къде ще е краят на нашият низ.

<h1>3. Важни функции</h1>

|№|                                                 Фунцкия                                                 |
|-|---------------------------------------------------------------------------------------------------------|
|1|**strlen(s1);**    <p>Връща дължината на низа s1.</p>                                                    |
|2|**strcpy(s1, s2);**<p>Копира съдържанието на s2 в s1.</p>                                                |
|3|**strcmp(s1, s2);**<p>Сравнява s1 и s2 и връща: 0, ако s1 = s2; < 0, ако s1 < s2; > 0, ако s1 > s2.</p>  |
|4|**strcat(s1, s2);**<p>Конкатенира(залепя) s2 към края на s1.</p>                                         |
|5|**strchr(s1, ch);**<p>Връща указател към първото срещане на ch в низът s1.</p>                           |
|6|**strstr(s1, s2);**<p>Връща указател към първото срещане на s2 в s1.</p>                                 |

**!Важно!** 5 и 6 връщат nullptr(празен указател) ако не намерят търсеното.

<h1>4. Четене и писане</h1>

```c++
char str[255]; // 254 символа + 1 за терминираща 0('\0')
std::cin >> str; // Въвеждане от стандартния вход
std::cout << str; // Извеждане на стандартния изход
```

**!!!Проблем!!!**

```c++
char str[255];
std::cin >> str; // Въвеждаме "Hello World"
std::cout << str; // Извежда "Hello"
```
**Защо става това?**

*Различни начини за въвеждане*

- Въвеждане на точен брой символи.

```c++
char str[255];
std::cin.get(str, 9); // Въвеждаме "Hello World"
std::cout << str; // Извежда "Hello Wo"
```

- Въвеждане на цял ред

```c++
char str[255];
std::cin.getline(str, 255); // Въвеждаме "Hello World"
std::cout << str; // Извежда "Hello World"
```

<h1>Задачи</h1>

**Задача 1** Да се напише програма, която приема низ и единичен символ и връща, колко пъти се среща символът в низа.

*Вход: ababbbccba a Изход: 3*

**Задача 2** Да се напише програма, която приема низ и проверява, какъв е броят на малки букви, големи букви и цифри.

*Вход: Aaab1Ba5Bab2b Изход: Uppercase: 3; Lowercase: 7; Digits: 3;*

**Задача 3** Да се напише програма, която приема низ. Програмата да прави главните букви малки и малките букви главни.

*Вход: AAAbbaaBaBB Изход: aaaBBAAbAbb*

**Задача 4** Да се напише програма, която приема низ и принтира максималният брой символи между две големи букви.

*Вход: jwislaowAkslawofOlsaQlkasG Изход: 7*

**Задача 5** Да се напише програма, която приема низ и премахва всички празни места в него(' ').

*Вход: Hello there my friends it's nice to meet you. Изход: Hellotheremyfriendsit'snicetomeetyou.*

**Задача 6** Да се напише програма, която намира дали един низ е плаиндром.

*Вход: AaABBbBBAaA Изход: true*
*Вход: skjwiaonsse Изход: true*

**Задача 7** Да се напише програма, която приема низ и намира най-късата и най-дългата дума в него.

*Вход: Hello there my friends it's nice to meet you. Изход: friends my*