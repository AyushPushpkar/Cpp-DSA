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

void bottomView(Node* root){
    //vertical     multinode
    map<int , int> mp ;
    queue<pair<Node* ,int>> todo  ;
    todo.push({root, 0 }) ;

    while(!todo.empty()){
        auto p = todo.front() ;
        todo.pop() ;
        Node* node = p.first ;
        int line = p.second ;
        mp[line] = node -> data ;

        if(node ->left){
            todo.push({node ->left ,line-1 }) ;
        }
        if(node -> right){
            todo.push({node->right , line+1 }) ;
        }
    }

    vector<int>ans ;
    for(auto it : mp){
        ans.push_back(it.second) ;
    }

    for(auto it  : ans){
        cout << it << " " ;
    }
    cout << endl ;
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

    bottomView(root) ;

    return 0;
}