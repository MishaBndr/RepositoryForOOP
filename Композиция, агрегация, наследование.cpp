#include <windows.h>
#include <iostream>
#include <string>
#include "PythonStyleSyntax.h"

using namespace std;

class Vehicle {
    string brand;
    int year;
public:
    Vehicle(string b, int y) : brand{ b }, year{ y } {}
    void start() {
        cout << "The " << brand << " is started" << "\n";
    }

    void displayInfo() {
        cout << "Brand: " << brand << "\n";
        cout << "Year: " << year << "\n";
    }
};

class Car : public Vehicle {
    int numDoors;
public:
	Car(string b, int y, int d) : Vehicle{ b, y }, numDoors{ d } {}

    void displayInfo() {
        Vehicle::displayInfo();
        cout << "Number of doors: " << numDoors << "\n";
	}
};

int main()
{
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    setlocale(LC_ALL, "Russian");
	Vehicle vehicle("Toyota", 2020);

    vehicle.start();

    vehicle.displayInfo();

	Car car("Honda", 2021, 4);

    car.start();

    car.displayInfo();
	return 0;
}

