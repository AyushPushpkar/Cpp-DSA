#include<bits/stdc++.h>
using namespace std ;

struct Node{
    int data ;
    struct Node* left ;
    struct Node* right ;

    Node(int value){
        data = value ;
        left = right = nullptr ;
    }
} ;


int main(){
    
    struct Node* root = new Node(1) ;

    root -> left = new Node(2) ;
    root -> right = new Node(3) ;
    root -> left -> right = new Node(4) ;

}

// --- Types of Binary Trees ---
    
    // Full Binary Tree:
    // Every node has either 0 or 2 children.
    // Example:
    //       1
    //      / \
    //     2   3
    //    / \
    //   4   5

    // Complete Binary Tree:
    // All levels are fully filled except possibly the last level,
    // which is filled from the left.
    // Example:
    //       1
    //      / \
    //     2   3
    //    / \  /
    //   4   5 6
  
    // Perfect Binary Tree:
    // All internal nodes have exactly two children, and all 
    // leaf nodes are at the same level.
    // Example:
    //       1
    //      / \
    //     2   3
    //    / \ / \
    //   4  5 6  7

    // Balanced Binary Tree:
    // The height of the left and right subtrees of every node 
    // differ by no more than 1.
    //height is at max log(n)
    // Example:
    //       1
    //      / \
    //     2   3
    //    / 
    //   4   

    // Degenerate (or Pathological) Binary Tree:
    // Each parent node has only one child, effectively becoming a linked list.
    // Example:
    //   1
    //    \
    //     2
    //      \
    //       3
    //        \
    //         4