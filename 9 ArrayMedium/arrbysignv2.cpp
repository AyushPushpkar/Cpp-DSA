#include<bits/stdc++.h>
using namespace std ;

void brute(int a[] ,int n){
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
    if(pos.size() > neg.size()){          //o(n)
        for(int i=0;i<neg.size();i++){   
            a[2*i]=pos[i];
            a[2*i+1]=neg[i];
        }
        int index = 2*neg.size();
        for(int i= neg.size();i<pos.size();i++){
            a[index] = pos[i] ;
            index++ ;
        }
    }
    else{
        for(int i=0;i<pos.size();i++){   
            a[2*i]=pos[i];
             a[2*i+1]=neg[i];
        }
        int index = 2*pos.size();
        for(int i= pos.size();i<neg.size();i++){
            a[index] = neg[i] ;
            index++ ;
        }
    }
   

    for(int i=0;i<n;i++){
        cout << a[i] << " " ;
    }
    cout << endl ;
}

int main(){
    int n = 8; 
    int a[n] = {1,2,-4,-5,3,6,-1,4};

    brute(a,n) ;
}