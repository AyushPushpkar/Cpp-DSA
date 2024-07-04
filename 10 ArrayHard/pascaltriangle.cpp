#include<bits/stdc++.h>
using namespace std ;

void betterrow(int row ){
    int res = 1;
    cout << res << " " ;            //sc : o(1)

    for(int i =1;i<row;i++){          //tc  o(n)
        res = res * (row-i)/i;     
        cout << res << " " ;
    }
    cout << endl ;
}

void optimaltriangle(int row ){

    for(int i=1;i<=row;i++){     // tc ~o(row * n)
        betterrow(i);
    }
}

int nCr(int n ,int r){
    int res = 1;             //sc : o(1)

    for(int i=0;i<r;i++){    // tc : o(r)
        res = res *(n - i);
        res = res/(i+1);
    }
    return res;
}

void bruterow(int row ){

    for(int col =1;col<=row;col++){          //tc : o(row * r)
        cout << nCr(row-1,col-1) << " " ;
    }
    cout << endl ;
}

void brutriangle(int row , int col){
    vector<vector<int>>ans ;

    for(int i=0;i<row;i++){     // tc ~o(n^3)
        vector<int>temp;
        for(int j=0;j<=i;j++){
            temp.push_back(nCr(i,j));
        }
        ans.push_back(temp);
    }

    for(auto it : ans){
        for (auto num : it) {
            cout << num << " ";
        }
        cout << endl;
    }
    cout << endl;
}

int main(){
    int row ,col;
    cin >> row >> col  ;

    cout  << nCr(row-1,col-1) << endl ;

    bruterow(row);
    betterrow(row) ;
    cout << endl ;

    brutriangle(row,col);

    optimaltriangle(row);
    
}