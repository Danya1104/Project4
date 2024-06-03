#include <list>
#include <string>
#include "Line.h"
#include "Table.h"
#include <iostream>
using namespace std;
class Hash : public Table {

private:
    list<Line>* arr;
    int count;
    int MAX;

public:
    Hash(int N) : Table(N), MAX(N), count(0) {
        arr = new list<Line>[MAX];
    }

    ~Hash() {
        delete[] arr;
    }

    int hash(string key) {
        int sum = 0;
        for (int i = 0; i < key.length(); i++) {
            sum += key[i] * (i + 1);
        }
        return sum % MAX;
    }

    void insert(int value, string key) {
        int i = hash(key);
        bool keyExists = false;
        for (auto& entry : arr[i]) {
            if (entry.key == key) {
                entry.value = value;
                keyExists = true;
                break;
            }
        }
        if (!keyExists) {
            arr[i].push_back(Line(value, key));
            count++;
        }
    }

    int find(const string& key) {
        int i = hash(key);
        eff = 0;
        for (const auto& entry : arr[i]) {
            eff++;
            if (entry.key == key) {
                return entry.value;
            }
        }
        eff++; // Добавлено для учета последней итерации
        return -1;
    }

    void remove(const string& key) {
        int i = hash(key);
        for (auto it = arr[i].begin(); it != arr[i].end(); ++it) {
            if (it->key == key) {
                arr[i].erase(it);
                count--;
                return;
            }
        }
        cout << "Значение не найдено." << endl;
    }

    void print() {
        cout << "Хеш-таблица: " << endl;
        for (int i = 0; i < MAX; i++) {

            for (const auto& entry : arr[i]) {
                cout << i << "\t" << entry.key << "\t\t" << entry.value << endl;
            }

        }
    }


    void printEfficiency() {
        cout << "Эффективность хеш-таблицы: " << eff << endl;
    }
};