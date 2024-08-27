#include<bits/stdc++.h>
using namespace std;

// Definition for a binary tree node.
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = right = nullptr;
    }
};

// Helper function to build the binary tree from inorder and preorder traversals
Node* buildTreeHelper(vector<int>& inorder, int inStart, int inEnd,
                    vector<int>& postorder, int postStart, int postEnd,
                    unordered_map<int, int>& inMap) {
    if (postStart > postEnd || inStart > inEnd) return nullptr;

    Node* root = new Node(postorder[postEnd]);

    int inRoot = inMap[postorder[postEnd]];
    int numsLeft = inRoot - inStart;

    root->left = buildTreeHelper(inorder, inStart , inRoot - 1, 
                                postorder, postStart, postStart + numsLeft -1,inMap);
    root->right = buildTreeHelper(inorder, inRoot + 1 , inEnd,
                                postorder, postStart + numsLeft, postEnd - 1, inMap);

    return root;
}

// tc : o(n)      sc : o(n)
Node* buildTree(vector<int>& inorder ,vector<int>& postorder) {
    unordered_map<int, int> inMap;  

    if(inorder.size() != postorder.size()) return nullptr ;

    for (int i = 0; i < inorder.size(); ++i) {
        inMap[inorder[i]] = i;
    }

    Node* root = buildTreeHelper(inorder, 0, inorder.size() - 1,
                                postorder, 0, postorder.size() - 1, inMap);

    return root;
}

// level-order traversal 
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

int main() {
    vector<int> inorder = {40, 20, 50,10, 60, 30};
    vector<int> postorder = {40, 50, 20, 60 ,30, 10};

    Node* root = buildTree(inorder, postorder);

    cout << "Constructed binary tree: " << endl;
    printLevelOrder(root);

    return 0;
}
