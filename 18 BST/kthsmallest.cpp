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

void inorder(Node* node ,vector<int> &ans ) {        
    if (node == nullptr) return;
    
    inorder(node->left , ans);
    ans.push_back(node->data) ;
    inorder(node->right , ans);
}

// inorder of bst is always sorted
int kthSmallest(Node* root , int k){
    vector<int> ans ;   // sc : o(n)

    inorder(root , ans) ; // tc : o(n)

    int cnt = 0 ;
    for(auto it : ans){
        cnt++ ;
        if(cnt == k){
            cout << it << endl;
            break;
        }
    }
}

// tc : o(1)   sc : o(1)
void morrisTraversal(Node* root , int k){
    Node* cur = root ;
    int cnt = 0 ;
    while (cur != nullptr) {
        if(cur -> left == nullptr){
            cnt++ ;
            if(cnt == k) cout << cur ->data << endl ;
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
                cnt++ ;
                if(cnt == k) cout << cur ->data << endl ;
                cur = cur-> right ;
            }
        }
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

    int k = 5;
    kthSmallest(root , k) ; 
    morrisTraversal(root , k) ; 
}