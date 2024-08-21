#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* left;
    struct Node* right;

    Node(int value) {
        data = value;
        left = right = nullptr;
    }
};

// root right left

void recursiveRight(Node* node , int level , vector<int> &res){
    if(node == nullptr) return ;

    if(level == res.size()){
        res.push_back(node ->data) ;
    }
    recursiveRight(node -> right , level + 1 , res) ;
    recursiveRight(node -> left , level +1 , res ) ;
}

void rightView(Node* root , int level ){
    vector<int> res ;
    recursiveRight(root , 0 , res ) ;

    for(auto  it : res){
        cout << it << " " ;
    }
    cout  << endl ;
}

void recursiveLeft(Node* node , int level , vector<int> &res){
    if(node == nullptr) return ;

    if(level == res.size()){
        res.push_back(node ->data) ;
    }
    recursiveLeft(node -> left , level +1 , res ) ;
    recursiveLeft(node -> right , level + 1 , res) ;
}

void leftView(Node* root , int level ){
    vector<int> res ;
    recursiveLeft(root , 0 , res ) ;

    for(auto  it : res){
        cout << it << " " ;
    }
    cout  << endl ;
}

int main() {
    
    struct Node* root = new Node(1);

    root->left = new Node(2);
    root->right = new Node(3);
    root -> left -> left = new Node(4) ;
    root -> left -> right = new Node(5) ;
    root -> right -> left = new Node(6) ;
    root -> right -> right = new Node(7) ;
    root -> left -> right ->left = new Node(8) ;
    root -> left -> right ->right = new Node(9) ;

    rightView(root , 0) ;

    leftView(root , 0) ;

    return 0;
}