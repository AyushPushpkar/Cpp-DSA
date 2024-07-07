#include<bits/stdc++.h>
using namespace std ;

//merge overlapping subinterval

void optimal(vector<vector<int>> &a , int n){
    sort(a.begin() ,a.end());    //  o(nlogn)
    vector<vector<int>> ans ;    // sc : o(n)

    for(int i=0;i<n;i++){      // o(2n)
        int start = a[i][0];
        int end = a[i][1] ;
        if(ans.empty() || start > ans.back()[1]) {
           ans.push_back({start,end}) ;
        }
        else if(start <= ans.back()[1]){
            ans.back()[1]= max (end , ans.back()[1]) ;
        }
    }

    for(auto it : ans){
        for(auto itt : it){
            cout << itt << " " ;
        }
        cout << endl;
    }

}

void brute(vector<vector<int>> &a , int n){
    sort(a.begin() ,a.end());    //  o(nlogn)
    vector<vector<int>> ans ;    // sc : o(n)

    for(int i=0;i<n;i++){      // o(2n)
        int start = a[i][0];
        int end = a[i][1] ;
        if(!ans.empty() && end <= ans.back()[1]) {
            continue;
        }
        for(int j=i+1;j<n;j++){
            if(a[j][0] <= end){
                end = max(a[j][1] ,end) ;
            }
            else{
                break;
            }
        }
        ans.push_back({start,end}) ;
    }

    for(auto it : ans){
        for(auto itt : it){
            cout << itt << " " ;
        }
        cout << endl;
    }

}

int main(){
    int n = 8  ;
    vector<vector<int>> a = {{2,6},{8,9},{1,3},
    {9,11},{8,10},{2,4},{15,18},{16,17}};

    brute(a,n) ;
    cout << endl ;

    optimal(a,n) ;

}