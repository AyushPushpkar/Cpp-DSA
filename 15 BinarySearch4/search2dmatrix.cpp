#include<bits/stdc++.h>
using namespace std ;

//find the row with max 1's
//if same 1's smallest row

bool iterative(vector<int> &a ,int n,int target){
    int low = 0 , high = n-1 ;

    while(low <= high){
        int mid = (low+high)/2 ;
        if(a[mid] == target) return true ;
        else if ( a[mid] < target){
            low = mid+1 ;
        }
        else{
            high = mid-1 ;
        }
    }
    return false ;
    
}

bool optimal(vector<vector<int>> &v ,int n, int m , int target){
    int low = 0 , high = n-1 ;
    
    while(low<= high){ // tc : o(logn) + o(logm)
        int mid = (low+high)/2;
        if(v[mid][0] <= target && target <= v[mid][m-1]){ 
            bool ans = iterative(v.at(mid),m,target) ;
            if(ans == 1) return true ;
            else return false ;
        }
        else if(v[mid][0] > target) high = mid -1 ;
        else if(v[mid][m-1] < target) low = mid +1 ;
    }
}

bool optimal2(vector<vector<int>> &v ,int n, int m , int target){
    int low = 0 , high = m*n-1 ;
    
    while(low<= high){ // tc : o(logn) + o(logm)
        int mid = (low+high)/2;
        int row = mid/m , col = mid%m ;
        if(v[row][col] == target) return true ;
        else if(v[row][col] > target) high = mid -1 ;
        else low = mid +1 ;
    }
    return false ;
}

bool binary(vector<vector<int>> &v ,int n, int m , int target){
    
    for(int i=0 ;i<n; i++){ // tc : o(n) + o(logm)
        if(v[i][0] <= target && target <= v[i][m-1]){ 
            bool ans = iterative(v.at(i),m,target) ;
            if(ans == 1) return true ;
            else return false ;
        }
        else continue ;
    }
}

int main(){
    vector<vector<int>>v = {
        {3,4,7,9},
        {12,13,16,18},
        {20,21,23,29}
    } ;  //sorted

    int n = v.size() ;
    int m = v.at(0).size() ;

    int target = 23;
    cin >> target ;

    cout << binary(v,n,m , target) << endl; 

    cout << optimal(v,n,m , target) << endl; 

    cout << optimal2(v,n,m , target) << endl; 

}