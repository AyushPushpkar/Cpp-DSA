#include<bits/stdc++.h>
using namespace std;

void optimal(vector<vector<int>>& v,int n,int m){
    vector<int> ans;
    int top =0 , bottom = n-1 ;
    int left = 0 , right = m-1 ;

    while(left<=right && top <=bottom){           //tc  o(n^2)
        for (int j = left; j <= right; j++) {
            ans.push_back(v[top][j])  ;
        }
        top +=1 ;
        for (int i = top; i <= bottom; i++) {
            ans.push_back(v[i][right])  ; 
        }
        right -=1 ;
        if(top<=bottom){
            for (int j = right; j >= left; j--) {
                ans.push_back(v[bottom][j])  ;
            }
            bottom -= 1 ;
        }
        if(left<=right){
            for (int i = bottom; i >= top; i--) {
                ans.push_back(v[i][left])  ;  
            }
            left +=1 ;
        }
    }

    for (auto it :ans){
        cout << it << " "  ;  
    }
}

int main(){
    int n=5 ,m=5;
    vector<vector<int>> v ={
        {1,2,3,4,5},
        {16,17,18,19,6},
        {15,24,25,20,7},
        {14,23,22,21,8},
        {13,12,11,10,9}
    };

    optimal(v,n,m);
}