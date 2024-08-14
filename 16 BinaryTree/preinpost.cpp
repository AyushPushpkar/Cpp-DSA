#include <bits/stdc++.h>
using namespace std;

/*
if num == 1 ;
pre-order
num++
left -> push to stack

if num == 2
inorder
num++
right -> push to stack

if num == 3
postorder
*/ 

struct Node {
    int val;
    struct Node* left;
    struct Node* right;

    Node(int value) {
        val = value;
        left = right = nullptr;
    }
};

void postorder(Node* node) {  

    if(node == nullptr) return ;
    vector<int>pre,in ,post ;     

    stack<pair<Node*,int>> st ;
    st.push({node,1}) ;

    while(!st.empty()){
        auto it = st.top() ;
        st.pop() ;

        if(it.second == 1){
            pre.push_back(it.first->val) ;
            it.second++ ;
            st.push(it) ;

            if(it.first->left != nullptr){
                st.push({it.first->left , 1}) ;
            }
        }
        else if(it.second == 2){
            in.push_back(it.first->val) ;
            it.second++;
            st.push(it) ;

            if(it.first->right != nullptr){
                st.push({it.first->right ,1}) ;
            }
        }
        else{
            post.push_back(it.first->val) ;
        }
    }

    for(auto it : pre){
        cout << it << " " ;
    }
    cout << endl;

    for(auto it : in){
        cout << it << " " ;
    }
    cout << endl;

    for(auto it : post){
        cout << it << " " ;
    }
    cout << endl;

}

int main() {

    struct Node* root = new Node(1);

    root->left = new Node(2);
    root->right = new Node(3);
    root->left->right = new Node(4);
    root -> right -> left = new Node(5) ;
    root -> right -> right = new Node(6) ;

    postorder(root);

    return 0;
}