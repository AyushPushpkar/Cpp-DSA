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

// Threaded binary tree
//inorder
void morrisTraversal(Node* root){
    vector<int> inorder ;
    Node* cur = root ;

    while (cur != nullptr) {
        if(cur -> left == nullptr){
            inorder.push_back(cur -> data) ;
            cur = cur -> right ;
        }
        else{
            Node* prev = cur -> left ;
            while(prev -> right && prev -> right != cur){
                prev = prev -> right ;
            }

            if(prev  -> right == nullptr){
                prev->right = cur ;
                cur = cur  ->left ;
            }
            else{
                prev ->right = nullptr ;
                inorder.push_back(cur->data) ;
                cur = cur-> right ;
            }
        }
    }

    for(auto it  : inorder){
        cout << it << " " ;
    }
}

//postorder
void morrisTraversal2(Node* root){
    vector<int> preorder ;
    Node* cur = root ;

    while (cur != nullptr) {
        if(cur -> left == nullptr){
            preorder.push_back(cur -> data) ;
            cur = cur -> right ;
        }
        else{
            Node* prev = cur -> left ;
            while(prev -> right && prev -> right != cur){
                prev = prev -> right ;
            }

            if(prev  -> right == nullptr){
                prev->right = cur ;
                preorder.push_back(cur->data) ;
                cur = cur  ->left ;
            }
            else{
                prev ->right = nullptr ;
                cur = cur-> right ;
            }
        }
    }

    for(auto it  : preorder){
        cout << it << " " ;
    }
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

    morrisTraversal(root) ;
    cout << endl ;

    morrisTraversal2(root) ;

}