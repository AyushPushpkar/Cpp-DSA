#include<bits/stdc++.h>
using namespace std ;

struct Node{
    int val ;
    struct Node* left ;
    struct Node* right ;

    Node(int value){
        val = value ;
        left = right = nullptr ;
    }
};

int maxSum(Node* node , int &maxi) {         
    if(node == nullptr) return 0 ;

    int leftSum = max(0,maxSum(node->left ,maxi )) ;      
    int rightSum = max(0 ,maxSum(node->right ,maxi)) ;

    maxi = max(maxi , leftSum+rightSum + node->val) ;

    return (node->val) + max(leftSum,rightSum) ;
}

int pathSum(Node* node ) {         
    int maxi = INT_MIN ;
    maxSum(node , maxi) ;
    return maxi ;
}

int main(){

    struct Node* root = new Node(-10);

    root->left = new Node(9);
    root->right = new Node(20);
    root->left->right = new Node(4);
    root -> right -> left = new Node(7) ;
    root -> right -> right = new Node(15) ;

    cout << pathSum(root ) << endl ;
}