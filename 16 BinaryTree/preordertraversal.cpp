#include <bits/stdc++.h>
using namespace std;

//DFS - depth first search

// Define the structure of the Node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;

    // Constructor to initialize the node with a value
    Node(int value) {
        data = value;
        left = right = nullptr;
    }
};

// Preorder traversal function: Root -> Left -> Right
void preorder(Node* node) {        // tc : o(n)  // sc : o(n) auxilary space
    if (node == nullptr) return;

    // Print the current node's data
    cout << node->data << " ";
    
    // Recursively traverse the left subtree
    preorder(node->left);
    
    // Recursively traverse the right subtree
    preorder(node->right);
}

int main() {
    // Create the root node
    struct Node* root = new Node(1);

    // Create and attach child nodes
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->right = new Node(4);

    // Call preorder traversal and print the tree
    preorder(root);

    return 0;
}
