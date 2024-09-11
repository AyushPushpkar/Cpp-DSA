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

//tc : o(h)
Node* lca(Node* root , Node* p , Node* q){
    //base case
    if(root == nullptr ){
        return root;
    }
    int cur = root->data ;

    if(cur < p->data && cur < q->data){
        return lca(root->right , p ,q) ;
    }
    if(cur > p->data && cur > q->data){
        return lca(root->left , p ,q)  ;
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

    struct Node* a = root -> right -> left ;  // Node with value 10
    struct Node* b = root -> right -> right -> left ; // Node with value 13

    cout << lca(root ,a, b) ->data << endl ;
}