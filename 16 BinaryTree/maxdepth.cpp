#include <bits/stdc++.h>
using namespace std;

struct Node {
    int val;
    struct Node* left;
    struct Node* right;

    Node(int value) {
        val = value;
        left = right = nullptr;
    }
};

int recursive(Node* node) {          // tc : o(n)
    if(node == nullptr) return 0 ;

    int lh = recursive(node->left) ;      // sc : o(n) squeue case
    int rh = recursive(node->right) ;

    return 1 + max(lh,rh) ;

}

int main() {

    struct Node* root = new Node(1);

    root->left = new Node(2);
    root->right = new Node(3);
    root->left->right = new Node(4);
    root -> right -> left = new Node(5) ;
    root -> right -> right = new Node(6) ;

    cout << recursive(root) << endl ; 

    return 0;
}