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

//tc : o(h)
Node* inSuccessor(Node* root , Node* p ){
    Node* successor = nullptr ;

    while(root != nullptr){
        if(p  -> data >= root->data){
            root = root -> right ;
        }
        else{
            successor = root ;
            root = root->left  ;
        }
    }
    return successor ; 
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

    struct Node* b = root -> right ; // Node with value 7

    cout << inSuccessor(root , b) ->data << endl ;

}