#include<bits/stdc++.h>
using namespace std ;

//Moore's voting algo
int optimal(int a[] , int n){
    int cnt = 0;
    int el ;
    for(int i=0;i<n;i++){   // o(n)
        if(cnt == 0){
            cnt = 1;
            el = a[i];
        }
        else if (a[i]== el) cnt ++;
        else cnt -- ;
    }
    int cnt1 = 0;
    for(int i=0;i<n;i++){     // o(n)
        if(a[i] == el) cnt1 ++;
    }
    if(cnt1 > n/2) return el ;
    return -1 ;
}

int better(int a[] , int n){
    map<int,int>mp ; // sc o(n)

    for(int i=0;i<n;i++){     // o(nlogn)
        mp[a[i]]+=1 ;
    }
    for(auto it:mp){        //o(n)
        if(it.second > n/2) return it.first ;
    }
    return -1 ;
}

int brute(int a[],int n){
    for(int i= 0;i<n;i++){        //tc o(n^2)
        int cnt = 0;
        for(int j=0 ;j<n ;j++){
            if(a[j]==a[i]){
                cnt ++ ;
            }
        }
        if(cnt>n/2) return a[i] ;
    }
    return -1 ;
}

int main(){
    int n = 9;
    int a[n] = {2,2,3,2,1,1,2,5,2};

    cout << brute(a,n) << endl ;

    cout << better(a,n) << endl ;

    cout << optimal(a,n) << endl ;
}