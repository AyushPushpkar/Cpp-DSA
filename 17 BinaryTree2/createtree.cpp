#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *lchild;
    Node *rchild;

    Node(int value) : data(value), lchild(nullptr), rchild(nullptr) {}
};

Node* create() {
    int x;
    cout << "Enter node value (-1 for no node): " << endl;
    cin >> x;

    // Base case: terminate recursion if user enters -1
    if (x == -1) {
        return nullptr;
    }

    // Create the current node
    Node* newNode = new Node(x);

    // Create left child
    cout << "Enter left child of " << x << ":\n";
    newNode->lchild = create();

    // Create right child
    cout << "Enter right child of " << x << ":\n";
    newNode->rchild = create();
    

    return newNode;
}

void preorder(Node* node) {
    if (node) {
        cout << node->data << " ";
        preorder(node->lchild);
        preorder(node->rchild);
    }
}

int main() {
    cout << "Create the binary tree:\n";
    Node* root = create();

    cout << "Preorder traversal: " << endl;
    preorder(root);

    return 0;
}
