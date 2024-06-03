#include <vector>
#include<iostream>
#include "TLine.h"
#include <string>
using namespace std;
class TTable {
private:
    vector<TLine> lines;
    int eff;

public:
    void insert(int value, string key) {
        for (auto& line : lines) {
            if (line.key == key) {
                line.value += value;
                return;
            }
        }
        lines.push_back(TLine(value, key));
    }

    void remove(string key) {
        lines.erase(remove_if(lines.begin(), lines.end(), [key](const TLine& line) { return line.key == key; }), lines.end());
    }

    int find(const string& key) {
        eff = 0;
        for (const auto& line : lines) {
            eff++;
            if (line.key == key) {
                return line.value;
            }
        }
        eff++;
        return -1;
    }

    void print() {
        setlocale(LC_ALL, "Russian");
        cout << "Просматриваемая таблица на списках: " << endl;
        for (const auto& line : lines) {
            cout << line.key << "\t\t" << line.value << endl;
        }
        cout << "\n";
    }

    void printEfficiency() {
        cout << "Эффективность на списках: " << eff << endl;
    }
};