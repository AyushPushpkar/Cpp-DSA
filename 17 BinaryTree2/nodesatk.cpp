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

void markParents(Node* root , unordered_map<Node* , Node*> &parent_track , Node* target){
    queue<Node* > q ;
    q.push(root) ;

    while(!q.empty()){
        Node* curr = q.front() ;
        q.pop() ;
        if(curr ->left){
            parent_track[curr ->left] = curr ;
            q.push(curr ->left) ;
        }
        if(curr -> right){
            parent_track[curr ->right] = curr ;
            q.push(curr -> right) ;
        }
    }
}

void nodesK(Node* root , Node* target ,int k ){

    if(!root) return ; // tc : o(n)         sc : o(n)

    unordered_map<Node* , Node*> parent_track ;
    markParents(root , parent_track ,target) ; // marking parents for upward traversal

    unordered_map<Node* , bool> visited ;
    queue<Node*>q;
    q.push(target);
    visited[target] = true ;
    int curr_level = 0 ; // distance

    while(!q.empty()){ // to find nodes at k dist
        int size = q.size() ;
        if(curr_level++ == k) break; // if equi break else increment
        for(int i=0 ;i<size ; i++){
            Node* cur = q.front() ;
            q.pop() ;
            if(cur ->left && !visited[cur->left]){
                q.push(cur->left) ;
                visited[cur ->left] =true ;
            }
            if(cur ->right && !visited[cur->right]){
                q.push(cur->right) ;
                visited[cur ->right] =true ;
            }
            if(parent_track[cur] && !visited[parent_track[cur]]){
                q.push(parent_track[cur]) ;
                visited[parent_track[cur]] =true ;
            }
        }
    }

    vector<int>res ;
    while(!q.empty()){
        Node* curr = q.front() ;
        q.pop() ;
        res.push_back(curr->data) ;
    }

    for(auto it : res){
        cout << it << " " ;
    }
    cout << endl;
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

    int k = 2 ;
    Node* target = root -> left -> right ;
    
    nodesK(root , target ,k ) ;

}