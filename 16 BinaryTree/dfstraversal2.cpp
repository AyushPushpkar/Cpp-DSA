#include <bits/stdc++.h>
using namespace std;

//DFS - iterative

struct Node {
    int data;
    struct Node* left;
    struct Node* right;

    Node(int value) {
        data = value;
        left = right = nullptr;
    }
};

// Preorder traversal function: Root -> Left -> Right
void preorder(Node* root) {        
    vector<int> pre ;        // tc : o(n)
    if(root == nullptr){
        cout << "empty tree" << endl ;
        return ;
    }

    stack<Node*> st ;      // sc : o(n)
    st.push(root) ;

    while(!st.empty()){
        root = st.top() ;
        st.pop() ;
        pre.push_back(root -> data) ;
        if(root -> right != nullptr) st.push(root -> right) ;
        if(root -> left != nullptr) st.push(root -> left) ;
        
    }

    for(auto it : pre){
        cout << it << " " ;
    }
    cout << endl;
}

// Inorder traversal function: Root -> Left -> Right
void inorder(Node* root) {        
    
}

// Postorder traversal function: Root -> Left -> Right
void postorder(Node* root) {       
    
    
}

int main() {
    // Create the root node
    struct Node* root = new Node(1);

    // Create and attach child nodes
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->right = new Node(4);
    root -> right -> left = new Node(5) ;
    root -> right -> right = new Node(6) ;

    // Call preorder traversal and print the tree
    preorder(root);
    

    // Call inorder traversal and print the tree
    inorder(root);
    cout << endl ;

    // Call postorder traversal and print the tree
    postorder(root);

    return 0;
}