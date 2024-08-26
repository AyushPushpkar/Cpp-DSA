#include<bits/stdc++.h>
using namespace std ;

//min time to burn bt from a node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;

    Node(int value) {
        data = value;
        left = right = nullptr;
    }
};

void markParents(Node* root , unordered_map<Node* , Node*> &parent_track){
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

int burnTree(Node* root , Node* node){
                             
    if(root == nullptr) return 0;   

    unordered_map<Node* , Node*> parent_track ; 
    markParents(root , parent_track ) ;

    unordered_map<Node* , bool> visited ;
    queue<Node*>q;
    q.push(node);
    visited[node] = true ;
    int time = 0 ;

    while(!q.empty()){ 
        int size = q.size() ;
        bool flag = false; // To check if any node at the current level catches fire
        for(int i=0 ;i<size ; i++){
            Node* cur = q.front() ;
            q.pop() ;
            if(cur ->left && !visited[cur->left]){
                q.push(cur->left) ;
                visited[cur ->left] =true ;
                flag = true;
            }
            if(cur ->right && !visited[cur->right]){
                q.push(cur->right) ;
                visited[cur ->right] =true ;
                flag = true;
            }
            if(parent_track[cur] && !visited[parent_track[cur]]){
                q.push(parent_track[cur]) ;
                visited[parent_track[cur]] =true ;
                flag = true;
            }
        }
        if(flag) time++; // Increment time only if there is any new node catching fire
    }

    return time ;
    
}

int main(){

    struct Node* root = new Node(1);

    root->left = new Node(2);
    root->right = new Node(3);
    root -> left -> left = new Node(4) ;
    root -> left -> right = new Node(5) ;
    root -> right -> left = new Node(6) ;
    root -> right -> right = new Node(7) ;
    root -> left -> left ->left = new Node(8) ;
    root -> left -> left ->right = new Node(9) ;

    Node* node = root -> left -> right ;

    cout << burnTree(root , node) << endl ;

}