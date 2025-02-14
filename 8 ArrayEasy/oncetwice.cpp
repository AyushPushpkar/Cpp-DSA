#include<bits/stdc++.h>
using namespace std ;

int onceoptimal(int a[] ,int n){

    int XOR =0 ;
    for(int i=0 ; i<n ;i++){          // o(n)
        XOR = XOR^a[i] ;             // x ^ x = 0 , x ^ 0 = x
    }   
    cout << XOR << endl ;
}

int oncebetter2(int a[] ,int n){

    map<int,int>mp ;  
    for(int i=0 ;i<n ;i++){    //o(nlogm)
        mp[a[i]]+=1 ;
    }   

    for(auto it :mp){          // o(n/2 +1)
        if(it.second == 1)
        cout <<  it.first << endl ; 
    }   
    
    unordered_map<int,int>ump ;   // o(n)
    
}

int oncebetter(int a[] , int n){
    int maxi = a[0] ; 
    for(int i=0;i<n ;i++){    //o(n)
       maxi= max(maxi,a[i]);
    }

    int hash[maxi] = {0};     //sc   o(maxi)
    for(int i=0 ;i<n ;i++){    //o(n)
        hash[a[i]]+=1 ;
    }   

    for(int i=1 ;i<=maxi ;i++){        //o(maxi)
        if(hash[i] == 1)
        cout <<  i << endl ; 
    }   

    for(int i=0 ;i<n ;i++){        //o(n)
        if(hash[a[i]] == 1)
        return a[i] ; 
    }

}

int oncebrute(int a[] , int n){
    for(int i=0 ;i<n ;i++){         // tc o(n*n)
        int num = a[i];             // sc  o(1)
        int cnt=0;
        for(int j=0;j<n;j++){
            if(a[j]==num)
            cnt ++ ;
        }
        if(cnt == 1)
        return a[i] ;
    }
}

int main(){
    int n =9 ;
    int a[9] = {1,1,2,2,3,3,5,7,7} ;

    cout << oncebrute(a,n) << endl;

    cout << oncebetter(a,n) << endl;

    oncebetter2(a,n) ;

    onceoptimal(a,n) ;
}