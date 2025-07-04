#include<bits/stdc++.h>
using namespace std ;

// no of nodes in between two nodes in a level

struct Node {
    int data;
    struct Node* left;
    struct Node* right;

    Node(int value) {
        data = value;
        left = right = nullptr;
    }
};

//index every node
//0 based : left -> (2i + 1)    right -> (2i +2) 
//1 based : left -> (2i )    right -> (2i + 1)      // overflow 
int maxWidth(Node* root ){

    if(!root) return 0; // tc : o(n)         sc : o(n)
    int ans = 0;
    queue<pair<Node*, int>>q;
    q.push({root , 0});

    while(!q.empty()){
        int size = q.size() ;
        int mmin = q.front().second ;
        int first , last  ;
        for(int i = 0 ;i<size ; i++){
            int curid = q.front().second - mmin ;
            Node* node = q.front().first ;
            q.pop() ;
            if(i==0) first = curid ;
            if(i == size -1) last = curid ;
            if(node ->left) {
                q.push({node ->left, curid*2+1} ) ;
            }
            if(node ->right) {
                q.push({node ->right, curid*2+2} ) ;
            }
        }
        ans = max(ans ,last - first +1) ;
    }
    return ans ; 
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

    cout << maxWidth(root) << endl ;

}

/*
? Type	                Signed?	 Range (64-bit)	        Typical Use Case
* size_t	            No	     0 to ~18 quintillion	Container sizes, indices, memory sizes
* long long	            Yes	     ~−9e18 to +9e18	    Math with large or negative values
* unsigned long long	No	     0 to ~18 quintillion	Binary tree indices, bitmasks, hashes
*/