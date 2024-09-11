#include<bits/stdc++.h>
using namespace std ;

// lowest common ancestor

struct Node {
    int data;
    struct Node* left;
    struct Node* right;

    Node(int value) {
        data = value;
        left = right = nullptr;
    }
};

//tc : o(n)      sc : o(n)
Node* lca(Node* root , Node* p , Node* q){
    //base case
    if(root == nullptr || root == p || root == q){
        return root;
    }

    Node* left = lca(root -> left , p , q) ;
    Node* right = lca(root ->right , p , q) ;

    //result 
    if(left == nullptr){
        return right ;
    }
    else if(right == nullptr){
        return left ;
    }
    //both non null we found lca
    else{
        return root ;
    }

}

int main(){

    struct Node* root = new Node(1);

    root->left = new Node(2);
    root->right = new Node(3);
    root -> left -> left = new Node(4) ;
    root -> left -> right = new Node(5) ;
    root -> right -> left = new Node(6) ;
    root -> right -> right = new Node(7) ;
    root -> left -> right ->left = new Node(8) ;
    root -> left -> right ->right = new Node(9) ;

    // Reference the actual nodes from the tree
    struct Node* a = root->left->right->left; // Node with value 8
    struct Node* b = root->right->right;      // Node with value 7

    cout << lca(root ,a, b) ->data << endl ; 

}