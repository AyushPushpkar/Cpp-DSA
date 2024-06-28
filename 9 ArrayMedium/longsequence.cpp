#include<bits/stdc++.h>
using namespace std ;

int optimal(int arr[] ,int m){
    if(m==0) return 0;

    unordered_set<int>st ;      // sc  o(n)
    int longest =1 ;
    int cnt = 0 ;
    
    for(int i=0;i<m;i++){            // o(n)
        st.insert(arr[i]);
    }
    for(auto it : st){
        if(st.find(it-1) == st.end()){
            cnt = 1 ;
            int x =it ;
            while(st.find(x+1) != st.end()){
                cnt += 1;
                x += 1;
            }
            longest = max(longest ,cnt) ;
        }
    }

    return longest ;
}

int better(int arr[] ,int m){
    int longest =1 ;
    int lastsmall =INT_MIN ;
    int cntcur = 0 ;
    sort(arr,arr+m);     // o(nlogn)
    
    for(int i=0;i<m;i++){            // o(n)
        if(lastsmall == arr[i]-1 ){
            cntcur +=1 ;
            longest = max(longest,cntcur);
        }
        else if(lastsmall != arr[i]){
            cntcur =1 ; 
        }  
        lastsmall =arr[i] ;
    }
    return longest ;
}

//linearsearch
bool ls(int a[] ,int n , int num){

    for(int i=0;i<n ;i++){
        if(a[i] == num){
            return true ;
        }
    }
    return false ;
}

int brute(int a[] , int n){
    int longest = 1;        //sc  o(1)

    for(int i=0;i<n;i++){   // tc ~ o(n^2)
        int x=a[i];
        int cnt =1 ;
        while(ls(a,n,x+1) == true){
            x += 1;
            cnt +=1 ;
        } 
        longest = max(longest ,cnt) ;
    }
    return longest ;
}

int main(){
    int n = 9;
    int a[n] = {102,4,100,1,101,3,2,1,1};

    cout << brute(a,n) << endl;

    int m=14;
    int arr[m]= {100,102,100,101,101,4,3,2,3,2,1,1,1,2} ;

    cout << better(arr,m) <<endl ;

    cout << optimal(arr,m) <<endl ;
}