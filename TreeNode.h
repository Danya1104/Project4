#pragma once
#include <string>
using namespace std;
class TreeNode {
public:
    int value;
    string key;
    int height;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int v, string k) : value(v), key(k), height(1), left(nullptr), right(nullptr) {}
};