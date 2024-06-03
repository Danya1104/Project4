#pragma once
#include <string>
#include <algorithm>
#include "Hash.h"
#include "Table.h"
using namespace std;
class SortTable : public Table {
public:
    SortTable(int N) : Table(N) {}

    void sort() {
        std::sort(arr, arr + count, [](const Line& a, const Line& b) {
            return a.key < b.key;
            });
    }

    int binarySearch(const string& key) {
        int left = 0;
        int right = count - 1;
        eff = 0;
        while (left <= right) {
            eff++;
            int mid = left + (right - left) / 2;
            if (arr[mid].key == key) {
                return arr[mid].value;
            }
            if (arr[mid].key < key) {
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }
        eff++;
        return -1;
    }

    int find(const string& key) {

        if (count > 0) {
            sort(); // Ensure the array is sorted before binary search
            return binarySearch(key);
        }
        return -1;
    }





    void sortprint() {
        cout << "ќтсортированна€ таблица на массиве: " << endl;
        sort();
        for (int i = 0; i < count; ++i) {
            cout << arr[i].key << "\t\t" << arr[i].value << endl;
        }
        cout << "\n";
    }

    void printEfficiency() {
        cout << "Ёффективность отсорт. таблицы: " << eff << endl;
    }
};
