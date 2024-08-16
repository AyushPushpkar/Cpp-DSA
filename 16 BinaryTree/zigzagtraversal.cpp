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

//flag 1 : left ->right
//flag 0 : right ->left

void zigzag(Node* root) {        // tc : o(n)
    vector<vector<int>>ans ;

    if(root == nullptr){
        cout << "empty tree" << endl ;
        return ;
    }
    queue<Node*>q ;       // sc : o(n)
    q.push(root) ;
    bool flag = true ;

    while(!q.empty()){
        int size = q.size() ;
        vector<int>level(size);

        for(int i=0 ;i<size ;i++){
            Node* node = q.front() ;
            q.pop() ;

            if(node -> left != nullptr) q.push(node -> left) ;
            if(node -> right != nullptr) q.push(node -> right) ;

            int index = (flag) ? i : (size - 1 -i) ;
            level[index] = node->data ;
        }
        flag = !flag ;
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

    zigzag(root);

    return 0;
}