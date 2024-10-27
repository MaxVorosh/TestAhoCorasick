<h1>Тестирование алгоритма Ахо-Корасик</h1>
В файлах AC.h  и main.cpp содержится реализация данного алгоритма. В файле test.cpp находится тестирующая функция. В папке gcov находятся файлы, необходимые для проверки покрытия.

Чтобы запустить процесс тестирования, нужно удалить файлы из папки gcov, и находясь в этой папке последовательно исполнить следующие строчки:
```shell
g++ --coverage -fprofile-arcs -ftest-coverage -fno-exceptions -fno-inline ../main.cpp -O0 -c -o main.o -lgcov
g++ --coverage -fprofile-arcs -ftest-coverage -fno-exceptions -fno-inline ../test.cpp -O0 -c -o test.o -lgcov
g++ --coverage -fprofile-arcs -ftest-coverage -fno-exceptions -fno-inline main.o test.o -O0 -o executable -lgcov
./executable
gcov main.gcda -b -r
```
Если достаточно посмотреть отчёт по уже собранному приложению, достаточно запустить последнюю строчку.
