#include <iostream>
#include <windows.h>
#include <ctime>
#include <filesystem>
#include <fstream>
#include "PythonStyleSyntax.h"

using namespace std;
using namespace filesystem;

int main() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    setlocale(LC_ALL, "Russian");
    srand(static_cast<unsigned>(time(0)));
    
    int choose;
    print("Добро пожаловать в файловый менеджер. Текущий каталог - рабочий стол.\nВыберите опцию:\n1 - создание файла в текущем каталоге\n2 - удаление файла из текущего каталога\n3 - Копирование файла из текущего каталога\n4 - Вывод содержимого файла\n5 - Вывод файлов из текущего каталога");
	path current_path = "C:\\Users\\Bondarenko_ms\\Desktop\\";
	print("Ваш выбор: ");
	cin >> choose;

    if (choose == 1) {
        string name_of_file;
		print("Введите имя файла: ");
		cin >>  name_of_file;
        ofstream file(current_path / name_of_file);
        print("Файл создан.");
        
    }
    else if (choose == 2) {
        string name_of_file;
        cin >> name_of_file;
        if (exists(current_path / name_of_file)) {
            remove(current_path / name_of_file);
            print("Файл удалён.");
        }
        else {
            print("Файл не найден!");
            return 1;
        }
    }
    else if (choose == 3) {
        ofstream target_file("target.txt");
        string choose_file;
        print("Введите имя файла, который хотите скопировать: ");
        cin >> choose_file;
        if (!exists(current_path / choose_file)) {
            print("Файл не найден.");
            return 1;
        }
        enter;

        path from = current_path / choose_file;
        path to = current_path / "directory-1/test.txt";

        copy_file(from, to, copy_options::overwrite_existing);
        print("Файл скопирован.");
        
    }
    else if (choose == 4) {
        string choose_file_to_read;
        print("Содержимое какого файла вы хотите прочесть?");
        cin >> choose_file_to_read;
        if (!exists(current_path / choose_file_to_read)) {
            print("Такого файла не существует!");
            return 1;
        }
        
        ifstream readFile(current_path / choose_file_to_read);
        string line;
        while (getline(readFile, line)) {
            print(line);
            enter;
        }
    }
    else if (choose == 5) {
        string need_catalog;
        print("Содержимое какого каталога желаете вывести: ");
        cin >> need_catalog;
        if (!exists(current_path / need_catalog)) {
            print("Такого каталога не существует!");
            return 1;
        }
        else {
            for (const auto& entry : directory_iterator(current_path / need_catalog)) {
                print(entry.path());
                enter;
            }
        }
    }

    return 0;
}
