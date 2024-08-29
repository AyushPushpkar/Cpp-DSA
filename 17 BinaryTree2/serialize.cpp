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

Node* deserialize(string data){
    if(data.size() == 0) return nullptr ;

    stringstream s(data) ;
    string str ;
    getline(s,str ,',') ;
    Node *root = new Node(stoi(str)) ;
    queue<Node*> q ; 
    q.push(root) ;

    while(!q.empty()){

        Node* node = q.front() ;
        q.pop() ;

        getline(s,str,',') ;
        if(str == "#"){
            node ->left == nullptr ;
        }
        else{
            Node* leftNode = new Node(stoi(str)) ;
            node->left = leftNode ; 
            q.push(leftNode) ;
        }

        getline(s,str,',') ;
        if(str == "#"){
            node ->right == nullptr ;
        }
        else{
            Node* rightNode = new Node(stoi(str)) ;
            node->right = rightNode ; 
            q.push(rightNode) ;
        }
        
    }
    return root ;
}

void printLevelOrder(Node* root) {
    if (!root) return;

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        int levelSize = q.size(); 
        for (int i = 0; i < levelSize; ++i) {
            Node* node = q.front();
            q.pop();

            cout << node->data << " ";

            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }
        cout << endl; 
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

    string res = serialize(root) ;
    cout << res << endl ;
    cout << endl ;

    Node* ansRoot = deserialize(res) ;
    printLevelOrder(ansRoot) ;
}