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

void topView(Node* root){
    //vertical   node
    map<int , int> mp ;            // sc : o(n)
    queue<pair<Node* ,int>> todo  ;   // sc  : o(n)
    todo.push({root, 0 }) ;

    while(!todo.empty()){         // tc : o(nlogn)
        auto p = todo.front() ;
        todo.pop() ;
        Node* node = p.first ;
        int line = p.second ;
        if(mp.find(line) == mp.end())
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
    root -> left -> right = new Node(4) ;
    root -> right -> left = new Node(5) ;
    root -> right -> right = new Node(6) ;

    topView(root) ;

    return 0;
}