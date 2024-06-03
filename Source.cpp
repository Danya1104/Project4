#include <iostream>
#include <string>
#include <locale>
#include <codecvt>
#include <vector>
#include <algorithm>
#include <list>
#include <chrono>
#include "TTable.h"
#include "SortTable.h"
#include "TreeTable.h"
#include"AVLTree.h"
#include"Hash.h"

using namespace std;
int main() {

    setlocale(LC_ALL, "Russian");

    int N = 5;
    int choice, value;
    string key;
    TTable table2;
    Table table(N);
    SortTable table3(N);
    Hash hashtable(N);
    TreeTable tree(N);
    chrono::microseconds duration;

    do {

        cout << "1. Ввести значение в таблицу: " << endl;
        cout << "2. Вывести таблицу" << endl;
        cout << "3. Операции над таблицей" << endl;

        cout << "0. Выйти" << endl;
        cout << "Введите свой выбор: ";
        cin >> choice;




        switch (choice) {
        case 1: {
            cout << "Введите данные(слово, значение): ";
            cin >> key >> value;
            table.insert(value, key);
            table2.insert(value, key);
            table3.insert(value, key);
            hashtable.insert(value, key);
            tree.insert(value, key);
            break;

        }
        case 2: {
            table.print();
            table2.print();
            table3.sortprint();
            hashtable.print();
            tree.print();

            break;
        }
        case 3: {
            int operationChoice;
            do {
                cout << "1. Добавить" << endl;
                cout << "2. Удалить" << endl;
                cout << "3. Найти" << endl;
                cout << "0. Вернуться в меню\n";
                cout << "Введите свой выбор: ";
                cin >> operationChoice;

                switch (operationChoice) {
                case 1:
                    cout << "Введите данные(слово, число): ";
                    cin >> key >> value;
                    table.insert(value, key);
                    table2.insert(value, key);
                    table3.insert(value, key);
                    hashtable.insert(value, key);
                    tree.insert(value, key);
                    table.print();
                    table2.print();
                    table3.sortprint();
                    hashtable.print();
                    tree.print();
                    break;
                case 2:
                    cout << "Введите слово: ";
                    cin >> key;
                    table.remove(key);
                    table2.remove(key);
                    table3.remove(key);
                    hashtable.remove(key);
                    tree.remove(key);
                    table.print();
                    table2.print();
                    table3.sortprint();
                    hashtable.print();
                    tree.print();
                    break;
                case 3:
                    cout << "Введите слово: ";
                    cin >> key;
                    auto start = chrono::high_resolution_clock::now();

                    // Выполняем операцию поиска в соответствующей таблице

                    
                   
                    if (table.find(key) == -1)
                        cout << "Значение не найдено" << endl;
                    else {
                        cout << "Значение: " << table.find(key) << endl;
                    }
                    if (table2.find(key) == -1)
                        cout << "Значение не найдено" << endl;
                    else {
                        cout << "Значение: " << table2.find(key) << endl;
                    }
                    if (table3.find(key) == -1)
                        cout << "Значение не найдено" << endl;
                    else {
                        cout << "Значение: " << table3.find(key) << endl;
                    }
                    if (hashtable.find(key) == -1)
                        cout << "Значение не найдено" << endl;
                    else {
                        cout << "Значение: " << hashtable.find(key) << endl;
                    }
                    if (tree.find(key) == -1)
                        cout << "Значение не найдено" << endl;
                    else {
                        cout << "Значение: " << tree.find(key) << endl;
                    }
                    auto end = chrono::high_resolution_clock::now();
                    duration = chrono::duration_cast<chrono::microseconds>(end - start);
                    cout << "Время поиска: " << duration.count() << " микросекунд" << endl;
                    table.printEfficiency();
                    table2.printEfficiency();
                    table3.printEfficiency();
                    hashtable.printEfficiency();
                    tree.printEfficiency();
                    break;
               

                }
            } while (operationChoice != 0);

        }

        case 0:
            break;
        default:
            cout << "Неверный выбор. Пробуйте снова." << endl;
        }
    } while (choice != 0);

    return 0;
}