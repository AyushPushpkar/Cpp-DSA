#include<bits/stdc++.h>
using namespace std ;

//for  variety 1 
string optimal(int a[], int n , int target){
    int left = 0;
    int right = n-1 ;   //sc o(1)

    sort(a,a+n);       // o(nlogn)

    while(left<right){      //o(n)
        if(a[left]+a[right] == target){
            return "yes";
        }
        else if(a[left]+a[right] <target)
        left++;
        else right-- ; 
    }
    return "no"; 
}

void better2(int a[] , int n , int target){
    map<int ,int>mp ;

    for(int i=0 ; i<n ; i++){        //tc o(nlogn)
        int rem = target -a[i] ;
        if(mp.find(rem) != mp.end()){
             cout << "yes " << mp[rem] << "," << i << endl ;
        }
         mp[a[i]]=i ;               //sc o(n)
    }
}

void better(int a[] , int n , int target){
    map<int ,int>mp ;

    for(int i=0 ; i<n ;i++){
         mp[a[i]]=i ;
    }
    for(int i=0 ; i<n ; i++){
        int rem = target -a[i] ;
        if(mp.find(rem) != mp.end() && mp[rem] < mp[a[i]]){
             cout << "yes " << mp[rem] << "," << mp[a[i]] << endl ;
        }
    }
}

void brute(int a[], int n , int target){

    for(int i=0 ; i<n ; i++){         //tc ~ o(n^2)
        for(int j=i+1 ; j<n ; j++){
            if(a[i]+a[j] == target){
                cout << "yes " << i << "," << j << endl ;
            }
        }
    }
}

int main(){
    int n = 5;
    int a[n] = {2,6,5,8,11};

int target = 14 ;
    brute(a,n , target);
    better(a,n ,target);
    better2(a,n , target);

    cout << optimal(a , n ,target);
}