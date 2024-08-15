#include<bits/stdc++.h>
using namespace std ;

//longest distance between 2 nodes
//not necessary to pass through root

struct Node{
    int val ;
    struct Node* left ;
    struct Node* right ;

    Node(int value){
        val = value ;
        left = right = nullptr ;
    }
};

int height2(Node* node , int &maxi) {          // tc : o(n)
    if(node == nullptr) return 0 ;

    int lh = height2(node->left ,maxi) ;      
    int rh = height2(node->right ,maxi) ;

    maxi = max(maxi , lh+rh) ;

    return 1 + max(lh,rh) ;

}

int optimal(Node* node) {       
    int maxi = 0 ;
    height2(node , maxi) ;
    return maxi ;
}

int height(Node* node) {          // tc : o(n)
    if(node == nullptr) return 0 ;

    int lh = height(node->left) ;      // sc : o(n) squeue case
    int rh = height(node->right) ;

    return 1 + max(lh,rh) ;

}

int diameter(Node* node ) {          // tc : o(n^2)
    if(node == nullptr) return 0;

    int lh = height(node->left) ;      
    int rh = height(node->right) ;

    int ld = diameter(node -> left ) ;
    int rd  = diameter(node->right ) ;

    return max( lh+rh , max(ld,rd) ) ;

}

int main(){

    struct Node* root = new Node(1);

    root->left = new Node(2);
    root->right = new Node(3);
    root->left->right = new Node(4);
    root -> right -> left = new Node(5) ;
    root -> right -> right = new Node(6) ;

    cout << diameter(root ) << endl ;

    cout << optimal(root) << endl ;
}