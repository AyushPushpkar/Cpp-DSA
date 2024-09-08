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

Node* insertVal(Node* root , int val){
    if(root == nullptr) return new Node(val) ;
    Node* cur = root ;
    while(true){
        if(cur->data <= val){
            if(cur-> right != nullptr) cur = cur -> right ;
            else{
                cur ->right = new Node(val) ;
                break ;
            }
        }
        else{
            if(cur-> left != nullptr) cur = cur -> left ;
            else{
                cur ->left = new Node(val) ;
                break ;
            }
        }

    }
    return root ;
    
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

    struct Node* root = new Node(8);

    root->left = new Node(5);
    root -> left -> left = new Node(4) ;
    root -> left -> right = new Node(7) ;
    root -> left -> right ->left = new Node(6) ;

    root->right = new Node(12);
    root -> right -> left = new Node(10) ;
    root -> right -> right = new Node(15) ;
    root -> right -> right -> left = new Node(13) ;

    int node = 9;
    Node* ans = insertVal(root , node) ;
    levelorder(ans) ;
}