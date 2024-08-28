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

string serialize(Node* root ){
    if(!root) return "";

    string s = "" ;
    queue<Node* > q ;
    q.push(root) ;

    while(!q.empty()){
        Node* curr = q.front() ;
        q.pop() ;
        if(curr == NULL)s.append("#,");
        else{
            s.append(to_string(curr->data)+",") ;
        }
        if(curr != NULL){
            q.push(curr ->left) ;
            q.push(curr ->right) ;
        }
    }
    // cout << s ;
    return s ;

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

    cout << serialize(root) << endl ;

}