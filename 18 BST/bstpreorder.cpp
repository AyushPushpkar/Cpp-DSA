#include<bits/stdc++.h>
using namespace std ;

// construct bst from a preorder traversal

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
Node* build(vector<int> &a , int &i , int bound){
    if(i == a.size() || a[i] > bound){
        return NULL;
    }
    Node* root = new Node(a[i++]) ;
    root->left = build(a , i , root->data) ;
    root->right = build(a ,i ,bound) ;
    return root ;
}

Node* bstPreorder(vector<int> &a){
    int i = 0 ;
    return build(a ,i ,INT_MAX) ;
}

void levelorder(Node* root) {        // tc : o(n)
    vector<vector<int>>ans ;

    if(root == nullptr){
        cout << "empty tree" << endl ;
        return ;
    }
    queue<Node*>q ;       // sc : o(n)
    q.push(root) ;

    while(!q.empty()){
        int size = q.size() ;
        vector<int>level;

        for(int i=0 ;i<size ;i++){
            Node* node = q.front() ;
            q.pop() ;
            if(node -> left != nullptr) q.push(node -> left) ;
            if(node -> right != nullptr) q.push(node -> right) ;
            level.push_back(node->data) ;
        }
        ans.push_back(level) ;
    }

    for(auto it : ans){
        for(auto itt : it){
            cout << itt << " " ;
        }
        cout << endl ;
    }
}

int main(){
    vector<int> a = {5,8,3,11,2,13,17} ;

    Node* root = bstPreorder(a) ;
    levelorder(root) ;
}