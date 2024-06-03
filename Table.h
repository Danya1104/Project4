#include<iostream>
#include"Line.h"    
using namespace std;
class Table {
protected:
    int MAX;
    int count;
    Line* arr;
    int eff;

public:
    Table(int N) {
        arr = new Line[N];
        MAX = N;
        count = 0;
        eff = 0;
    }

    ~Table() {
        delete[] arr;
    }

    int find(const string& key) {
        eff = 0;
        for (int i = 0; i < count; ++i) {
            eff++;
            if (arr[i].key == key) {
                return arr[i].value;
            }
        }
        eff++;
        return -1;
    }

    void insert(int value, const string& key) {
        if (count < MAX) {
            for (int i = 0; i < count; i++) {
                if (arr[i].key == key) {
                    arr[i].value += value;
                    return;
                }
            }
            arr[count] = Line(value, key);

            count++;

        }
        else {
            cout << "Просматриваемая/отсортированная таблица заполнена. Значение не будет сохранено." << endl;
        }

    }

    void remove(const string& key) {
        for (int i = 0; i < count; ++i) {
            if (arr[i].key == key) {
                // Shift elements to fill the gap
                for (int j = i; j < count - 1; ++j) {
                    arr[j] = arr[j + 1];
                }
                count--;
                return;
            }
        }
        cout << "Значение не найдено." << endl;
    }
    void print() {
        cout << "Просматриваемая таблица на массиве: " << endl;
        for (int i = 0; i < count; ++i) {
            cout << arr[i].key << "\t\t" << arr[i].value << endl;
        }
        cout << "\n";
    }

    void printEfficiency() {
        cout << "Эффективность на массиве: " << eff << endl;
    }

    Table() = default;
};