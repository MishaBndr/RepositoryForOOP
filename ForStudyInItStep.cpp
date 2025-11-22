#include "PythonStyleSyntax.h"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <windows.h>
#include <string>

using namespace std;

class Shape {
    static int count;
public:
    static double triangleArea_baseHeight(double base, double height) {
        count++;
        print("\nПлощадь треугольника: ");
        return 0.5 * base * height;
    }

    static double triangleArea_incircle(double a, double b, double c, double R) {
        count++;
        double p = (a + b + c) / 2.0;
        print("\nПлощадь треугольника: ");
        return p * R;
    }

    static double triangleArea_outcircle(double a, double b, double c, double R) {
        count++;
        print("\nПлощадь треугольника: ");
        return (a * b * c) / (4.0 * R);
    }

    static double rectangle(int width, int height) {
        count++;
        double S = width * height;
        print("\nПлощадь прямоугольника: ");
        return S;
    }

    static double square(int side) {
        count++;
        double S = side * side;
        print("\nПлощадь квадрата: ");
        return S;
    }

    static double rhombus(int d1, int d2) {
        count++;
        double S = 0.5 * d1 * d2;
        print("\nПлощадь ромба: ");
        return S;
    }

    static int getCount() { 
        print("\nБыло произведено подсчётов площадей фигур: ");
        return count; 
    }
}; 

int Shape::count = 0;


int main()
{
    srand(static_cast<unsigned>(time(0)));
    setlocale(LC_ALL, "Russian");
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    
    int choose;
    while (true) {
        print("===Меню===\nПлощадь какой фигуры вы хотите получить?\n1 - Треугольник\n2 - Прямоугольник\n3 - Квадрат\n4 - Ромб\n0 - Выйти из программы\nВаш выбор:");
        cin >> choose;
        if (choose == 1) {
            int choose_formula;
            print("\nКакой формулой вы желаете найти площадь треугольника?\n1 - По основанию и высоте\n2 - По радиусу вписанной окружности\n3 - По радиусу описанной окружности\nВаш выбор:");
            cin >> choose_formula;
            if (choose_formula == 1) {
                int base;
                int height;
                print("\nВведите длину основания треугольника:");
                cin >> base;
                print("\nВведите длину высоты треугольника:");
                cin >> height;
                print(Shape::triangleArea_baseHeight(base, height));
            }
            else if (choose_formula == 2) {
                int a, b, c, R;
                print("\nВведите первую сторону треугольника:");
                cin >> a;
                print("\nВведите вторую сторону треугольника:");
                cin >> b;
                print("\nВведите третью сторону треугольника:");
                cin >> c;
                print("\nВведите радиус вписанной окружности:");
                cin >> R;
                print(Shape::triangleArea_incircle(a, b, c, R));
            }
            else if (choose_formula == 3) {
                int a, b, c, R;
                print("\nВведите первую сторону треугольника:");
                cin >> a;
                print("\nВведите вторую сторону треугольника:");
                cin >> b;
                print("\nВведите третью сторону треугольника:");
                cin >> c;
                print("\nВведите радиус описанной окружности:");
                cin >> R;
                print(Shape::triangleArea_outcircle(a, b, c, R));
            }
        }
        else if (choose == 2) {
            int width, height;
            print("\nВведите длину ширины прямоугольника: ");
            cin >> width;
            print("\nВведите длину высоты прямоугольника: ");
            cin >> height;
            print(Shape::rectangle(width, height));
        }
        else if (choose == 3) {
            int side;
            print("\nВведите длину стороны квадрата: ");
            cin >> side;
            print(Shape::square(side));
        }
        else if (choose == 4) {
            int d1, d2;
            print("\nВведите длину первой диагонали ромба:");
            cin >> d1;
            print("\nВведите длину второй диагонали ромба:");
            cin >> d2;
            print(Shape::rhombus(d1, d2));
        }
        else if (choose == 0) {
            print(Shape::getCount());
            print("Всего доброго!");
            return 0;
        }
    }
    return 0;
}


