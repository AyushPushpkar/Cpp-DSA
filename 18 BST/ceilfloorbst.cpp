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

// val >= key
// tc : o(h) ~ o(log2(n))
int Ceil(Node* root , int key){
    int ceil = -1 ;
    while(root ){
        if(root -> data == key){
            ceil = root -> data  ;
            return ceil ;
        }
        if(key > root -> data){
            root = root -> right ;
        }
        else{
            ceil = root -> data ;
            root = root -> left ;
        }
    }

    return ceil ;
}

//val <= key
int Floor(Node* root , int key){
    int floor = -1 ;
    while(root ){
        if(root -> data == key){
            floor = root -> data  ;
            return floor ;
        }
        if(key < root -> data){
            root = root -> left ;
        }
        else{
            floor = root -> data ;
            root = root -> right ;
        }
    }

    return floor ;
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

    int key = 9;
    cout << Ceil(root , key) << endl ;
    cout << Floor(root , key) << endl ;
}