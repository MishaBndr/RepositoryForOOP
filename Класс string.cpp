#include <iostream>
#include <string>
#include <vector>
#include <windows.h>
#define AtR ArabicNumberToRoman
using namespace std;

//ИЗ АРАБСКОЙ В РИМСКУЮ

//string toRoman(int num) {
//    vector<pair<int, string>> roman = {
//        {1000, "M"}, {900, "CM"}, {500, "D"},  {400, "CD"},
//        {100,  "C"}, {90,  "XC"}, {50,  "L"},  {40,  "XL"},
//        {10,   "X"}, {9,   "IX"}, {5,   "V"},  {4,   "IV"},
//        {1,    "I"}
//    };
//
//    string result = "";
//
//    for (const auto& pair : roman) {
//        int value = pair.first;
//        const string& symbol = pair.second;
//
//        while (num >= value) {
//            result += symbol;
//            num -= value;
//        }
//    }
//
//    return result;
//}
//
//string AtR(const string& input) {
//    int num = 0;
//    for (char c : input) {
//        if (c < '0' || c > '9') {
//            return "Ошибка: строка содержит недопустимые символы";
//        }
//        num = num * 10 + (c - '0');
//    }
//
//    if (num <= 0 || num > 4000) {
//        return "Ошибка: число должно быть от 1 до 4000";
//    }
//
//    return toRoman(num);
//}

//ЗАДАНИЕ С ПУТЁМ ФАЙЛА

void filePath(const string& filepath) {
    
    int x;
    while (true) {
        cout << "\nВыберите желаемую опцию.\n1 - Путь без имени файла.\n2 - Имя последней папки в пути.\n3 - Имя файла с расширением, но без пути.\n4 - Расширение имени файла.\n5 - Имя файла без пути и расширения.\nВаш выбор: ";
        cin >> x;
        if (x == 1) {
            cout << filepath.substr(0, filepath.rfind("\\"));
        }
        else if (x == 2) {
            string path = filepath.substr(0, filepath.rfind("\\"));
            cout << path.substr(path.rfind("\\") + 1);
        }
        else if (x == 3) {
            cout << filepath.substr(filepath.rfind("\\" + 1));
        }
        else if (x == 4) {
            cout << filepath.substr(filepath.rfind("."));
        }
        else if (x == 5) {
            string filename = filepath.substr(filepath.rfind("\\") + 1);
            cout << filename.substr(0, filename.rfind("."));
        }
        else {
            cout << "Некорректный выбор.";
        }
    }
    
}

int main() {
    setlocale(LC_ALL, "Russian");
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

	// ИЗ АРАБСКОЙ В РИМСКУЮ

    /*string input;
    cout << "Введите натуральное число (1-4000): ";
    cin >> input;

    string roman = ArabicNumberToRoman(input);
    cout << "Римская запись: " << roman << endl;*/

    //ЗАДАНИЕ С ПУТЁМ ФАЙЛА

	string s = "C:\\Step\\С++lesson_03\\Docs\\Less03.docx";

	filePath(s);


    return 0;
}

