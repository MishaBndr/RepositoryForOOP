#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <string>
#include <windows.h>

using namespace std;

class Elevator {
public:
	int lowerFloor;
	int upperFloor;
    int on_off;
	int currentFloor;

    Elevator(int lowFl, int uppFl, int currFl, int On_Off) {
        lowerFloor = lowFl;
        upperFloor = uppFl;
        currentFloor = currFl;
		on_off = On_Off;
    }

    int inWhatFloor() {
		ifstream fin("file_of_floor.txt");
		fin >> currentFloor;
		fin.close();
        return currentFloor;
    }
	
    bool isWorks(int new_state) {
        on_off = new_state;
        ofstream is_working("is_working.txt");
        is_working << on_off;
        is_working.close();
        return on_off == 1;
    }

    bool getCurrentState() {
        ifstream is_working("is_working.txt");
        is_working >> on_off;
        is_working.close();
        return on_off == 1;
    }
};

int main()
{
    srand(static_cast<unsigned>(time(0)));
    setlocale(LC_ALL, "Russian");
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

	int currentFloor = rand() % 9 + 1;

    Elevator elevator(1, 9, 1, currentFloor);

    cout << "===МЕНЮ==\n";
    cout << "Кто вы?\n";
	cout << "1. Пассажир\n";
	cout << "2. Диспетчер\n";
	int whoAreYou;
	cin >> whoAreYou;
    while (whoAreYou != 1 && whoAreYou != 2) {
        cout << "Ошибка! Введите 1 или 2: ";
        cin >> whoAreYou;
	}
    
    if (whoAreYou == 1) {
        if (elevator.getCurrentState()) {
            cout << "На каком этаже вы находитесь? (1-9): ";
            int passengerFloor;
            cin >> passengerFloor;
            while (passengerFloor < elevator.lowerFloor || passengerFloor > elevator.upperFloor) {
                cout << "Ошибка! Введите этаж от 1 до 9: ";
                cin >> passengerFloor;
            }
            cout << "Лифт прибыл, просьба войти.\n";
            cout << "На какой этаж вам нужно ехать?(1-9) Ваш выбор: ";
            int needFloor;
            cin >> needFloor;
            while ((needFloor < 1 || needFloor > 9) || needFloor == passengerFloor) {
                cout << "Ошибка! Вы ввели тот же или некоррекетный этаж! Введите нужный вам этаж: ";
                cin >> needFloor;
            }

            cout << "Лифт прибыл на нужный этаж. Просьба выйти.";
            ofstream fout("file_of_floor.txt");
            fout << needFloor;
            fout.close();
        }
        
        else {
            cout << "Лифт не работает. Приносим свои извинения.";
        }
    }

    else {
        cout << "=меню=\n";
        cout << "Что вы хотите?\n";
        cout << "1. Узнать, на каком этаже находится лифт.\n";
        cout << "2. Вкл/выкл лифт.\n";
        cout << "3. Узнать состояние лифта.\n";
        int dispatcherChoice;
        cin >> dispatcherChoice;
        while (dispatcherChoice != 1 && dispatcherChoice != 2 && dispatcherChoice != 3) {
            cout << "Ошибка! Введите 1 или 2: ";
            cin >> dispatcherChoice;
        }
        if (dispatcherChoice == 1) {
            cout << "Лифт находится на " << elevator.inWhatFloor() << " этаже.";
        }

        else if (dispatcherChoice == 2) {
            bool current_state = elevator.getCurrentState();
            if (current_state) {
				elevator.isWorks(0);
                cout << "Лифт выключен.";
            }
            else {
				elevator.isWorks(1);
                cout << "Лифт включён.";
			}
        }

        else if (dispatcherChoice == 3) {
            if (elevator.getCurrentState()) {
                cout << "Лифт работает.";
            }

            else {
                cout << "Лифт не работает.";
            }
		}
    }

    return 0;
}
