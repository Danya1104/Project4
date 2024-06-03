#pragma once
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

    int find(const std::string& key) {
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

    void insert(int value, const std::string& key) {
        if (count < MAX)
        {
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
            std::cout << "Просматриваемая/отсортированная таблица заполнена. Значение не будет сохранено." << std::endl;
        }

    }

    void remove(const std::string& key) {
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
        std::cout << "Значение не найдено." << std::endl;
    }
    void print() {
        std::cout << "Просматриваемая таблица на массиве: " << std::endl;
        for (int i = 0; i < count; ++i) {
            std::cout << arr[i].key << "\t\t" << arr[i].value << std::endl;
        }
        std::cout << "\n";
    }

    void printEfficiency() {
        std::cout << "Эффективность на массиве: " << eff << std::endl;
    }
};
