<h1>Указатели и референции. Динамична памет</h1>

<h1>1. Референции</h1>

- Референция(псевдоним) е втора променлива която използва същата памет.
- Референцията е задължително да се инциализира при декларация!

```c++
int x = 10;
int &y = x;

y++; // Променя х и у
x++; // Променя х и у
```

<h1>2. Указател</h1>

- Указател е променлива, в която пазим адрес(шеснайсетично число) от паметта.
- Указателят не е задължително да се инициализира при декларация.
- Указателят може да променя стойността си(да сочи към друг адрес).

```c++
int x = 10;
int *ptr = &x;

// 0x61fe14 -> Адрес в паметта(там се пази информацията на x)
cout << ptr;
```

Пример за употреба на указател:

```c++
int arr[] = {1, 2, 3};
int* ptr = arr;
```

![enter image description here](https://i.ibb.co/cDcX8st/Untitled-Diagram-drawio-3.png)

```c++
ptr++;
cout << ptr[0]; //2;
cout << ptr[1]; //3;
```

 ![enter image description here](https://i.ibb.co/xLLsVK5/Untitled-Diagram-drawio-4.png)

<h1>3. Важни оператори</h1>

<h3>3.1. Оператор &</h3>

- Приема променлива от тип Т.
- Връша указател от тип Т*.

```c++
int x = 10;
int *ptr = &x;
```

<h3>3.2. Оператор *</h3>

- Приема указател от тип Т*.
- Връща променлива от тип Т.

```c++
int x = 10;
int *ptr = &x;
// result вече живее в друг адрес в паметта и няма нищо общо с x.
int result = *ptr;
cout << result;
```

<h1>4. Важни разлики</h1>

- Указателят може да се "re-assign"-ва. Може да приема нови стойност.
- Референцията трябва да се инициализира при създаването.
- Указателят има неутрална стойност (nullptr), а референцията няма.
- Може да се направи масив от указатели, но не и масив от референции.

<h1>5. Динамична памет</h1>

<h3>5.1. Stack</h3>

- Паметта се заделя **ПРЕДИ** да се компилира програмата.
- Паметта се освобождава автоматично - при излизането от scope-а,  в който е дефинирана.

<h3>5.2. Heap</h3>

- От тук се заделя памет по време на изпълнение на програмата.
- Масиви и обекти без предварително да е известна големината.

<h3>5.3. Оператор new</h3>

- Връща указтел към началото на паметта, която сме заделили.
- Заделянето на динамична памет е много "**бавна**" операция!!

**!!Важно!!** При заделяне на памет с оператора new паметта се маркира като използвана. И остава така дори след приключване на програмата! Това се нарича **memory leak**.

```c++
// 8 bytes for 64-bit
// 4 bytes for 32-bit
int *ptr = new int;
// 8 * 10 bytes for 64-bit
// 4 * 10 bytes for 32-bit
int *ptrArray = new int[10];
```

<h3>5.4. Оператор delete</h3>

- Динамична памет **НЕ** се трие автоматично, както в други езици.
- Оператор delete и delete[] - освобождава динамична памет!

```c++
int *ptr = new int(10);
int *ptrArray = new int[10];

delete ptr; // Използваме за единични указатели
delete[] ptrArray; // Използва се за масиви от указатели
```

<h1>6. Примери за лоша употреба на динамична памет</h1>

```c++
void f()
{
    int x = 10;
    bool used[5] = { true, false };
    int *ptrArray = new int[4];
}
```

След приключването на функцията ще се изчисти паметта в стека, но **Не** и паметта в heap-а.

Ние ръчно трябва да я маркираме като свободна.

```c++
void f()
{
    int x = 10;
    bool used[5] = { true, false };
    int *ptrArray = new int[4];
    delete[] ptrArray;
}
```
<h1>Задачи</h1>

**Задача 1** Да се напише програма, която при въведен масив от n цели числа да намира кой от всички елементи преобладава. Ако има еднакъв брой преобладаващи числа да се извади първото срещнато.

*Вход: 7 [2, 2, 1, 1, 1, 2, 2]  Изход: 2*
*Вход: 3 [3, 2, 3]  Изход: 3*

**Задача 2** Напишете функция, която проверява в стринг с дължина n дали всички скоби са затворени последователно и от един и същи вид.

*Вход: 2 "()" Изход: true*
*Вход: 6 "(){}[]" Изход: true*
*Вход: 4 "({}]" Изход: false*

**Задача 3** Да се напише програма, която при въведен стринг с дължина n отговарящ на римско число с дължина максимум 5 букви, принтира това число в десетичен вид:

*Вход: 3 "III" Изход: 3*
*Вход: 4 "XXIV" Изход: 24*
*Вход: 1 "L" Изход: 50*

**Задача 4** Напишете функция, която приема стринг с дължина n и връща този стринг наобратно.

*Вход: 5 "Hello" Изход: "olleH"*

**Задача 5** Да се напише функция, която приема стринг с дължина n и връща първият уникален елемент от него.

*Вход: 3 "FMI", Изход: "F"*
*Вход: 6 "LoveLoaker", Изход: "v"*

**Задача 6** Напишете функция, която приема 3 стринга с дължини - n, n1, n2 и връща най-големия префикс между думите.

*Вход: 6 "flower", 4 "flow", 6 "flight" Изход: "fl"*
*Вход: 3 "dog", 3 "car", 7 "carrace" Изход: ""*

**Задача 7** Напишете програма, която приема дължина на масив n и след това n на брой цели числа. След това програмата да приема цяло число k, което е елемент от масива. Програмата трябва да пренареди елементите в масива, така че всички по-малки елемнти от k да са отляво на k, а всички по-големи да са отдясно на него.

*Вход: 9 [1, 5, 6, 3, 0, -1, 2, 9, 7] 3 Изход: [1, 0, 2, ,-1, 3, 6, 5, 9, 7]*