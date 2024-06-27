#include<bits/stdc++.h>
using namespace std ;

//repeatition allowed
void optimalInter(int a[],int n, int arr[],int m){
    vector<int>interarr ;
    int i=0 , j=0 ;           // sc o(1)

    while(i<n && j<m){         //tc o(n+m)
        if(a[i]< arr[j]){
            i++;
        }
        else if(a[i]> arr[j]){
            j++;
        }
        else{
            interarr.push_back(a[i]) ;
            i++;
            j++ ;
        }
    }

    int size = interarr.size();
    for(int i=0 ;i<size ; i++){
        cout << interarr[i] <<" ";
    }
    
}

void bruteInter(int a[],int n, int arr[],int m){
    vector<int>interarr ;
    int v[m] = {0} ;   //visited arr   // sc o(m)

    for(int i=0;i<n ;i++){        // tc o(n*m)
        for(int j=0 ;j<m ;j++){
            if(a[i]==arr[j] && v[j]==0){
                interarr.push_back(a[i]);
                v[j] = 1;
                break;
            } 
            if(arr[j]>a[i])
            break;
        }
    }

    int size = interarr.size();
    for(int i=0 ;i<size ; i++){
        cout << interarr[i] <<" ";
    }
    
}

void optimalUnion(int a[],int n, int arr[],int m){
    vector<int> unionarr ;
    int i=0 , j=0;                 //tc o(n+m)

    while((i<n)&&(j<m)){
        if(a[i]<=arr[j]){
            if(unionarr.size()== 0 || unionarr.back()!=a[i]){
                unionarr.push_back(a[i]) ;
            }
            i++ ;
        }
        else{
            if(unionarr.size()== 0 || unionarr.back()!=arr[j]){
                unionarr.push_back(arr[j]) ;
            }
            j++ ;
        }
    }
    while(i<n){  
        if(unionarr.size()== 0 || unionarr.back()!=a[i]){
            unionarr.push_back(a[i]) ;
        }
        i++ ;
    }
     while(j<m){  
        if(unionarr.size()== 0 || unionarr.back()!=a[j]){
            unionarr.push_back(arr[j]) ;
        }
        j++ ;
    }

    int size = unionarr.size();     //sc o(n+m) to return
    for(int i=0 ;i<size ; i++){
        cout << unionarr[i] <<" ";
    }
}

void bruteUnion(int a[],int n, int arr[],int m){
    set<int>st ;

    for(int i=0;i<n ;i++){      // o(nlog(size1))
        st.insert(a[i]);
    }
    for(int i=0 ;i<m ;i++){     // 0(mlog(size2))
        st.insert(arr[i]);
    }

    int size = st.size();
    int unionarr[size] ;
    int j=0 ;
    for(auto it :st){          // o(n+m)
        unionarr[j] = it ;
        j++;
    }
    
    for(int i=0 ;i<size ; i++){
        cout << unionarr[i] <<" ";
    }
}

int main(){
    int n=8 ,m=6 ;
    int a[n]={1,1,3,5,6,8,8,8} ;
    int arr[m]={0,1,5,5,7,8} ;

    // bruteUnion(a,n, arr,m);

    // optimalUnion(a,n,arr,m) ;

    // bruteInter(a,n,arr,m) ;

    optimalInter(a,n,arr,m) ;
}