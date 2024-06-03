#include "AVLTree.h"
#include"Table.h"
#include <iostream>
using namespace std;
class TreeTable : public Table {
private:
    AVLTree tree;

public:
    TreeTable(int N) : Table(N) {}

    void insert(int value, const string& key) {
        tree.root = tree.insert(tree.root, value, key);
    }

    int find(const string& key) {
        TreeNode* result = tree.search(tree.root, key);
        return result ? result->value : -1;
    }

    void remove(const string& key) {
        tree.root = tree.deleteNode(tree.root, key);
    }

    void print() {
        cout << "ƒревовидна€ таблица (AVL-дерево): " << endl;
        tree.inOrder(tree.root);
        cout << "\n";
    }

    void printEfficiency() {

        cout << "Ёффективность древовидной таблицы: " << eff << endl;
    }
};