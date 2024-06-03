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
#include "AVLTree.h"
#include "Hash.h"
#include <iomanip>

using namespace std;

struct SearchResult {
    string tableName;
    int value;
    chrono::microseconds duration;
};

void showMainMenu();
void showOperationsMenu();
void handleInsert(Table& table, TTable& table2, SortTable& table3, Hash& hashtable, TreeTable& tree);
void handlePrint(Table& table, TTable& table2, SortTable& table3, Hash& hashtable, TreeTable& tree);
void handleOperations(Table& table, TTable& table2, SortTable& table3, Hash& hashtable, TreeTable& tree);
void printSearchResults(const vector<SearchResult>& results, Table& table, TTable& table2, SortTable& table3, Hash& hashtable, TreeTable& tree);

int main() {
    setlocale(LC_ALL, "Russian");

    int N = 5;
    int choice;
    TTable table2;
    Table table(N);
    SortTable table3(N);
    Hash hashtable(N);
    TreeTable tree(N);

    do {
        showMainMenu();
        cin >> choice;

        switch (choice) {
        case 1:
            handleInsert(table, table2, table3, hashtable, tree);
            break;
        case 2:
            handlePrint(table, table2, table3, hashtable, tree);
            break;
        case 3:
            handleOperations(table, table2, table3, hashtable, tree);
            break;
        case 0:
            cout << "Выход из программы." << endl;
            break;
        default:
            cout << "Неверный выбор. Пробуйте снова." << endl;
        }
    } while (choice != 0);

    return 0;
}

void showMainMenu() {
    cout << "=== Главное меню ===" << endl;
    cout << "1. Ввести значение в таблицу" << endl;
    cout << "2. Вывести таблицу" << endl;
    cout << "3. Операции над таблицей" << endl;
    cout << "0. Выйти" << endl;
    cout << "Введите свой выбор: ";
}

void showOperationsMenu() {
    cout << "=== Операции над таблицей ===" << endl;
    cout << "1. Добавить" << endl;
    cout << "2. Удалить" << endl;
    cout << "3. Найти" << endl;
    cout << "0. Вернуться в меню" << endl;
    cout << "Введите свой выбор: ";
}

void handleInsert(Table& table, TTable& table2, SortTable& table3, Hash& hashtable, TreeTable& tree) {
    string key;
    int value;
    cout << "Введите данные (слово, значение): ";
    cin >> key >> value;
    table.insert(value, key);
    table2.insert(value, key);
    table3.insert(value, key);
    hashtable.insert(value, key);
    tree.insert(value, key);
}

void handlePrint(Table& table, TTable& table2, SortTable& table3, Hash& hashtable, TreeTable& tree) {
    table.print();
    table2.print();
    table3.sortprint();
    hashtable.print();
    tree.print();
}

void handleOperations(Table& table, TTable& table2, SortTable& table3, Hash& hashtable, TreeTable& tree) {
    int operationChoice;
    string key;
    int value;

    do {
        showOperationsMenu();
        cin >> operationChoice;

        switch (operationChoice) {
        case 1:
            cout << "Введите данные (слово, значение): ";
            cin >> key >> value;
            table.insert(value, key);
            table2.insert(value, key);
            table3.insert(value, key);
            hashtable.insert(value, key);
            tree.insert(value, key);
            handlePrint(table, table2, table3, hashtable, tree);
            break;
        case 2:
            cout << "Введите слово: ";
            cin >> key;
            table.remove(key);
            table2.remove(key);
            table3.remove(key);
            hashtable.remove(key);
            tree.remove(key);
            handlePrint(table, table2, table3, hashtable, tree);
            break;
        case 3:
            cout << "Введите слово: ";
            cin >> key;

            vector<SearchResult> results;
            auto start = chrono::high_resolution_clock::now();
            int valueTable = table.find(key);
            auto end = chrono::high_resolution_clock::now();
            results.push_back({ "Table", valueTable, chrono::duration_cast<chrono::microseconds>(end - start) });

            start = chrono::high_resolution_clock::now();
            int valueTable2 = table2.find(key);
            end = chrono::high_resolution_clock::now();
            results.push_back({ "TTable", valueTable2, chrono::duration_cast<chrono::microseconds>(end - start) });

            start = chrono::high_resolution_clock::now();
            int valueTable3 = table3.find(key);
            end = chrono::high_resolution_clock::now();
            results.push_back({ "SortTable", valueTable3, chrono::duration_cast<chrono::microseconds>(end - start) });

            start = chrono::high_resolution_clock::now();
            int valueHashTable = hashtable.find(key);
            end = chrono::high_resolution_clock::now();
            results.push_back({ "Hash", valueHashTable, chrono::duration_cast<chrono::microseconds>(end - start) });

            start = chrono::high_resolution_clock::now();
            int valueTreeTable = tree.find(key);
            end = chrono::high_resolution_clock::now();
            results.push_back({ "TreeTable", valueTreeTable, chrono::duration_cast<chrono::microseconds>(end - start) });

            printSearchResults(results, table, table2, table3, hashtable, tree);
            break;
        }
    } while (operationChoice != 0);
}

void printSearchResults(const vector<SearchResult>& results, Table& table, TTable& table2, SortTable& table3, Hash& hashtable, TreeTable& tree) {
    cout << "===============================================================================" << endl;
    cout << "| Таблица     | Значение       | Время (мкс) | Эффективность                |" << endl;
    cout << "===============================================================================" << endl;
    for (const auto& result : results) {
        cout << "| " << setw(11) << left << result.tableName << " | "
            << setw(13) << (result.value == -1 ? "Не найдено" : to_string(result.value)) << " | "
            << setw(11) << result.duration.count() << " | ";

        if (result.tableName == "Table") {
            table.printEfficiency();
        }
        else if (result.tableName == "TTable") {
            table2.printEfficiency();
        }
        else if (result.tableName == "SortTable") {
            table3.printEfficiency();
        }
        else if (result.tableName == "Hash") {
            hashtable.printEfficiency();
        }
        else if (result.tableName == "TreeTable") {
            tree.printEfficiency();
        }
    }
    cout << "===============================================================================" << endl;
}

