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

        cout << "1. ������ �������� � �������: " << endl;
        cout << "2. ������� �������" << endl;
        cout << "3. �������� ��� ��������" << endl;

        cout << "0. �����" << endl;
        cout << "������� ���� �����: ";
        cin >> choice;




        switch (choice) {
        case 1: {
            cout << "������� ������(�����, ��������): ";
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
                cout << "1. ��������" << endl;
                cout << "2. �������" << endl;
                cout << "3. �����" << endl;
                cout << "0. ��������� � ����\n";
                cout << "������� ���� �����: ";
                cin >> operationChoice;

                switch (operationChoice) {
                case 1:
                    cout << "������� ������(�����, �����): ";
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
                    cout << "������� �����: ";
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
                    cout << "������� �����: ";
                    cin >> key;
                    auto start = chrono::high_resolution_clock::now();

                    // ��������� �������� ������ � ��������������� �������

                    
                   
                    if (table.find(key) == -1)
                        cout << "�������� �� �������" << endl;
                    else {
                        cout << "��������: " << table.find(key) << endl;
                    }
                    if (table2.find(key) == -1)
                        cout << "�������� �� �������" << endl;
                    else {
                        cout << "��������: " << table2.find(key) << endl;
                    }
                    if (table3.find(key) == -1)
                        cout << "�������� �� �������" << endl;
                    else {
                        cout << "��������: " << table3.find(key) << endl;
                    }
                    if (hashtable.find(key) == -1)
                        cout << "�������� �� �������" << endl;
                    else {
                        cout << "��������: " << hashtable.find(key) << endl;
                    }
                    if (tree.find(key) == -1)
                        cout << "�������� �� �������" << endl;
                    else {
                        cout << "��������: " << tree.find(key) << endl;
                    }
                    auto end = chrono::high_resolution_clock::now();
                    duration = chrono::duration_cast<chrono::microseconds>(end - start);
                    cout << "����� ������: " << duration.count() << " �����������" << endl;
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
            cout << "�������� �����. �������� �����." << endl;
        }
    } while (choice != 0);

    return 0;
}