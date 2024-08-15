#include <bits/stdc++.h>
using namespace std;

//height(left) - height(right) <= 1

struct Node {
    int val;
    struct Node* left;
    struct Node* right;

    Node(int value) {
        val = value;
        left = right = nullptr;
    }
};

bool identical(Node* p , Node*q) {        // tc : o(n)  // sc : o(n) auxilary space
    if (p == nullptr || q == nullptr) return (p==q);

    return (p->val == q->val)
    && identical(p->left , q->left) 
    && identical(p->right , q->right ) ;
}

int main() {

    struct Node* root = new Node(1);

    root->left = new Node(2);
    root->right = new Node(3);
    root->left->right = new Node(4);
    root -> right -> left = new Node(5) ;
    root -> right -> right = new Node(6) ;

    struct Node* root2 = new Node(1);

    root2->left = new Node(2);
    root2->right = new Node(3);
    root2->left->right = new Node(4);
    root2 -> right -> left = new Node(5) ;
    // root2 -> right -> right = new Node(6) ;

    cout << identical(root , root2) << endl ;

    return 0;
}