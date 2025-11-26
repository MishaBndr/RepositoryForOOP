#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <windows.h>
#include <string>
#include <cstring>
#include "PythonStyleSyntax.h"

using namespace std;

class Fraction {
    int numerator;
    int denominator;
public:
    explicit Fraction(int n, int d) : numerator(n), denominator(d) {}
    void display() const {
        cout << numerator << "/" << denominator << endl;
    }

    Fraction operator+(const Fraction& other) const {
        int first = (numerator * other.denominator) + (other.numerator * denominator);
        int second = denominator * other.denominator;
        cout << first << '/' << second;
        return Fraction(first, second);
    }

    Fraction operator-(const Fraction& other) const {
        int first = (numerator * other.denominator) - (other.numerator * denominator);
        int second = denominator * other.denominator;
        cout << first << '/' << second;
        return Fraction(first, second);
    }

    Fraction operator*(const Fraction& other) const {
        int first = numerator * other.numerator;
        int second = denominator * other.denominator;
        cout << first << '/' << second;
        return Fraction(first, second);
    }

    Fraction operator/(const Fraction& other) const {
        int first = numerator * other.denominator;
        int second = denominator * other.numerator;
        cout << first << '/' << second;
        return Fraction(first, second);
    }

};


int main()
{
    srand(static_cast<unsigned>(time(0)));
    setlocale(LC_ALL, "Russian");
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    int num1, den1;
    print("Введите числитель первой дроби:");
    input num1;
	print("Введите знаменатель первой дроби:");
    input den1;
    Fraction frac1(num1, den1);

    int num2, den2;
    print("Введите числитель второй дроби:");
    input num2;
	print("Введите знаменатель второй дроби:");
    input den2;
    Fraction frac2(num2, den2);

    print("Первая дробь:");
    frac1.display();
    print("Вторая дробь:");
    frac2.display();
    print("\nСложение:");
    frac1 + frac2;
    print("\nВычитание:");
    frac1 - frac2;
    print("\nУмножение:");
    frac1 * frac2;
    print("\nДеление:");
    frac1 / frac2;


    return 0;
}