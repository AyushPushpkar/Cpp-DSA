#include<bits/stdc++.h>
using namespace std ;

//sum of 4 el = 0
//no repeatition
//no dulplicate 

void optimal(int a[] , int n){
    vector<vector<int>>ans ;
    sort(a,a+n) ;

    for(int i=0;i<n-2;i++){      // tc ~ o(n^3)
        if(i>0 && a[i] == a[i-1]) continue;
        for(int j=i+1;j<n;j++){
            if(j != i+1 && a[j] == a[j-1]) continue; 
                int k= j+1 , l =n-1 ;
                while(k<l){
                    int temp1 =a[k] ,temp2 = a[l] ;
                    int sum = a[i]+a[j]+a[k] +a[l] ;
                    if(sum == 0){
                    vector<int>tempv = {a[i],a[j],a[k],a[l]};
                    ans.push_back(tempv) ;
                    while(a[k] == temp1 && k<l){
                        k++ ;
                    }
                    while(a[l] == temp2 && k<l){
                        l-- ;
                    }
                }
                else if(sum < 0){
                    while(a[k] == temp1 && k<l){
                        k++ ;
                    }
                }
                else {
                    while(a[l] == temp2 && k<l){
                        l-- ;
                    }
                }
            }
        }
    }

    for(auto it : ans){
        for(auto itt : it){
            cout << itt << " " ;
        }
        cout << endl;
    }
    
} 

void better(int a[] , int n){
    set<vector<int>>ans ;    //sc: o(no of quadruplets)

    for(int i=0;i<n;i++){   // o(n^3)        
        for(int j=i+1;j<n;j++){
            set<int>hash ;          //sc : o(n)
            for(int k=j+1;k<n;k++){
                int quad = -(a[i]+a[j]+a[k]) ;
                if(hash.find(quad) != hash.end()){
                    vector<int>temp = {a[i] ,a[j],a[k],quad};
                    sort(temp.begin() , temp.end());  //o(1)
                    ans.insert(temp) ;  //   o(log (unique quadplets))
                }
                hash.insert(a[k]) ;    // o(log (size of hash))
            }
        }
    }
    for(auto it : ans){
        for(auto itt : it){
            cout << itt << " " ;
        }
        cout << endl;
    }
} 

void brute(int a[] , int n){
    set<vector<int>>ans ;    //sc: o(no of quadruplets)

    for(int i=0;i<n;i++){           // o(n^4)
        for(int j=i+1;j<n;j++){
            for(int k=j+1 ;k<n;k++){
                for(int l=k+1;l<n;l++){
                    if(a[i] +a[j] +a[k] +a[l] == 0){
                        vector<int>temp = {a[i],a[j],a[k],a[l]};
                        sort(temp.begin(),temp.end());  //only 4 el
                        ans.insert(temp);    // o(log (unique quadruplets)) ordered
                    }  
                } 
            }
        }
    }
    for(auto it : ans){
        for(auto itt : it){
            cout << itt << " " ;
        }
        cout << endl;
    }
}

int main(){
    int n=6;
    int a[n] ={-1,0,1,2,0,-2};

    // brute(a,n);

    better(a,n) ;
    cout << endl ;

    int m =13 ;
    int arr[m] = {-2,-2,3,0,2,0,-2,1,2,2,-1,-1,2} ;
    optimal(arr,m) ;
}