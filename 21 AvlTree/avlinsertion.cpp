#include <bits/stdc++.h>
using namespace std;

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    int height;

    Node(int value) : data(value), left(nullptr), right(nullptr), height(1) {}
};

int getHeight(Node* node) {
    if (node == nullptr) {
        return 0;
    }
    return node->height;
}

int getBalance(Node* node) {
    if (node == nullptr) {
        return 0;
    }
    return getHeight(node->left) - getHeight(node->right);
}

void updateHeight(Node* node) {
    if (node != nullptr) {
        int leftHeight = getHeight(node->left);
        int rightHeight = getHeight(node->right);
        node->height = 1 + max(leftHeight, rightHeight);
    }
}

// Right rotation for LL imbalance
Node* rotateRight(Node* node) {
    Node* newRoot = node->left;
    node->left = newRoot->right;
    newRoot->right = node;

    updateHeight(node);
    updateHeight(newRoot);

    return newRoot;
}

// Left rotation for RR imbalance
Node* rotateLeft(Node* node) {
    Node* newRoot = node->right;
    node->right = newRoot->left;
    newRoot->left = node;

    updateHeight(node);
    updateHeight(newRoot);

    return newRoot;
}

// Left-Right rotation for LR imbalance
Node* rotateLeftRight(Node* node) {
    node->left = rotateLeft(node->left);
    return rotateRight(node);
}

// Right-Left rotation for RL imbalance
Node* rotateRightLeft(Node* node) {
    node->right = rotateRight(node->right);
    return rotateLeft(node);
}

// Function to insert a value into the AVL tree
Node* insert(Node* root, int value) {
    if (root == nullptr) {
        return new Node(value);
    }

    if (value < root->data) {
        root->left = insert(root->left, value);
    } else if (value > root->data) {
        root->right = insert(root->right, value);
    } else {
        // Duplicate values are not allowed
        return root;
    }

    updateHeight(root);
    int balance = getBalance(root);

    // Perform rotations based on the balance factor
    if (balance > 1) { // Left-heavy
        if (value < root->left->data) { // LL case
            return rotateRight(root);
        } else { // LR case
            return rotateLeftRight(root);
        }
    } else if (balance < -1) { // Right-heavy
        if (value > root->right->data) { // RR case
            return rotateLeft(root);
        } else { // RL case
            return rotateRightLeft(root);
        }
    }

    return root;
}

void inOrder(Node* root) {
    if (root != nullptr) {
        inOrder(root->left);
        cout << root->data << " ";
        inOrder(root->right);
    }
}

int main() {
    Node* root = nullptr;

    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);  // Triggers RR rotation
    root = insert(root, 25);  // Triggers RL rotation
    root = insert(root, 5);
    root = insert(root, 15);  // Triggers LR rotation
    root = insert(root, 2);   // Triggers LL rotation

    inOrder(root);
    cout << endl;

    return 0;
}
