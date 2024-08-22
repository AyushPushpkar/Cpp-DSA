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

//inorder      tc : o(n)      sc : o(h)
bool getPath(Node* root , vector<int> &v , int target ){
    if(!root) return false ;

    v.push_back(root ->data) ;

    if(root ->data == target) return true ;

    if(getPath(root ->left , v  , target) || 
    getPath(root ->right , v ,target)) return true ;

    v.pop_back() ;
    return false ;
}

void rootToNode(Node* root , int target){
    vector<int> arr ;
    if(root == nullptr) return  ;

    getPath(root ,arr , target) ;

    for(auto it : arr){
        cout << it << " " ;
    }
    cout << endl ;

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

    int target = 8 ;

    rootToNode(root ,target) ;

}