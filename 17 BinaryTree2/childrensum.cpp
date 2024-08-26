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

//tc : o(n)      sc : o(n)
void childSum(Node* root ){

    if(root == nullptr) return ;

    int child = 0 ;

    if(root ->left){
        child += root ->left ->data ;
    }
    if(root ->right){
        child += root ->right ->data ;
    }

    if(child >= root ->data) root->data = child ;
    else{
        if(root -> left) root ->left ->data = root ->data ;
        else if(root ->right) root ->right ->data = root ->data ;
    }

    childSum(root ->left) ;
    childSum(root ->right) ;

    int tot = 0 ;
    if(root ->left) tot += root ->left ->data ;
    if(root ->right) tot += root ->right ->data ;
    if(root ->left or root ->right) root ->data = tot ;

}

int main(){

    struct Node* root = new Node(1);

    root->left = new Node(2);
    root->right = new Node(3);
    root -> left -> left = new Node(4) ;
    root -> left -> right = new Node(5) ;
    root -> right -> left = new Node(6) ;
    root -> right -> right = new Node(7) ;
    root -> left -> right ->left = new Node(8) ;
    root -> left -> right ->right = new Node(9) ;

    childSum(root) ;

    levelorder(root) ;

}