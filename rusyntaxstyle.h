#pragma once
#define число int
#define без¬озврата void
#define строка std::string
#define публичное public
#define защищЄнное protected
#define класс class
#define файлƒл€„тени€ ifstream
#define файлƒл€«аписи ofstream
#define вернуть return
#define нова€ѕам€ть new
#define использовать using
#define пространство»мЄн namespace
#define виртуально virtual
#define главна€‘ункци€ main
#define локализаци€ setlocale(LC_ALL, "Russian")
#define код¬ывода SetConsoleOutputCP(1251)
#define код¬вода SetConsoleCP(1251)
#define рандомизировать srand(static_cast<unsigned>(time(0)))
#define шаблон template
#define им€“ипа typename
#define неизменный const
#define дл€ for
#define ¬ектор std::vector
#define приватное private
#include <iostream>

шаблон <им€“ипа T>

без¬озврата ¬ывести(неизменный T& значение) {
    std::cout << значение << std::endl;
};