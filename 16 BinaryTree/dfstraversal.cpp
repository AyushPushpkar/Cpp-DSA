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

// Inorder traversal function: Root -> Left -> Right
void inorder(Node* node) {        // tc : o(n)  // sc : o(n) auxilary space
    if (node == nullptr) return;
    
    // Recursively traverse the left subtree
    inorder(node->left);

    // Print the current node's data
    cout << node->data << " ";
    
    // Recursively traverse the right subtree
    inorder(node->right);
}

// Postorder traversal function: Root -> Left -> Right
void postorder(Node* node) {        // tc : o(n)  // sc : o(n) auxilary space
    if (node == nullptr) return;
    
    // Recursively traverse the left subtree
    postorder(node->left);

    // Recursively traverse the right subtree
    postorder(node->right);

    // Print the current node's data
    cout << node->data << " ";
    
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
    cout << endl ;

    // Call inorder traversal and print the tree
    inorder(root);
    cout << endl ;

    // Call postorder traversal and print the tree
    postorder(root);

    return 0;
}