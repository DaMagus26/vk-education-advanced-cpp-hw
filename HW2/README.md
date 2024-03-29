## Текст задания
Необходимо написать программу, реализующую функционал калькулятора с использованием ООП.

Необходимо реализовать поддержку операций +, - и скобок ( ). Для реализации вычислений утверждается следующий интерфейс ```ICalculatable```.
Наследник ```ICalculatable``` обязан реализовать метод double ```Calculate()```;

Каждая операция наследуется от интерфейса ```ICalculatable```, бинарные операции могут принимать два ```ICalculatable```, а унарные один ```ICalculatable```.
Число тоже ```ICalculatable```.
Программа должна парсить выражение, переданное в аргументах командной строки и строить древовидную структуру из наследников ```ICalculatable```.
Выражение можно парсить предельно строго (например, недопускаются лишние пробелы или их отсутствие)
Результат вычисления получается вызовом метода ```Calculate``` у корневой вершины структуры.
Пример (при вводе в терминале выражение с пробелами нужно обернуть, например, в одинарные кавычки)
```shell
./calculator '23 + 7 - ( 10 + 12 )'
8
```

## Запуск программы
Для запуска программы у себя выполните следующие шаги:

1. Клонируйте репозиторий в свою директорию:
```shell
git clone https://github.com/DaMagus26/vk-education-advanced-cpp-hw.git
```

3. Программа использует сборщик CMake. Убедитесь, что он у вас загружена. Скачать библиотеку на Linux/Mac можно командой
```shell
brew install cmake
```
или
```shell
sudo apt-get install cmake
```
4. Соберите приложение. Для этого выполните следующие команды:
```shell
mkdir build
cd build
cmake ..
cmake --build .
```
5. Запустите программу. Исполняемый файл находится в директории build. Программа принимает на вход 1 аргумент –
строку (в кавычках), содержащую математическое выражение. Наличие пробелов значения не имеет. Число, передаваемое 
в функции sqrt и ceil рекомендуется укзывать в скобках (однако это не обязательно).
    
Пример команды запуска:
```shell
./HW2 "2 + 4 * (sqrt(4) + ceil(3.2))"
```
Вывод:
```shell
26
```
