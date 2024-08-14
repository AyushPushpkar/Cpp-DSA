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
    vector<int> in ;        // tc : o(n)
    if(root == nullptr){
        cout << "empty tree" << endl ;
        return ;
    }
    
    stack<Node*> st ;      // sc : o(n)
    Node* node = root ;

    while(true){
        if(node != nullptr){
            st.push(node) ;
            node = node->left ;
        }
        else{
            if(st.empty() == true) break;
            node = st.top() ;
            st.pop() ;
            in.push_back(node -> data) ;
            node = node -> right ;
        }
        
    }

    for(auto it : in){
        cout << it << " " ;
    }
    cout << endl;
}

// Postorder traversal function: Root -> Left -> Right : 2 stack
void postorder(Node* root) {       
    vector<int> post ;        // tc : o(n)
    if(root == nullptr){
        cout << "empty tree" << endl ;
        return ;
    }
    
    stack<Node*> st1 , st2 ;      // sc : o(2n)
    st1.push(root) ;

    while(!st1.empty()){
        root = st1.top() ;
        st1.pop() ;
        st2.push(root) ;
        if(root -> left != nullptr) st1.push(root -> left) ;
        if(root -> right != nullptr) st1.push(root -> right) ;
    }

    while(!st2.empty()){
        post.push_back(st2.top() -> data) ;
        st2.pop() ;
    }

    for(auto it : post){
        cout << it << " " ;
    }
    cout << endl;
    
}

// Postorder traversal function: Root -> Left -> Right : 1 stack
void postorder2(Node* curr) {       
    vector<int> post;
    if(curr == nullptr){
        cout << "empty tree" << endl ;
        return ;
    }

    stack<Node*> st;
    
    while(curr != nullptr || !st.empty())
    {
        if(curr != nullptr){
            st.push(curr) ;
            curr = curr -> left ;
        }      
        else{
            Node* temp = st.top() ->right ;
            if( temp == nullptr){
                temp = st.top() ;
                st.pop() ;
                post.push_back(temp -> data) ;
                while( temp == st.top() -> right && !st.empty()){
                    temp = st.top() ;
                    st.pop() ;
                    post.push_back(temp ->data) ;
                }
            }
            else curr = temp ;
        }
    }

    for(auto it : post){
        cout << it << " " ;
    }
    cout << endl;
    
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

    // Call postorder traversal and print the tree
    postorder(root);
    postorder2(root)  ;

    return 0;
}