#include <iostream>
#include <windows.h>
#include <vector>
#include "PythonStyleSyntax.h"
#include <string>

using namespace std;

class Book {
    string title;
    string author;
	int year;
public:
    Book(string t, string a, int y) : title(t), author(a), year(y) {}

    void display() {
        cout << "Title: " << title << ", Author: " << author << ", Year: " << year << endl;
	}

	int getYear() {
		return year;
	}

};

int main()
{
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    setlocale(LC_ALL, "Russian");

	Book book1("Война и мир", "Лев Толстой", 1869);
	Book book2("Преступление и наказание", "Фёдор Достоевский", 1866);
    Book book3("Древний: Предыстория \"Истоки\"", "Сергей Тармашев", 2015);
    Book book4("Ареал \"Заражение\"", "Сергей Тармашев", 2010);
	Book book5("Метро 2033", "Дмитрий Глуховский", 2005);
    Book book6("Наследие", "Сергей Тармашев", 2010);

	vector<Book> library = { book1, book2, book3, book4, book5, book6 };

	int choose;
	while (true) {
		print("Выберите действие:\n1 - добавить новую книгу.\n2 - вывести все книги.\n3 - показать книги, изданные после определенного года, выбранного вами.\n4 - показать старейшую книгув библиотеке.");
		input(choose);
		if (choose == 1) {
			string t, a;
			int y;
			print("Введите название книги:");
			input(t);
			print("Введите автора книги:");
			input(a);
			print("Введите год издания книги:");
			input(y);
			Book newBook(t, a, y);
			library.push_back(newBook);
			print("Книга добавлена в библиотеку.");
		}

		else if (choose == 2) {
			print("Все книги в библиотеке:");
			for (auto& book : library) {
				book.display();
			}
		}

		else if (choose == 3) {
			int year;
			print("Введите год:");
			input(year);
			print("Книги, изданные после " + to_string(year) + ":");
			for (auto& book : library) {
				if (book.getYear() > year) {
					book.display();
				}
			}
		}

		else if (choose == 4) {
			if (!library.empty()) {
				Book* oldestBook = &library[0];
				for (auto& book : library) {
					if (book.getYear() < oldestBook->getYear()) {
						oldestBook = &book;
					}
				}
				print("Старейшая книга в библиотеке:");
				oldestBook->display();
			}
			else {
				print("Библиотека пуста.");
			}
		}
		else {
			print("Некорректный выбор. Пожалуйста, попробуйте снова.");
		}
	}
	

    return 0;
}

