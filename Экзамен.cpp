#include <iostream>
#include <filesystem>
#include <fstream>

using namespace std;
using namespace filesystem;

// Класс для базовых операций с файловой системой
class FileSystemObject {
protected:
    path p;
public:
    FileSystemObject(const path& p) : p(p) {}
    virtual void info() = 0;
};

// Класс для папок
class Directory : public FileSystemObject {
public:
    Directory(const path& p) : FileSystemObject(p) {}

    void info() override {
        cout << "Содержимое директории: " << p << "\n";
        if (exists(p) && is_directory(p)) {
            for (auto& entry : directory_iterator(p))
                cout << entry.path().filename().string() << "\n";
        }
    }

    bool createDir(const string& name) {
        return create_directory(p / name);
    }

    bool removeDir(const string& name) {
        return remove(p / name);
    }

    bool renameDir(const string& newName) {
        rename(p, p.parent_path() / newName);
        return true;
    }

    void copyTo(const path& dest) {
        copy(p, dest, copy_options::recursive);
    }
};

// Класс для файлов
class File : public FileSystemObject {
public:
    File(const path& p) : FileSystemObject(p) {}

    void info() override {
        cout << "Информация о файле: " << p << "\n";
        if (exists(p)) cout << "Размер: " << file_size(p) << " байт\n";
    }

    bool createFile() {
        ofstream f(p);
        return f.is_open();
    }

    bool removeFile() {
        return remove(p);
    }

    bool renameFile(const string& newName) {
        rename(p, p.parent_path() / newName);
        return true;
    }
};

// Менеджер файловой системы
class FileManager {
public:
    void showDisks() {
        cout << "Диски: C:\\\n";
    }

    void showDirectory(const path& p) {
        Directory d(p);
        d.info();
    }

    void createDirectory(const path& p, const string& name) {
        Directory d(p);
        if (d.createDir(name)) cout << "Папка создана.\n";
        else cout << "Ошибка создания папки.\n";
    }

    void createFile(const path& p, const string& name) {
        File f(p / name);
        if (f.createFile()) cout << "Файл создан.\n";
        else cout << "Ошибка создания файла.\n";
    }

    void removeDirectory(const path& p, const string& name) {
        Directory d(p);
        if (d.removeDir(name)) cout << "Папка удалена.\n";
        else cout << "Ошибка удаления папки.\n";
    }

    void removeFile(const path& p, const string& name) {
        File f(p / name);
        if (f.removeFile()) cout << "Файл удалён.\n";
        else cout << "Ошибка удаления файла.\n";
    }

    void renameDirectory(const path& p, const string& newName) {
        Directory d(p);
        d.renameDir(newName);
        cout << "Папка переименована.\n";
    }

    void renameFile(const path& p, const string& newName) {
        File f(p);
        f.renameFile(newName);
        cout << "Файл переименован.\n";
    }

    void copyDirectory(const path& from, const path& to) {
        Directory d(from);
        d.copyTo(to);
        cout << "Папка скопирована.\n";
    }
};

int main() {
    setlocale(LC_ALL, "Russian");

    FileManager fm;

    int choose;
    while (true) {
        cout << "Добро пожаловать в файловый менеджер. Выберите опцию:\n1 — Показать содержимое диска\n2 — Создать папку/файл\n3 — Удалить папку/файл\n4 — Переименовать папку/файл\n5 — Копировать папку\n";

        cin >> choose;

        if (choose == 1) {
            fm.showDirectory("C:/");
        }
        else if (choose == 2) {
            cout << "Что вы желаете создать?\n1 - Папку.\n2 - Файл.";
            int t; 
            cin >> t;
            path p; 
            string name;
            cout << "Введите путь: "; 
            cin >> p;
            cout << "Введите имя: "; 
            cin >> name;
            if (t == 1) {
                fm.createDirectory(p, name);
            }
            else {
                fm.createFile(p, name);
            }
        }
        else if (choose == 3) {
            cout << "Что вы желаете удалить?\n1 - Папку.\n2 - Файл.";
            int t; 
            cin >> t;
            path p; 
            string name;
            cout << "Введите путь: "; 
            cin >> p;
            cout << "Введите имя: "; 
            cin >> name;
            if (t == 1) fm.removeDirectory(p, name);
            else fm.removeFile(p, name);
        }
        else if (choose == 4) {
            cout << "Что вы желаете переименовать?\n1 - Папку.\n2 - Файл.";
            int t; 
            cin >> t;
            path p; 
            string name;
            cout << "Введите путь: "; 
            cin >> p;
            cout << "Введите новое имя: "; 
            cin >> name;
            if (t == 1) fm.renameDirectory(p, name);
            else fm.renameFile(p, name);
        }
        else if (choose == 5) {
            path from, to;
            cout << "Введите путь источника: "; 
            cin >> from;
            cout << "Введите путь назначения: "; 
            cin >> to;
            fm.copyDirectory(from, to);
        }

    }
    
    return 0;
}
