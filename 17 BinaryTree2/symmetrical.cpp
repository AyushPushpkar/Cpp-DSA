#include<bits/stdc++.h>
using namespace std ;

struct Node {
    int data;
    struct Node* left;
    struct Node* right;

    Node(int value) {
        data = value;
        left = right = nullptr;
    }
};

bool isSymmetricHelp(Node* left , Node* right){
    if(left == nullptr || right == nullptr){
        return (left == right) ;
    }

    if(left->data != right->data)return false ;

    return  isSymmetricHelp(left->left , right -> right) 
    && isSymmetricHelp(left -> right , right -> left) ;
}

//tc : o(n)      sc : o(n)
bool isSymmetrical(Node* root){
    return root == nullptr || isSymmetricHelp(root -> left , root ->right) ;
}

int main(){
    struct Node* root = new Node(1);

    root->left = new Node(2);
    root->right = new Node(2);
    root -> left -> left = new Node(3) ;
    root -> left -> right = new Node(4) ;
    root -> right -> left = new Node(4) ;
    root -> right -> right = new Node(3) ;
    // root -> left -> right ->left = new Node(5) ;

    cout << isSymmetrical(root) ;

}