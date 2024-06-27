#include<bits/stdc++.h>
using namespace std;

void arrangeoptimal(int a[] ,int n){
    vector<int>ans(n,0);       // sc o(n)
    int posindex = 0 , negindex = 1 ;
    
    for(int i=0;i<n;i++){       // o(n)
        if(a[i]<0){
            ans[negindex] =a[i]; 
            negindex +=2;
        }
        else{
            ans[posindex] =a[i];
            posindex += 2;
        }
    }

    for(auto it: ans){
        cout << it << " " ;
    }
    cout << endl ;
}

void arrangebrute(int a[] ,int n){
    vector<int>pos;       // sc o(n/2)
    vector<int>neg ;      // sc o(n/2)

    for(int i=0;i<n;i++){       // o(n)
        if(a[i]>0){
            pos.push_back(a[i]);
        }
        else if(a[i]<0){
            neg.push_back(a[i]);
        }
    }
    for(int i=0;i<n/2;i++){   // o(n/2)
        a[2*i]=pos[i];
        a[2*i+1]=neg[i];
    }
    for(int i=0;i<n;i++){
        cout << a[i] << " " ;
    }
    cout << endl ;
}

int main(){
    int n =6;
    int a[n] = {3,1,-2,-5,2,-4} ;

    // arrangebrute(a,n);

    arrangeoptimal(a,n);
}