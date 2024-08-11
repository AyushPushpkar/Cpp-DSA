#include<bits/stdc++.h>
using namespace std ;

// individual row and col sorted

int iterative(vector<int> &a ,int n,int target){
    int low = 0 , high = n-1 ;

    while(low <= high){
        int mid = (low+high)/2 ;
        if(a[mid] == target) return mid ;
        else if ( a[mid] < target){
            low = mid+1 ;
        }
        else{
            high = mid-1 ;
        }
    }
    return -1 ;
    
}

pair<int,int> optimal(vector<vector<int>> &v ,int n, int m , int target){
    int row = 0 , col = m-1 ;

    while(row < n && col >=0){
        if(v[row][col] == target) return {row,col} ;
        else if(v[row][col] > target) col-- ;
        else row++ ;
    }
    return {-1,-1} ;
}

pair<int,int> binary(vector<vector<int>> &v ,int n, int m , int target){
    
    for(int i=0 ;i<n; i++){ // tc : o(n*logm)
        if(v[i][0] <= target && target <= v[i][m-1]){ 
            int ans = iterative(v.at(i),m,target) ;
            if(ans != -1)return {i,ans} ;
        }
        else continue ;
    }
    return {-1,-1} ;
}

int main(){
    vector<vector<int>>v = {
        {1,4,7,11,15},
        {2,5,8,12,19},
        {3,6,9,16,22},
        {10,13,14,17,24},
        {20,21,23,29,30}
    } ;  //sorted

    int n = v.size() ;
    int m = v.at(0).size() ;

    int target = 23;
    cin >> target ;

    auto it = binary(v,n,m,target) ;
    cout << it.first << " , " << it.second << endl ;

    auto it2 = optimal(v,n,m,target) ;
    cout << it2.first << " , " << it2.second << endl ; 

}