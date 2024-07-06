#include<bits/stdc++.h>
using namespace std ;

//sum of triplet = 0
//no repeatition
//no dulplicate triplet

//2 pointer
void optimal(int a[] , int n){
    vector<vector<int>>ans ;
    sort(a,a+n) ;        //  o(nlogn)
    int i=0 ;

    while(i<n-2){
        int temp  = a[i] ;
        int j= i+1 , k =n-1 ;
        while(j<k){
            int temp1 =a[j] ,temp2 = a[k] ;
            int sum = a[i]+a[j]+a[k] ;
            if(sum == 0){
                vector<int>tempv = {a[i],a[j],a[k]};
                ans.push_back(tempv) ;
                while(a[j] == temp1 && j<k){
                    j++ ;
                }
                while(a[k] == temp2 && j<k){
                    k-- ;
                }
            }
            else if(sum < 0){
                while(a[j] == temp1 && j<k){
                    j++ ;
                }
            }
            else {
                while(a[k] == temp2 && j<k){
                    k-- ;
                }
            }
        }
        while(a[i] == temp && i<n-2){
            i++ ;
        }
    }

    for(auto it : ans){
        for(auto itt : it){
            cout << itt << " " ;
        }
        cout << endl;
    }
    
} 

void optimal2(int a[] , int n){
    vector<vector<int>>ans ;
    sort(a,a+n) ;          // o(nlogn)

    for(int i=0;i<n-2;i++){       // tc ~ o(n^2)
        if(i>0 && a[i] == a[i-1]) continue; // goes back to condn
        int j= i+1 , k =n-1 ;
        while(j<k){
            int temp1 =a[j] ,temp2 = a[k] ;
            int sum = a[i]+a[j]+a[k] ;
            if(sum == 0){
                vector<int>tempv = {a[i],a[j],a[k]};
                ans.push_back(tempv) ;
                while(a[j] == temp1 && j<k){
                    j++ ;
                }
                while(a[k] == temp2 && j<k){
                    k-- ;
                }
            }
            else if(sum < 0){
                    j++ ;
            }
            else {
                    k-- ;
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
    set<vector<int>>ans ;    //sc: o(no of triplets)

    for(int i=0;i<n;i++){   // o(n^2)
        set<int>hash ;         
        for(int j=i+1;j<n;j++){
            int tri = -(a[i]+a[j]) ;
            if(hash.find(tri) != hash.end()){
                vector<int>temp = {a[i] ,a[j],tri};
                sort(temp.begin() , temp.end());  //o(1)
                ans.insert(temp) ;  //   o(log (unique triplets))
            }
            hash.insert(a[j]) ;    // o(log (size of hash))
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
    set<vector<int>>ans ;    //sc: o(no of triplets)

    for(int i=0;i<n;i++){           // o(n^3)
        for(int j=i+1;j<n;j++){
            for(int k=j+1 ;k<n;k++){
                if(a[i] +a[j] +a[k] == 0){
                    vector<int>temp = {a[i],a[j],a[k]};
                    sort(temp.begin(),temp.end());  //only 3 el
                    ans.insert(temp);    // o(log (unique triplets)) ordered
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
    int a[n] ={-1,0,1,2,-1,-4};

    // brute(a,n);

    better(a,n) ;
    cout << endl ;

    int m =13 ;
    int arr[m] = {-2,-2,3,0,2,0,-2,1,2,2,-1,-1,2} ;
    optimal2(arr,m) ;
}