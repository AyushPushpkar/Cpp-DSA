#include<bits/stdc++.h>
using namespace std ;

//minimise max dist to gas stations

int gasStationsReq(int a[] ,int n ,int dist){
    int cnt =0 ;
    for(int j=0;j<n-1 ;j++){
        int noInBetween = (a[j+1]-a[j])/dist ;
        if((a[j+1]-a[j]) == noInBetween*dist){
            noInBetween-- ;
        }
        cnt += noInBetween ;
    }
    return cnt ;
}

long double binary(int a[] ,int n ,int  gasStation){
    long double low =0 ;
    long double high = 0 ;
    for(int j=0;j<n-1 ;j++){
        high = max(high , (long double)(a[j+1] - a[j])) ;
    }

    long double diff = 1e-6 ;
    while(high- low > diff){         // o(log(high-low+1)*n)  
        long double mid = (low+high)/(2.0) ;
        int cnt = gasStationsReq(a,n,mid) ;
        if(cnt > gasStation){
            low = mid ;
        }
        else{
            high = mid ;
        }
    }
    return high ;

}

long double pQueue(int a[] ,int n ,int  gasStation){
    vector<int> howMany(n - 1, 0);            // sc : o(n-1)
    priority_queue<pair<long double,int>> pq ;

    for(int j=0 ;j<n-1 ;j++){               // o(n*logn)
        pq.push({a[j+1] - a[j] , j}) ;
    }

    for(int i=1 ;i<= gasStation ;i++){   // o(k*logn)  
        auto tp = pq.top() ;
        pq.pop() ;
        int secInd = tp.second ;
        howMany[secInd] ++ ;
        long double iniDiff = a[secInd+1] - a[secInd] ;
        long double newSecLen = iniDiff/(long double)(howMany[secInd]+1) ;
        pq.push({newSecLen ,secInd}) ;
    }

    return pq.top().first ;
}

long double brute(int a[] ,int n ,int  gasStation){
    vector<int> howMany(n - 1, 0);

    for(int i=1 ;i<= gasStation ;i++){   // o(k*n)  TLE
        long double maxSec = -1 ;
        int maxInd = -1 ;
        for(int j=0 ;j<n-1 ;j++){
            long double diff = a[j+1] - a[j] ;
            long double secLen = diff/(long double)(howMany[j]+1) ;
            if(maxSec < secLen){
                maxSec = secLen ;
                maxInd = j ;
            }
        }
        howMany[maxInd] ++ ;
    }

    long double maxAns = -1 ;

    for(int j=0 ; j<n-1 ;j++){
        long double diff = a[j+1] - a[j] ;
        long double secLen = diff/(long double)(howMany[j]+1) ;
        maxAns = max(maxAns , secLen) ;
    }

    return maxAns ;
}

int main(){
    int n =4 ;
    int a[] = {1,13,17,23} ;  // coordinates of gas stations (sorted)

    int  k = 5 ;  // k new gas stations
    //decimals allowed 

    cout << fixed << setprecision(6) << brute(a, n, k) << endl;

    cout << fixed << setprecision(6) << pQueue(a,n,k) << endl ;

    cout << fixed << setprecision(6) << binary(a,n,k) << endl ;

    return 0;
}