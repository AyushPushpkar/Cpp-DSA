#include <bits/stdc++.h>
using namespace std;

//BFS - breadth first search

struct Node {
    int data;
    struct Node* left;
    struct Node* right;

    Node(int value) {
        data = value;
        left = right = nullptr;
    }
};

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

int main() {
    
    struct Node* root = new Node(1);

    root->left = new Node(2);
    root->right = new Node(3);
    root -> left -> right = new Node(4) ;
    root -> right -> left = new Node(5) ;
    root -> right -> right = new Node(6) ;

    // root = nullptr ;

    // Call levelorder traversal and print the tree
    levelorder(root);

    return 0;
}