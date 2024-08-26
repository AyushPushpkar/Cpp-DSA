#include<bits/stdc++.h>
using namespace std ;

//complete binary tree
struct Node {
    int data;
    struct Node* left;
    struct Node* right;

    Node(int value) {
        data = value;
        left = right = nullptr;
    }
};

int findHeightLeft(Node* node) {          
    int h = 0 ;

    while(node){
        h++ ;
        node = node->left ;
    }
    return h ;
}

int findHeightRight(Node* node) {          
    int h = 0 ;

    while(node){
        h++ ;
        node = node->right ;
    }
    return h ;
}

//no of nodes = 2^h - 1 
int cntNodes(Node* root ){   // tc : o((logn)^2)
                             
    if(root == nullptr) return 0;   // sc : o(logn)

    int lh = findHeightLeft(root) ;      
    int rh = findHeightRight(root) ;
    
    if(lh == rh) return (1<<lh) - 1 ; // have all the nodes
     
    return 1 + cntNodes(root ->left) + cntNodes(root ->right) ; 
}

int main(){

    struct Node* root = new Node(1);

    root->left = new Node(2);
    root->right = new Node(3);
    root -> left -> left = new Node(4) ;
    root -> left -> right = new Node(5) ;
    root -> right -> left = new Node(6) ;
    root -> right -> right = new Node(7) ;
    root -> left -> left ->left = new Node(8) ;
    root -> left -> left ->right = new Node(9) ;

    cout << cntNodes(root) << endl ;

}