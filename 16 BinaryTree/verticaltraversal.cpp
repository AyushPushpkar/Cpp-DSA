#include <bits/stdc++.h>
using namespace std;

//left -> right
//smaller first if overlapping
//can have same values

struct Node {
    int data;
    struct Node* left;
    struct Node* right;

    Node(int value) {
        data = value;
        left = right = nullptr;
    }
};

//(v,level)
//left -> (-1,1)
//right -> (1,1)

void vertical(Node* root){
    //vertical    level     multinode
    map<int , map<int , multiset<int>>> mp ;
    queue<pair<Node* , pair<int ,int>>> todo  ;
    todo.push({root,{0 , 0 }}) ;

    while(!todo.empty()){
        auto p = todo.front() ;
        todo.pop() ;
        Node* node = p.first ;
        int x = p.second.first , y = p.second.second ;
        mp[x][y].insert(node -> data) ;

        if(node ->left){
            todo.push({node ->left , {x-1 , y+1}}) ;
        }
        if(node -> right){
            todo.push({node->right ,{ x+1 , y+1}}) ;
        }
    }

    vector<vector<int>>ans ;
    for(auto it : mp){
        vector<int>col ;
        for(auto itt : it.second){
            col.insert(col.end() , itt.second.begin() , itt.second.end()) ;
        }
        ans.push_back(col) ;
    }

    for(auto it  : ans){
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

    vertical(root) ;

    return 0;
}