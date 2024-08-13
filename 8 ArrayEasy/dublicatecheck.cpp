#include<bits/stdc++.h>
using namespace std ;


void optimal (int a[],int n){

    sort(a,a+n);

    int index = 0;
    for(int i=1 ; i<n ; i++){    //tc : o(n)
        if(a[i] != a[index]){     // sc o(1)
            a[index+1]=a[i];
            index++;
        }
    }cout << index+1 << endl;
    for(int i=0 ;i<=index ;i++){
        cout << a[i] << " " ;
    }    
    cout << endl;
}

void duplicate (int a[],int n){
    set<int> st;
    for(int i=0;i<n ;i++){   //o(nlogn)
        st.insert(a[i]);
    }
    int index =0 ;        
    for(auto it : st){       //o(n)
        a[index] = it ;   
        index++;    //sc o(n)
    }
    for(int i=0 ;i<index ;i++){
        cout << a[i] << " " ;
    }
    cout << endl;
}

void check(int a[], int n){
    int yes =0;
    for(int i=1 ;i<n-1;i++){   //o(n)
        if(a[i]>a[i+1]){
            yes+=1 ;
        }
    }
    if(yes == 0){
         cout << "sorted" << endl;
    }
    else{
        cout << "unsorted" << endl  ;
    }
}

int main(){
    int n = 8;
    cin >> n;
    int a[n] = {1,3,4,4,7,9,9,11};
    for(int i=0 ; i<n ; i++){
        cin >> a[i];
    }

    check(a,n);

    // duplicate(a,n); 
    optimal(a,n);
}