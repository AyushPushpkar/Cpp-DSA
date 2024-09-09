#include<bits/stdc++.h>
using namespace std ;

struct Node {
    int val;
    struct Node* left;
    struct Node* right;

    Node(int value) {
        val = value;
        left = right = nullptr;
    }
};

Node* deleteNode(Node* root, int key) {
    if( !root ) return NULL;
    if( root->val < key ) root->right = deleteNode(root->right, key);
    else if( root->val > key ) root->left = deleteNode(root->left, key);
    else{
        if( !root->right && !root->left ) return NULL;
        else if( !root->right ) return root->left;
        else if( !root->left ) return root->right;
        else{
            Node* temp = root->right;
            while( temp->left ) temp = temp->left;
            temp->left = root->left;
            return root->right;
        }
    }
    return root;
   
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
            level.push_back(node->val) ;
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

    int node = 10;
    Node* ans = deleteNode(root , node) ;
    levelorder(ans) ;
}