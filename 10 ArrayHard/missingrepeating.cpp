#include<bits/stdc++.h>
using namespace std ;

void optimal2(int a[] ,int n){ 
    int xr = 0 ;        // tc o(n)

    for(int i=0;i<n;i++){     // o(n)
        xr = xr^a[i]^(i+1) ;
    }

    int bitno =0 ;
    while(1){             //infinit loop until break
        if( (xr & (1 << bitno)) != 0){
            break;
        }
        bitno ++ ;
    }
    int zero =0 ;
    int one = 0 ;
    for(int i=0 ;i<n ;i++){
        // 1 club
        if((a[i] & (1<< bitno)) != 0){
            one = one  ^a[i] ;
        }
        else{
            zero = zero^a[i] ;
        }
    }
    for(int i=1 ;i<=n ;i++){
        // 1 club
        if((i & (1<< bitno)) != 0){
            one = one  ^i ;
        }  // 0 club
        else{
            zero = zero^i ;
        }
    }

    int cnt = 0 ;
    for(int i=0 ;i<n ;i++){
        if(a[i]  == zero){
            cnt ++ ;
        }
    }
    if(cnt == 2) cout << one << " , " << zero << endl ;
    else if (cnt == 0) cout << zero << " , " << one << endl ;

}

void optimal(int a[] ,int n){
    int x , y ;   
    int sum = n*(n+1)/2 ;    // sc o(1)
    int s =0 ,sqs =0 ;
    int sqsum = (n*(n+1)*(2*n +1))/6 ;

    for(int i=0;i<n;i++){     // o(n)
        s += a[i] ;       
        sqs += a[i]*a[i] ;
    }

    int diff = s -sum ;
    int add = (sqs - sqsum)/diff ;

    x = (diff+add)/2 ;
    y = (add -diff)/2 ;

    cout << y << " , " << x <<endl ;
}

void better(int a[] ,int n){
    int miss =-1 ;
    int repeat = -1 ;
    int hash[n+1] ={0} ;    // sc :o(n)

    for(int i=0 ;i<n ;i++){    // o(n)
        hash[a[i]]+= 1 ;
    }

    for(int i=1;i<=n;i++){        // o(n)
        if(hash[i] == 0) miss = i ;
        else if(hash[i] == 2) repeat = i ;
        if(miss != -1 && repeat != -1) break;
    }
    cout << miss << " , " << repeat << endl ;
}

void brute(int a[] ,int n){
    int miss =-1 ;
    int repeat = -1 ;

    for(int i=1;i<=n;i++){
        int cnt =0 ;
        for(int j=0 ;j<n ;j++){
            if(i == a[j])
            cnt++;
        }
        if(cnt == 0) miss = i ;
        else if(cnt == 2) repeat =i ;
        if(miss != -1 && repeat != -1) break;
    }
    cout << miss << " , " << repeat << endl ;
}

int main(){
    int n=6;
    int a[n] = {2,4,6,3,1,1} ;

    brute(a,n) ;

    better(a,n) ;

    optimal(a,n ) ;
    optimal2(a,n ) ;
}