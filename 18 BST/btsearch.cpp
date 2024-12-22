#include<bits/stdc++.h>
using namespace std ;

// Binary search Tree -> left < node < right
// everything on right must be greater
// everything on left should be smaller 

struct Node {
    int data;
    struct Node* left;
    struct Node* right;

    Node(int value) {
        data = value;
        left = right = nullptr;
    }
};

//search in BST - log2(n)
Node* BTsearch(Node* root , int target){
    if(root == nullptr) return nullptr ;

    if(root->data == target) return root ;
    else if(root -> data < target) return BTsearch(root ->right , target) ;
    else return BTsearch(root ->left , target) ;
}

Node* BTsearch2(Node* root , int target){
    while(root != nullptr && root->data != target){
        root = target < root->data ? root ->left : root ->right ;
    }
    return root ;
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

    int target = 15;
    Node* ans = BTsearch2(root , target) ;
    if(ans != nullptr ){
        cout << ans->data << endl;
    } 
    else{
        cout << "Node not in Tree" << endl ;
    }
}