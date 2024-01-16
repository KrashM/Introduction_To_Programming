<h1>Структури</h1>

<h3>1. Какво е структура?</h3>

- Структурите в C++ представляват нов тип, дефиниран от потребителя.
- Те позволяват обединяването на няколко различни типа данни в един(Хетерогенна структура).
- Елементите и се наричат членове(member variables).

<h3>2. Примери за употреба на структури</h3>

<h5>Дефиниция</h5>

```c++
struct Point
{
    double x, y;
};
```

<h5>Деклариране на обект</h5>

```c++
Point a; // Стойности по подразбиране

Point b{0, 0}; // x = 0, y = 0

Point c; // Достъпваме member-ите с оператора "."
c.x = 0;
c.y = 0;
```

<h3>3. Подаване на обект във функция</h3>

- Както всички фундаментални типове данни(int, char, double...), така и обектите от наши типове могат да бъдат константи, референции и т.н.

<h5>Подаване на обект по <em>копие</em></h5>

- Използва се, когато искаме копие на обекта.

```c++
Point reflectX(Point p)
{
    p.x *= -1;
    return p;
}
```

<h5>Подаване на обект по <em>референция</em></h5>

- Използваме, когато искаме да променяме обекта.

```c++
void readPoint(Point &p)
{
    cin >> p.x >> p.y;
}
```

<h5>Подаване на обект по <em>константна референция</em></h5>

- Използваме, когато няма да променяме обекта.

```c++
double euclideanDistance(const Point &q, const Point &p)
{
    return sqrt((q.x - p.x) * (q.x - p.x) + (q.y - p.y) * (q.y - p.y));
}
```

<h3>4. Работа с динамична памет</h3>

- При работа с обекти в динамичната памет, използваме оператора "->", за да достъпваме членовете на обекта.

```c++
#include <iostream>

struct Point
{
    double x, y;
};

double euclideanDistance(const Point &q, const Point &p)
{
    return sqrt((q.x - p.x) * (q.x - p.x) + (q.y - p.y) * (q.y - p.y));
}

int main()
{
   Point *p = new Point(); // Default-ни стойности
   Point *q = new Point(); // Default-ни стойности

   (*p).x = 0; // Достъп, като дереференцираме и с оператор "."
   (*p).y = 0; // Достъп, като дереференцираме и с оператор "."
   q->x = 2; // Достъп с оператор "->".
   q->y = 2; // Достъп с оператор "->".
   
   std::cout << euclideanDistance(*p, *q) << std::endl;
   
   delete p;
   delete q;
}
```

<h3>4. Масиви от обекти</h3>

```c++
struct Point
{
    // Дефинираме default-ни стойност.
    // Ако не се променят, тези остават по подразбиране.
    double x = 3.14, y = 5;
};

int main()
{
    Point arr[10]; // 10 точки
    Point *arr1 = new Point[20]; // 20 точки в динамичната памет

    std::cout << arr[0].x << " " << arr1[3].y << std::endl;

    delete[] arr1; 
}
```

<h1>Препроцесорни директиви и макрота</h1>

<h3>1. Препроцесорни директиви</h3>

- Всички препроцесорни директиви започват с "#".
- Има вградени такива директиви във всички компилатори, като например:
    - #include
    - #define, #undef
    - #ifdef, #ifndef, #elifdef, #elifndef(c++2023)
    - #if, #else, #elif, #endif
    - #error, #warning(c++2023)
    - #pragma

Тези препроцесорни директиви се използват във всички по-големи проекти писани на C++. И са стандарт в индустрията.

<h3>2. Какво е макро и как се използва?</h3>

Макротата в c++ представляват препроцесорна процедура. Това означава, че те се изпълняват преди компилация. За макротата можем да мислим точно като find and replace в кода ни.

<h5>Пример:</h5>

```c++
#include <iostream>

#define L 5
#define WAIT std::cin.get()

int main()
{
    std::cout << L << '\n'; // 5
    WAIT; // Waits for enter to be pressed
}
```

<h3>3. Дефиниране на макро функция</h3>

```c++
#include <iostream>

#define LOG(x) std::cout << x << '\n' // Функция с един аргумент
#define AREA(a, b) (a * b) // Функция с 2 аргумента

int main()
{
    LOG("Hello"); // Hello
    LOG(AREA(4, 3)); // 12
}
```

<h3>4. Писане на макро на повече от 1 ред</h3>

```c++
#include <iostream>

#define MAIN int main()\
{\
    std::cout << "Hello world!";\
}

MAIN
```

<h3>5. Вградени макрота</h3>

Ето [тук](https://en.cppreference.com/w/cpp/preprocessor/replace#Predefined_macros) можете да прочетете повече за тях.
- \__{Macro Name}__

```c++
#include <iostream>

int main()
{
    std::cout << __FUNCTION__ << '\n'; // main
    std::cout << __LINE__ << '\n'; // 6
}
```

<h3>6. Кога е добре да използваме макрота и кога не?</h3>

- Внимавайте за изяждането на запетаите
- Целта им е да пишем лесен за разбиране код.
- Макротата са много полезни за Debugging и Version control.
- Още един добър ресурс свързан с макрота може да намерите [тук](https://caiorss.github.io/C-Cpp-Notes/Preprocessor_and_Macros.html).

<h1>Задачи</h1>

**Задача 1** Да се реализира logging функция, с помощта на макрота, която показва къде точно и кога се е извикала.

**Задача 2** Да се реализира макро CUSTOM_ASSERT(condition, message), което изпълнява следната функционалност. Ако условието, което е подадено, е истина, тогава се принтира на екрана "Assert is ok!". Ако условието, което е подадено, е лъжа, тогава се принтира съобщението, което е подадено и се приключва програмата. За принтирането използвайте макрото от **задача 1**. Напишете проста програма, която да демонстрира работата на макрото.

**Задача 3** Въвеждат се n на брой точки от координатна система. За всяка точка да се определи дали тя лежи в някоя от фигурите, на някой ръб или не лежи никъде. Да се покаже съответното съобщение на конзолата.
![](https://i.ibb.co/jHsN9sK/image.png)

**Задача 4** Създайте структура, която представя комплексно число. Направете функция, която да събира 2 комплексни числа. Направете фунцкия, която да извежда в правилен формат комплексно число.

**Задача 5** Въвежда се цяло число N и после N тригъгълника в равнината, определени от 3 точки(6 координати). Отпечатайте тригълниците сортирани по лицата им.

**Задача 6** Реализирайте структура, която моделира квадратно уравнение. Квадратното уравнение се дефинира с 3 коефициента a, b, c, които са произволни числа. Напишете методи за изчисление на решенията ако има реални такива.

**Задача 7** Създайте структура описваща студент. Всеки студент се определя чрез факултетен номер, курс и средна оценка за курса. Всеки студент е в първи, втори, трети или четвърти курс. Факултетните номера винаги са петцифрени цели числа. Създайте подходящо параметризирана функция `initStudent(...);`, която въвежда коректни данни за студент. Да се напише функция, която принтира студент. Може да използвате помощни функции.