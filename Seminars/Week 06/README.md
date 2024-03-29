<h1>Масиви</h1>

**!Важно!** *Масив* наричаме наредена поредица от елементи от един тип. Елементите се достъпват директно, чрез индекси.

<h1>1. Инициализация на мисиви</h1>

```c++
int arr[10]; // Създава масив от 10 цели числа.
int arr2[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9}; // Създава масив с числата от 0 до 9.
int arr3[10] = {0, 1, 2, 3}; // Останалите елементи се запълват с default-на стойност

int arr[]; // Грешка!!!
int arr[4] = {0, 1, 2, 3, 4}; // Грешка!!!
```

**!Важно!** Задължително е големината на масива да е константа, чиято стойност е ясна преди компилация.

```c++
int n;
std::cin >> n;
int arr[n]; // Грешка!
```

*Забележка!* Това имитира поведение на динамичен масив, именно заради което не го използваме. Напрактика компилатора отново заделя памет от стека за тези масиви.

```c++
const int SIZE = 4;
int arr[SIZE]; // Екстра!
```

<h1>2. Достъп до елементите</h1>
В масивите имаме константен достъп до всеки един елемент. Достъпът става посредством индекси, започващи от 0. Защо от 0!?

```c++
int arr[] = {1, 2, 40, 4, 5};
arr[2] = 3; // Присвояваме на елементът на индекс 2 стойността 3.
            // [1, 2, 3, 4, 5]
std::cout << arr[3]; // Отпечатва на стандартния изход елементът на индекс 3(4).
```

<h1>3. Масиви като аргументи на функции</h1>

<h3>Пример:</h3>

```c++
// Функция, която показва съдържанието на масива
void print(const int arr[], int len){

    for(int i = 0; i < len; ++i)
    {
        std::cout << arr[i] << ' ';
    }

}

// Функция, която удвоява стойността на всеки елемент в масива
void doubleValue(int[] arr, unsigned size){

    for(unsigned i = 0; i < size; ++i)
    {
        arr[i]++;
    }

}

// Функция, която сумира елементите на масива
int sum(int *arr, size_t size)
{
    int sum = 0;

    for(size_t i = 0; i < size; ++i)
    {
        sum += arr[i];
    }

    return sum;
}
```

<h1>Задачи</h1>

**Задача 1:** Да се напише фунцкия, която приема масив и връща минималния елемент в него.

*Вход: [12 5 23 9] Изход: 5*

**Задача 2:** Да се напише функция, която приема масив и връща сумата на елементите в него.

*Вход: [13 0 2 3 16] Изход: 34*

**Задача 3:** Да се напише функция, която приема масив и връща най-големият общ делител на числата в масива.

*Вход: 9 18 27 15 Изход: 3*

**Задача 4:** Да се напише функция, която приема 2 масива и връща броят на еднаквите им елементи. Не разглеждаме повторения, търсим само дали има еднакви елементи!

*Вход: [1 2 3 4 5 6 7 8 9] [14 67 23 4 92 6 10 2 48 5 19 4] Изход: 4*

**Задача 5:** Да се напише функция, която приема сортиран масив и изтрива всички повтарящи се елементи в него.

*Вход: [1 2 2 2 3 4 5 5 6 7] Изход: [1 3 4 6 7]*

**Задача 6:** Да се напише функция, която приема масив и намира коя е най-малката разлика между два елемента.

*Вход: [10 2 5 83 20 17 24 7] Изход: 2*