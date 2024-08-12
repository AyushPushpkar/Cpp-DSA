#include<bits/stdc++.h>
using namespace std ;

int maxEl(vector<vector<int>> &v ,int n ,int mid){
    int index = 0 ;
    int max = v[0][mid] ;

    for(int i=1 ;i<n ;i++){       
        if(v[i][mid] > max){
            max= v[i][mid] ;
            index = i ;
        }
    }
    return index ;
}

pair<int,int> binary(vector<vector<int>> &v ,int n, int m){
    int low = 0 , high = m-1 ;

    while(low <= high){     //tc : (logm * n)
        int mid = (low+high)/2 ;
        int row = maxEl(v , n ,mid) ;
        int left = (mid-1 >= 0) ? v[row][mid-1] : -1 ;
        int right = (mid+1 < m) ? v[row][mid+1] : -1 ;

        if(left < v[row][mid] && v[row][mid] > right){
            return {row,mid} ;
        }
        if(left > v[row][mid]){
            high = mid-1 ;
        }
        else low = mid +1 ;
    }

    return {-1,-1} ;
}

int main(){
    vector<vector<int>>v = {
        {4,2,5,1,4,5},
        {2,9,3,2,3,2},
        {1,7,6,0,1,3},
        {3,6,2,3,7,2}
    } ;

    int n = v.size() ;
    int m = v.at(0).size() ;

    auto it = binary(v,n,m) ;
    cout << it.first << " , " << it.second << endl ;

}