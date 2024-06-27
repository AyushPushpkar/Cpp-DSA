#include<bits/stdc++.h>
using namespace std;

int linearSearch(int a[], int n){
    int q;
    cin >> q;

    for(int i=0;i<n ;i++){
        if(a[i] == q){
            return i;
        } 
    }
    return -1 ;
}

void optimal(int a[] , int n){
    
    int index = -1;
    for(int i=0 ; i<n ; i++){    
        if(a[i] == 0){     
            index = i ;
            break;
        }
    }
    if(index == -1){
        cout << "no zero" << endl; 
    }

    for(int i=index+1 ; i<n ; i++){    //tc : o(n)
        if(a[i] != 0){     // sc o(1)
            swap(a[index],a[i]);
            index++;
        }
    }
    for(int i=0 ;i<n ;i++){
        cout << a[i] << " " ;
    }    
    cout << endl;
}

void Brute2( int a[], int n){       // tc o(2n)
    vector<int>v ;

    for(int i =0;i<n;i++){   //o(n)
        if(a[i]!=0){
            v.push_back(a[i]);     // sc o(x)
        }
    }
    int nz = v.size();
    for(int i=0 ; i<nz ; i++){     //o(n)
        a[i] = v[i];
    }
    for(int i=nz ; i<n ; i++){    //o(n-x)
        a[i] = 0;
    }

    for(int i=0 ; i<n ; i++){
        cout << a[i] << " ";
    }
}

void Brute( int a[], int n){
    vector<int>v ;

    for(int i =0;i<n;i++){   //o(n)
        if(a[i]!=0){
            v.push_back(a[i]);     // sc o(x)
        }
    }
    for(int i=0 ; i<n ; i++){  //o(n)
        a[i]=0;
    }

    int j=0 ;
    for(auto it:v){      // o(x)
        a[j] = it ;
        j++ ;
    }

    for(int i=0 ; i<n ; i++){
        cout << a[i] << " ";
    }
}

int main(){
    int a[]= {0,1,2,0,4,6,1,0,0,5,0} ;

    int n = sizeof(a)/sizeof(a[0]);
    cout << n << endl;

    cout << linearSearch(a,n) << endl ;

    // Brute2(a,n);

    optimal(a,n) ;
}