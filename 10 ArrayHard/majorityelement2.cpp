#include<bits/stdc++.h>
using namespace std ;

int optimal(int a[] , int n){
    vector<int>v ;
    int cnt1 = 0 , cnt2 =0;
    int el1 , el2 ;

    for(int i=0;i<n;i++){   // o(n)
        if(cnt1 == 0 && a[i]!= el2){
            cnt1 = 1;
            el1 = a[i];
        }
        else if(cnt2 == 0 && a[i]!= el1){
            cnt2 = 1;
            el2 = a[i];
        }
        else if (a[i]== el1) cnt1 ++;
        else if (a[i]== el2) cnt2 ++;
        else {
            cnt1-- ;
            cnt2-- ;
        }
    }
    int cntel1 = 0 , cntel2 = 0;
    for(int i=0;i<n;i++){     // o(n)
        if(a[i] == el1) cntel1++ ;
        if(a[i] == el2) cntel2++ ;
    }
    if(cntel1 > n/3) v.push_back(el1) ;
    if(cntel2 > n/3) v.push_back(el2) ;
    
    for(auto it:v){        
        cout << it << " ";
    }
    cout << endl;
}

int better2(int a[] , int n){
    map<int,int>mp ; // sc o(n)
    vector<int>v ;

    for(int i=0;i<n;i++){     // o(nlogn)
        mp[a[i]]+=1 ;
        if(mp[a[i]] >n/3) v.push_back(a[i]) ;
        if(v.size() == 2) break;
    }
    for(auto it:v){        
        cout << it << " ";
    }
    cout << endl;
}

int better(int a[] , int n){
    map<int,int>mp ; // sc o(n)

    for(int i=0;i<n;i++){     // o(nlogn)
        mp[a[i]]+=1 ;
    }
    for(auto it:mp){        //o(n)
        if(it.second > n/3) cout << it.first << " " ;
    }
    cout << endl;
}

void brute2(int a[],int n){
    vector<int>v ;            //sc ~ o(1)

    for(int i= 0;i<n;i++){      //tc ~ o(n^2)
        if(v.size() == 0 || v[0]!=a[i]){
            int cnt = 0;
            for(int j=0 ;j<n ;j++){
                if(a[j]==a[i]){
                    cnt ++ ;
                }
            }
            if(cnt>n/3) {
                v.push_back(a[i]);
                if(v.size() == 2) break;
            }
        } 
    }
    
    for(auto it :v){
        cout << it << " " ;
    }
    cout << endl ;
}

void brute(int a[],int n){
    set<int>st ;       //sc : o(1)            tc o(n^2)

    for(int i= 0;i<n;i++){      
        int cnt = 0;
        for(int j=0 ;j<n ;j++){      //o(n)
            if(a[j]==a[i]){
                cnt ++ ;
            }
        }
        if(cnt>n/3) st.insert(a[i]);   //o(1)  at most 2 el
    }
    
    for(auto it :st){
        cout << it << " " ;
    }
    cout << endl ;
}


//majority > n/3
int main(){
    int n =8 ;
    int a[n] = {1,1,1,2,2,3,3,3};

    brute2(a,n);
    better2(a,n);

    optimal(a,n);
}