#pragma once

#define число int
#define без¬озврата void
#define строка std::string
#define публичное public
#define защищЄнное protected
#define приватное private
#define класс class
#define нова€ѕам€ть new
#define пространство»мЄн namespace
#define использовать using
#define виртуально virtual
#define главна€‘ункци€ main
#define вернуть return
#define шаблон template
#define им€“ипа typename
#define дл€ for
#define вектор std::vector
#define неизменный const

#define локализаци€ setlocale(LC_ALL, "Russian")
#define код¬ывода SetConsoleOutputCP(1251)
#define код¬вода SetConsoleCP(1251)
#define рандомизировать srand(static_cast<unsigned>(time(0)))
#include <iostream>

шаблон <им€“ипа T>

без¬озврата ¬ывести(неизменный T& значение) {
    std::cout << значение << std::endl;
};