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
Node* buildTreeHelper(vector<int>& preorder, int preStart, int preEnd,
                      vector<int>& inorder, int inStart, int inEnd,
                      unordered_map<int, int>& inMap) {
    if (preStart > preEnd || inStart > inEnd) return nullptr;

    Node* root = new Node(preorder[preStart]);

    int inRoot = inMap[root->data];
    int numsLeft = inRoot - inStart;

    root->left = buildTreeHelper(preorder, preStart + 1, preStart + numsLeft,
                                 inorder, inStart, inRoot - 1, inMap);
    root->right = buildTreeHelper(preorder, preStart + numsLeft + 1, preEnd,
                                  inorder, inRoot + 1, inEnd, inMap);

    return root;
}

// tc : o(n)      sc : o(n)
// Function to build a tree from preorder and inorder traversals
Node* buildTree(vector<int>& preorder, vector<int>& inorder) {
    unordered_map<int, int> inMap;  // Use unordered_map for better performance
    for (int i = 0; i < inorder.size(); i++) {
        inMap[inorder[i]] = i;
    }

    Node* root = buildTreeHelper(preorder, 0, preorder.size() - 1,
                                 inorder, 0, inorder.size() - 1, inMap);

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
    vector<int> inorder = {9, 3, 15, 20, 7};
    vector<int> preorder = {3, 9, 20, 15, 7};

    Node* root = buildTree(preorder, inorder);

    cout << "Constructed binary tree: " << endl;
    printLevelOrder(root);

    return 0;
}
