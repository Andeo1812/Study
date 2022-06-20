#  Углубленное программирование на языке С/С++

# Задание
Вы разрабатываете специализированную БД сотрудников для корпорации, в которой работает около 10к человек. 
По ряду причин все данные необходимо хранить в оперативной памяти. Предложите такую эффективную упаковку 
данных о сотруднике (его имени, фамилии, поле, возрасте, заработной плате, должности и стаже работы), 
при которой эти данные занимали бы наименьший объем. Используя её, реализуйте однопоточную и многопоточную 
программу построения отчётов о средней заработной плате для каждой должности в зависимости от стажа работы.

Первым аргументом программе подается путь к файлу письма (.blk).

## Формат ввода:

`name[32] surname[64] gender[8] age[4] salaty[16] position[64] experience[4]`

## Формат вывода:

В работе создает директорию report* в зависимости
от метода и там же создаются файлы отвечающие за распределение по должностям:

Actor.txt
```
exp 4 - 379648
exp 5 - 49136
exp 6 - 217894
exp 7 - 104281
exp 8 - 64867
exp 9 - 111761
exp 10 - 34688
```

## Устройство структуры:

Массив пользовательского типа.

## Модули:

general - отвечат за загрузку данных в память, вывод, освобождение памяти, а так же сортировку данных.

imperative_model - отвечает за последовательную реализацию бизнес логики.

multi_threaded_model - отвечает за погопоточную реализацию бизнес логики.

## Работа программы:

На вход принимает первым аргументом требование к сортировке, путь к базе
данных, путь к отсортированной базе данных (для вывода), тип работы 
императивный или многопоточный.

### Примеры запуска:
```
./build/HW-2 1 generated_database.txt sorted_database.txt 1
```
- для последовательного алгоритма.

```
./build/HW-2 1 generated_database.txt sorted_database.txt 2
```
- для многопоточного

## Проверки:
1. Стические анализаторы cppcheck, clang-tidy, cpplint.
2. Сборка на cmake.
3. Тестирование на gtest общего функционала для обоих библиотек.
4. Провекрка покрытия gtest. Если менее чем 60% (опционально в make) выдаст ошибку для также для общего функционала и обоих библиотек.
5. Запуск тестов на valgring также для общего функционала и обоих библиотек.

При наличии замечаний или неудаче выдаст ошибку.