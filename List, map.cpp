#include <windows.h>
#include <string>
#include <map>
#include <iostream>
#include "﻿PythonStyleSyntax.h"
#include <algorithm>
#include <list>

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

	// Телефонная книга с использованием map

    map<string, int> telephoneBook = { {"Михаил", 987835082}, {"Анна", 63586932}, {"Алексей", 933861600}, {"Борис", 635194255}};

    int choose;
    print("Добро пожаловать в телефонную книгу. Выберите опцию:\n1 - Добавить контакт\n2 - Найти номер по имени\n3 - Удалить контакт\n4 - Обновить номер телефона\n5 - Показать все контакты в алфавитном порядке\n6 - Проверить контакт");
    while (true) {
        cin >> choose;
        if (choose == 1)
        {
            string name;
            int number;
            print("Введите имя контакта:");
            cin >> name;
            print("Введите номер телефона:");
            cin >> number;
            telephoneBook[name] = number;
            print("Контакт добавлен.");
        }
        else if (choose == 2)
        {
            string name;
            print("Введите имя контакта для поиска:");
            cin >> name;
            if (telephoneBook.find(name) != telephoneBook.end())
            {
                print("Номер телефона: " + to_string(telephoneBook[name]));
            }
            else
            {
                print("Контакт не найден.");
            }
        }
        else if (choose == 3)
        {
            string name;
            print("Введите имя контакта для удаления:");
            cin >> name;
            telephoneBook.erase(name);
            print("Контакт удален.");
        }
        else if (choose == 4)
        {
            string name;
            int number;
            print("Введите имя контакта для обновления:");
            cin >> name;
            print("Введите новый номер телефона:");
            cin >> number;
            telephoneBook[name] = number;
            print("Номер телефона обновлен.");
        }
        else if (choose == 5)
        {
            print("Все контакты в алфавитном порядке:");
            for (const auto& [name, number] : telephoneBook)
            {
                print(name + " - " + to_string(number));
            }
        }
        else if (choose == 6)
        {
            string name;
            print("Введите имя контакта для проверки:");
            cin >> name;
            if (telephoneBook.count(name))
            {
                print("Контакт существует.");
            }
            else
            {
                print("Контакт не найден.");
            }
        }
    }
    

    //Система обработки заказов с помощью list

	/*list<string> listOfOrders = { "Планшет", "Иркутский холодильник", "Клавиатура", "Фотоаппарат", "СУХАРИКИИИИИИИИИИИ"};

    int choose;
    print("Добро пожаловать в программу обработки заказов. Выберите опцию.\n1 - Добавить новый заказ.\n2 - Обработать заказ (удалить из начала очереди)\n3 - Показать текущий заказ\n4 - Отменить заказ\n5 - Показать все заказы в очереди\n6 - Проверить сколько заказов ожидает\n7 - Найти заказ по номеру\nВаш выбор: ");
    
    while (true) {
        cin >> choose;

        if (choose == 1)
        {
            string order;
            print("Введите название заказа:");
            cin >> order;
            listOfOrders.push_back(order);
            print("Заказ добавлен.");
        }
        else if (choose == 2)
        {
            if (!listOfOrders.empty())
            {
                print("Обрабатывается заказ: " + listOfOrders.front());
                listOfOrders.pop_front();
            }
            else
            {
                print("Нет заказов для обработки.");
            }
        }
        else if (choose == 3)
        {
            if (!listOfOrders.empty())
            {
                print("Текущий заказ: " + listOfOrders.front());
            }
            else
            {
                print("Нет текущих заказов.");
            }
        }
        else if (choose == 4)
        {
            string order;
            print("Введите название заказа для отмены:");
            cin >> order;
            listOfOrders.remove(order);
            print("Заказ отменен.");
        }
        else if (choose == 5)
        {
            print("Все заказы в очереди:");
            for (const auto& order : listOfOrders)
            {
                print(order);
            }
        }
        else if (choose == 6)
        {
            print("Количество ожидающих заказов: " + to_string(listOfOrders.size()));
        }
        else if (choose == 7)
        {
            int order;
            print("Введите номер заказа для поиска:");
            cin >> order;
            if (order > 0 && order <= listOfOrders.size())
            {
                auto it = listOfOrders.begin();
                advance(it, order - 1);
                print("Заказ под номером " + to_string(order) + ": " + *it);
            }
            else
            {
                print("Заказ с таким номером не найден.");
            }
        }
    }*/
	

    return 0;
}
