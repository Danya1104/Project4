#pragma once
#include "TreeNode.h"
#include <chrono>
#include <string>
#include <iostream>
using namespace std;
class AVLTree {
public:
    TreeNode* root;

    AVLTree() : root(nullptr) {}

    int height(TreeNode* node) {
        return node ? node->height : 0;
    }

    int balanceFactor(TreeNode* node) {
        return node ? height(node->left) - height(node->right) : 0;
    }

    TreeNode* rightRotate(TreeNode* y) {
        TreeNode* x = y->left;
        TreeNode* T2 = x->right;

        x->right = y;
        y->left = T2;

        y->height = max(height(y->left), height(y->right)) + 1;
        x->height = max(height(x->left), height(x->right)) + 1;

        return x;
    }

    TreeNode* leftRotate(TreeNode* x) {
        TreeNode* y = x->right;
        TreeNode* T2 = y->left;

        y->left = x;
        x->right = T2;

        x->height = max(height(x->left), height(x->right)) + 1;
        y->height = max(height(y->left), height(y->right)) + 1;

        return y;
    }

    TreeNode* insert(TreeNode* node, int value, const string& key) {
        if (!node)
            return new TreeNode(value, key);

        if (key < node->key)
            node->left = insert(node->left, value, key);
        else if (key > node->key)
            node->right = insert(node->right, value, key);
        else {
            node->value += value;
            return node;
        }

        node->height = 1 + max(height(node->left), height(node->right));

        int balance = balanceFactor(node);

        if (balance > 1 && key < node->left->key)
            return rightRotate(node);

        if (balance < -1 && key > node->right->key)
            return leftRotate(node);

        if (balance > 1 && key > node->left->key) {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }

        if (balance < -1 && key < node->right->key) {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }

        return node;
    }

    TreeNode* minValueNode(TreeNode* node) {
        TreeNode* current = node;

        while (current->left != nullptr)
            current = current->left;

        return current;
    }

    TreeNode* deleteNode(TreeNode* root, const string& key) {
        if (!root)
            return root;

        if (key < root->key)
            root->left = deleteNode(root->left, key);
        else if (key > root->key)
            root->right = deleteNode(root->right, key);
        else {
            if (!root->left || !root->right) {
                TreeNode* temp = root->left ? root->left : root->right;

                if (!temp) {
                    temp = root;
                    root = nullptr;
                }
                else
                    *root = *temp;
                delete temp;
            }
            else {
                TreeNode* temp = minValueNode(root->right);
                root->key = temp->key;
                root->value = temp->value;
                root->right = deleteNode(root->right, temp->key);
            }
        }

        if (!root)
            return root;

        root->height = max(height(root->left), height(root->right)) + 1;

        int balance = balanceFactor(root);

        if (balance > 1 && balanceFactor(root->left) >= 0)
            return rightRotate(root);

        if (balance > 1 && balanceFactor(root->left) < 0) {
            root->left = leftRotate(root->left);
            return rightRotate(root);
        }

        if (balance < -1 && balanceFactor(root->right) <= 0)
            return leftRotate(root);

        if (balance < -1 && balanceFactor(root->right) > 0) {
            root->right = rightRotate(root->right);
            return leftRotate(root);
        }

        return root;
    }

    TreeNode* search(TreeNode* root, const string& key) {
        int eff = 0;
        if (!root || root->key == key) {
            eff++;
            return root;
        }


        if (key < root->key) {
            eff++;
            return search(root->left, key);
        }

        eff++;
        return search(root->right, key);
    }

    void inOrder(TreeNode* root) {
        if (root != nullptr) {
            inOrder(root->left);
            cout << root->key << "\t\t" << root->value << endl;
            inOrder(root->right);
        }
    }
};