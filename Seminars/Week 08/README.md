<h1>Многомерни масиви</h1>

<h1>1. Двумерни масиви(матрици)</h1>

```c++
// Създава матрица с 3 реда и 2 колони.
int matrix[3][2];
// Инициализираме матрицата с 3 реда и 2 колони с конкретни стойности.
int matrix2[3][2] = {
    {1, 3},
    {4, 2},
    {2, 5}
};
// Инициализиране по изреждане на елементите.
int matrix3[3][2] = { 1, 2, 3, 4, 5, 6 };
// Можем да изпуснем броя редове на матрицата.
int matrix4[][2] = { 1, 2, 3, 4, 5, 6, 7, 8 };
```

![](https://eli.thegreenplace.net/images/2015/row-major-2D.png)

<h1>2. Достъп до елементи</h1>

```c++
int matrix[3][2] = { {1, 2}, {3, 4}, {5, 6} };
cout << matrix[1] << '\n'; // row 1 - 0x93ad9ffdcc
cout << matrix[0][1] <<'\n'; // 2
```

<h1>3. N-мерни масиви</h1>

```c++
// Декларация:
int cube[3][3][3];

// Достъп до елементи:
cube[1]       // Двумерен масив
cube[1][2]    // Едномерен масив
cube[1][2][0] // Конкретен елемент
```

**Задача за часа:** Да се направи примерна имплементация на играта tic-tac-toe.

<h1>Задачи</h1>

**Задача 1:** Да се напише функция, която принтира матрица в спираловидна форма.

*Вход:*<br>*3 3*<br>*1 2 3*<br>*4 5 6*<br>*7 8 9*<br>*Изход: 1 2 3 6 9 8 7 4 5*

**Задача 2:** Да се напише програма, която при въведена матрица NxN, извежда дали матрицата е *магически квадрат*.

*Вход:*<br>*3*<br>*2 7 6*<br>*9 5 1*<br>*4 3 8*<br>*Изход: Yes*
*Вход:*<br>*3*<br>*1 2 2*<br>*2 2 1*<br>*2 1 2*<br>*Изход: No*

**Задача 3:** Да се напише програма, която проверява дали матрица е горен или долен триъгълник и да изписва съответното.

*Вход:*<br>*4 4*<br>*1 0 0 0*<br>*1 4 0 0*<br>*4 6 2 0*<br>*0 4 7 6*<br>*Изход: This is a lower triangular matrix*
*Вход:*<br>*4 4*<br>*1 3 5 3*<br>*0 4 6 2*<br>*0 0 2 5*<br>*0 0 0 6*<br>*Изход: This is an upper triangular matrix*
*Вход:*<br>*4 4*<br>*0 0 5 3*<br>*1 4 6 2*<br>*3 0 2 5*<br>*0 6 5 6*<br>*Изход: This is neither an upper, nor a lower triangular matrix*

**Задача 4:** Да се направи програма, която намира сбора и разликата на две матрици NxM.

*Вход:*<br>*3 2*<br>*1 2*<br>*3 4*<br>*5 6*<br><br>*1 4*<br>*3 5*<br>*6 1*<br>*Изход:*<br>*2 6*<br>*6 9*<br>*11 7*<br><br>*0 -2*<br>*0 -1*<br>*-1 5*

**Задача 5:** Да се напише функция, която приема двумерен масив(матрица) и я завърта на 90 градуса, по часовниковата стрелка. За допълнителна сложност се опитайте да я направите със сложност по памет O(1).

*Вход:*</br>
*1 2 3*</br>
*4 5 6*</br>
*7 8 9*</br>
*Изход:*</br>
*7 4 1*</br>
*8 5 2*</br>
*9 6 3*

**Задача 6:** Да се напише програма, която намира детерминантата на NxN матрица.

*Вход:*<br>*3*<br>*1 2 3*<br>*4 3 5*<br>*7 5 3*<br>*Изход: 27*

**Задача 7:** Да се напише програма, която нямира ранга на матрица NxM.

*Вход:*<br>*4 4*<br>*2 8 -3 14*<br>*-1 2 3 5*<br>*-1 14 6 2*<br>*0 12 3 24*<br>*Изход: 3*