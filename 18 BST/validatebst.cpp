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

bool isValid(Node* root , int minVal , int maxVal){
    if(root == nullptr)return true ;
    if(root -> data >= maxVal || root->data <= minVal) return false ;
    return isValid(root->left , minVal , root ->data) 
        && isValid(root->right , root->data , maxVal) ;
}

bool isValid(Node* root) {        
    return isValid(root , INT_MIN , INT_MAX) ;   // tc : o(n)
}

int main(){

    struct Node* root = new Node(8);

    root->left = new Node(5);
    root -> left -> left = new Node(4) ;
    root -> left -> right = new Node(7) ;
    root -> left -> right ->left = new Node(6) ;

    root->right = new Node(12);
    root -> right -> left = new Node(10) ;
    root -> right -> right = new Node(15) ;
    root -> right -> right -> left = new Node(13) ;

    cout << isValid(root) << endl ;
}