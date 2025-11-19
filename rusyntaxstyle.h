#pragma once
// Русские замены для ключевых слов (оставляем те, что полезны)
#define число int
#define безВозврата void
#define строка std::string
#define публичное public
#define защищённое protected
#define приватное private
#define класс class
#define новаяПамять new
#define пространствоИмён namespace
#define использовать using
#define виртуально virtual
#define главнаяФункция main
#define вернуть return
#define шаблон template
#define имяТипа typename
#define для for
#define Вектор std::vector
#define неизменный const

// Локализация/кодировка — можно оставить как макросы, если удобнее
#define локализация setlocale(LC_ALL, "Russian")
#define кодВывода SetConsoleOutputCP(1251)
#define кодВвода SetConsoleCP(1251)
#define рандомизировать srand(static_cast<unsigned>(time(0)))
#include <iostream>

шаблон <имяТипа T>

безВозврата Вывести(неизменный T& значение) {
    std::cout << значение << std::endl;
};