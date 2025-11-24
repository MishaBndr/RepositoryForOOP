#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <windows.h>
#include <string>
#include <cstring>
#include "PythonStyleSyntax.h"

using namespace std;

class Human {
    string name;
    int age;
public:
    static int quantity_of_humans;
    Human() : name{}, age{ 0 } {}

    Human(string Name, int Age) : name(Name), age(Age) {
        quantity_of_humans++;
    }

    Human(const Human& other) {
        name = other.name;
        age = other.age;
        quantity_of_humans++;
    }

    string getName() {
        return name;
    }

    int getAge() {
        return age;
    }

};

int Human::quantity_of_humans = 0;

class Apartament {
    Human* humans;
    int count_of_humans;
public:
    static int quantity_of_apartaments;
    Apartament() : humans{ nullptr }, count_of_humans{ 0 } {}

    Apartament(Human* arr, int cnt) {
        quantity_of_apartaments++;
        count_of_humans = cnt;
        humans = new Human[count_of_humans];
        for (int i = 0; i < count_of_humans; i++) {
            humans[i] = arr[i];
        }
    }

    Apartament(const Apartament& other) {
        count_of_humans = other.count_of_humans;
        humans = new Human[count_of_humans];
        for (int i = 0; i < count_of_humans; i++) {
            humans[i] = other.humans[i];
        }
    }

    int getCount() {
        return count_of_humans;
    }

    void getInfoOfApartament(int index) {
        
        cout << "Кол-во жильцов в квартире №" << index << ": " << getCount();
        cout << "\nЖильцы: " << "\n";
        for (int i = 0; i < count_of_humans; i++) {
            cout << humans[i].getName() << " - " << humans[i].getAge() << endl;
        }
    }


    ~Apartament() {
        delete[] humans;
    }
};

int Apartament::quantity_of_apartaments = 0;

class House {
    Apartament* apartaments;
    int count_of_apartaments;
public:
    House(Apartament* arr, int Count_of_apartaments) {
        count_of_apartaments = Count_of_apartaments;
        apartaments = new Apartament[count_of_apartaments];
        for (int i = 0; i < count_of_apartaments; i++) {
            apartaments[i] = arr[i];
        }
    }


    House(const House& other) {
        count_of_apartaments = other.count_of_apartaments;
        apartaments = new Apartament[count_of_apartaments];
        for (int i = 0; i < count_of_apartaments; i++) {
            apartaments[i] = other.apartaments[i];
        }
    }

    ~House() {
        delete[] apartaments;
    }
};

int main()
{
    srand(static_cast<unsigned>(time(0)));
    setlocale(LC_ALL, "Russian");
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    Human h1{ "Алексей", 25 };
    Human h2{ "Максим", 17 };
    Human h3{ "Ольга", 30 };

    Human* humans1 = new Human[3]{ h1, h2, h3 };

    Human h4{ "Антон", 34 };
    Human h5{ "Андрей", 15 };
    Human h6{ "Дарья", 25 };
    Human h7{ "Дарина", 23 };

    Human* humans2 = new Human[4]{ h4, h5, h6, h7 };

    Human h8{ "Валентина", 36 };
    Human h9{ "Михаил", 17 };
    Human h10{ "Станислав", 40 };
    Human h11{ "Любовь", 45 };
    Human h12{ "Мария", 30 };

    Human* humans3 = new Human[5]{ h8, h9, h10, h11, h12 };

    Apartament a1{ humans1, 3 };
    Apartament a2{ humans2, 4 };
    Apartament a3{ humans3, 5 };

    Apartament* apartaments = new Apartament[3]{ a1, a2, a3 };

    House house{ apartaments , 3 };

    int choose;
    while (true) {
        print("\n===Меню===\nДобро пожаловать!\nВыберите опцию:\n1 - узнать о жильцах в квартирах\n2 - кол-во квартир в доме\n3 - кол-во людей в доме\n4 - Опция \"Новая квартира\" Ваш выбор: ");
        input choose;
        if (choose == 1) {
            int choose_flat;
            print("Информацию о каких квартирах вы хотите получить?\n1 - Первая\n2 - Вторая\n3 - Третья\n4 - Получить информацию из всех трёх квартир.\nВаш выбор: ");
            input choose_flat;
            if (choose_flat == 1) {
                apartaments[0].getInfoOfApartament(choose_flat);
            }
            else if (choose_flat == 2) {
                apartaments[1].getInfoOfApartament(choose_flat);
            }
            else if (choose_flat == 3) {
                apartaments[2].getInfoOfApartament(choose_flat);
            }
            else if (choose_flat == 4) {
                apartaments[0].getInfoOfApartament(1);
                enter;
                apartaments[1].getInfoOfApartament(2);
                enter;
                apartaments[2].getInfoOfApartament(3);
            }
        }
        else if (choose == 2) {
            cout << "В доме всего " << Apartament::quantity_of_apartaments << " квартир";
        }
        else if (choose == 3) {
            cout << "В доме всего " << Human::quantity_of_humans << " людей";
        }
        else if (choose == 4) {
            int choose_to_give_new_apartament;
            print("Люди из какой квартиры оформят документы на новую?\n1 - из первой.\n2 - из второй.\n3 - из третьей.\n");
            input choose_to_give_new_apartament;
            if (choose_to_give_new_apartament == 1) {
                Apartament a4;
                a4 = a1;
                print("На жильцов из квартиры 1 были записаны документы новой квартиры. Теперь согласно документам жильцы квартиры 4: ");
                a1.getInfoOfApartament(4);
            }
            else if (choose_to_give_new_apartament == 2) {
                Apartament a5;
                a5 = a2;
                print("На жильцов из квартиры 2 были записаны документы новой квартиры. Теперь согласно документам жильцы квартиры 5: ");
                a2.getInfoOfApartament(5);
            }
            else if (choose_to_give_new_apartament == 3) {
                Apartament a6;
                a6 = a3;
                print("На жильцов из квартиры 3 были записаны документы новой квартиры. Теперь согласно документам жильцы квартиры 6: ");
                a3.getInfoOfApartament(6);
            }

            
        }
    }

    delete[] humans1;
    delete[] humans2;
    delete[] humans3;
    delete[] apartaments;

    return 0;
}

   

