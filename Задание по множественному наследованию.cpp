#include <windows.h>
#include <iostream>
#include "PythonStyleSyntax.h"

using namespace std;

class Warrior {
public:
    void attack() {
        print("Противник атакован в ближнем бою.");
    }

    void UseShield() {
        print("Щит установлен.");
    }
};

class Mage {
public:
    void castSpell() {
        print("Противник атакован заклинанием 1 уровня.");
    }

    void useMana() {
        print("На заклинание 1 уровня потрачено 50 ед маны.");
    }
};

class Rogue {
public:
    void stealth() {
        print("Активирован режим стелса. Параметр максировки: 30 -> 50.");
    }

    void pickLock() {
        print("Использовать отмычку на двери? Это снизит уровень маскировки.");
        string choose;
        while (true) {
            input(choose);
            if (choose == "Да") {
                print("Отмычка использована. Осталось отмычек: 0");
                break;
            }
            else if (choose == "Нет") {
                print("Дверь по прежнему заперта. Осталось отмычек: 1");
                break;
            }
            else {
                print("Некорректный выбор, попробуйте ещё раз: ");
            }
        }

    }
};

class Hybrid : public Warrior, public Mage, public Rogue {
public:
    void hybridAttack() {
        print("Гибридная атака: ближний бой + заклинание 1 уровня.");
	}   
};
int main() {
    setlocale(LC_ALL, "Russian");
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

	Warrior warrior;
	Mage mage;
	Rogue rogue;
	Hybrid hybrid;
    print("Воин: \n");
	warrior.attack();
    warrior.UseShield();
	print("\nМаг: \n");
	mage.castSpell();
	mage.useMana();
    print("\nРазбойник: \n");
	rogue.stealth();
    rogue.pickLock();
	print("\nГибрид (Воин + Маг + Разбойник): \n");
	hybrid.hybridAttack();
    hybrid.attack();
	hybrid.castSpell();
    hybrid.useMana();
	hybrid.pickLock();
	hybrid.UseShield();

    return 0;
}

