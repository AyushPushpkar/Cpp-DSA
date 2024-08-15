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

int optimal(Node* node) {          // tc : o(n)
    if(node == nullptr) return 0 ;

    int lh = optimal(node->left) ;      // sc : o(n) squeue case
    if(lh == -1 ) return -1 ;
    int rh = optimal(node->right) ;
    if(lh == -1 && rh == -1) return -1 ;
    
    if(abs(lh- rh) > 1) return -1 ;

    return 1 + max(lh,rh) ;

}

int height(Node* node) {          // tc : o(n)
    if(node == nullptr) return 0 ;

    int lh = height(node->left) ;      // sc : o(n) squeue case
    int rh = height(node->right) ;

    return 1 + max(lh,rh) ;

}

bool check(Node*node){                    //tc : o(n^2)
    if(node == nullptr) return true ;

    int Lh = height(node -> left) ;
    int Rh = height(node ->right) ;

    if(abs(Lh - Rh) > 1) return false;

    bool Left = check(node -> left) ;
    bool right = check (node -> right) ;

    if(!left || !right) return false ;

    return true ;
}

int main() {

    struct Node* root = new Node(1);

    root->left = new Node(2);
    root->right = new Node(3);
    root->left->right = new Node(4);
    root -> right -> left = new Node(5) ;
    root -> right -> right = new Node(6) ;

    cout << check(root) << endl ;

    cout << optimal(root) << endl ; 

    return 0;
}