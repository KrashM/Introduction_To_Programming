<h1>Задача за подготовка</h1>

Да направим програма, която проверява валидността на текст и ни помага да го оправим.

Типовете грешки, които могат да съществуват в текст са следните:

- пропуснат интервал около препинателен знак:
    - интервал се слага след всеки препинателен знак с изключение на отваряща скоба и отварящи кавички;
    - интервал се слага преди тире, аритметична операция, отваряща скоба и отварящи кавички;
- сгрешен правопис на дума или фраза;
    - за корекция на сгрешени думи или фрази, софтуерът използва помощен речник;
    - речникът представлява поредица от двойки от сгрешена дума или фраза и правилното ѝ изписване, разделени със знак за тире;
- изпуснат знак за край на изречението:
    - софтуерът определя дали е достигнат краят на изречението тогава и само тогава, когато следващата дума започва на нов ред или няма следваща дума;
    - приемаме, че всяко такова изречение би завършило с точка;
    - ако изречението завършва със затварящи кавички, точката се слага преди тях.

Да се напише функция autoCorrect, която по зададен текст за редакция и речник, както е описан по-горе, извежда на екрана редактирания текст. Функцията да приема параметри с подходящ тип. Да се реализира подходяща програма, която демонстрира работата на функцията като въвежда текст за редакция и речник и гид подава като параметри.

Допуска се използването на помощни функции.

За опериране с вход и изход ще използваме файлове. Ще имаме входен файл "input.txt", изходен файл "result.txt" и файл за всички грешки "errors.txt".

<h3>Ограничения:</h3>

- Максималният брой елементи в речника е 128.
- Максималната дължина на оригиналния текст е 2MB.
- Реалната дължина на речника и оригиналния текст се подават от клавиатурата и трябва да бъдат валидирани, че са в нужните граници.
- Записите в речника имат максимална дължина от 100 символа.
- Дължината на текста след извършените корекции не може да надвишава 4MB.

<h3>Пример:</h3>

Вход:
534
Once upon a time there lived in a certain village a little country girl, the pritiest creature who was ever seen. Her mother was excessively fond of her; and her grandmother doted on her still more.This good woman had a little red riding hood made for her. It suited the girl so extremely well that everybody called her little red riding hood. One day her mother, having made some cakes, said to her,"Go, my dear, and see how your grandmother is doing, for I hear she has been very ill. Take her a cake, and this little pot of butter"

4
stil-still
pritiest-prettiest
little red riding hood-Little Red Riding Hood
leafes-leaves

Изход:
Once upon a time there lived in a certain village a little country girl, the prettiest creature who was ever seen. Her mother was excessively fond of her; and her grandmother doted on her still more. This good woman had a Little Red Riding Hood made for her. It suited the girl so extremely well that everybody called her Little Red Riding Hood. One day her mother, having made some cakes, said to her, "Go, my dear, and see how your grandmother is doing, for I hear she has been very ill. Take her a cake, and this little pot of butter."