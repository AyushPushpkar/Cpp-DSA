#include <bits/stdc++.h>
using namespace std;

//anti-clockwise
//left boundary w/o leaf
//leaf nodes -> preorder
//right boundary reverse w/o leaf

struct Node {
    int data;
    struct Node* left;
    struct Node* right;

    Node(int value) {
        data = value;
        left = right = nullptr;
    }
};

bool isLeaf(Node* cur){
    if(!cur->left and !cur->right) return true;
    else return false;
}

void addLeft(Node* node , vector<int> &res){
    Node* cur = node->left ;
    while(cur){
        if(!isLeaf(cur)) res.push_back(cur ->data) ;
        if(cur -> left) cur = cur ->left ;
        else cur = cur -> right ;
    }
}

void addRight(Node* node , vector<int> &res){
    vector<int> temp ;
    Node* cur = node->right ;
    while(cur){
        if(!isLeaf(cur)) temp.push_back(cur ->data) ;
        if(cur -> right) cur = cur ->right ;
        else cur = cur -> left ;
    }

    for(int i = temp.size() -1 ; i>= 0 ;i--){
        res.push_back(temp[i]) ;
    }
}

void addLeaves(Node* node , vector<int> &res){
    if(isLeaf(node)){
        res.push_back(node -> data) ;
        return ;
    }
    if(node -> left) addLeaves(node->left , res) ;
    if(node ->right) addLeaves(node->right ,res) ;
}

void printBoundary(Node* root){
    vector<int> res ;
    if(!root){
        cout << "empty tree" << endl;
        return ;
    }

    if(!isLeaf(root)) res.push_back(root -> data) ;
    addLeft(root , res) ;
    addLeaves(root ,res) ;
    addRight(root , res) ;

    for(auto it  : res){
        cout << it << " " ;
    }

}

int main() {
    
    struct Node* root = new Node(1);

    root->left = new Node(2);
    root->right = new Node(3);
    root -> left -> right = new Node(4) ;
    root -> right -> left = new Node(5) ;
    root -> right -> right = new Node(6) ;

    printBoundary(root) ;

    return 0;
}