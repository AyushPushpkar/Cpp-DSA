#include<bits/stdc++.h>
using namespace std ;


int positiveoptimal(int a[], int n, int s) {
    int left =0 , right = 0 ;
    int maxLen = 0;                  
    long long sum = a[0];

    while(right < n){               //tc  o(2n)
        while (left <= right && sum > s){
            sum -= a[left];
            left ++ ;
        }
        if(sum == s){
            maxLen = max(maxLen, right - left +1);
        }
        right ++ ;
        if(right < n) sum += a[right] ;  
    }
    
    return maxLen ;
}
 
//optimal for negatives
int positivebetter(int a[], int n, int s) {
    map<long long , int > preSumMap ;   //sc o(n)
    int maxLen = 0;                   // tc o(n)  unordered
    long long sum = 0;

    for(int i=0;i<n;i++){           //tc o(nlogn)
        sum += a[i];
        if(sum == s) maxLen = max(maxLen,i+1);
        
        int rem = sum - s;
        if(preSumMap.find(rem) != preSumMap.end()){
            int len = i - preSumMap[rem] ;
            maxLen = max(maxLen,len) ;
        }
        if(preSumMap.find(sum) == preSumMap.end()){  //for 0s
            preSumMap[sum] = i ; // update index
        }
    } 
    return maxLen ;
}

int positivebrute2(int a[], int n, int s) {
    int len = 0;

    for (int i = 0; i < n; i++) {    //tc ~ o(n^2)
        int sum = 0;
        for (int j = i; j < n; j++) {
            sum += a[j];
            if(sum == s)
            len = max(len , j-i+1) ;
        }
    }
    return len;
}

int positivebrute(int a[], int n, int s) {
    int len = 0;

    for (int i = 0; i < n; i++) {    //tc ~ o(n^3)
        for (int j = i; j < n; j++) {
            int sum = 0;
            for (int k = i; k <= j; k++) {
                sum += a[k];
            }
            if (sum == s) {
                len = max(len, j - i + 1);
            }
        }
    }
    return len;
}

int main(){
    int n= 10;
    int a[n] ={7,2,3,1,1,1,1,4,2,3} ;

//longest subarr with sum s
    int s = 6 ;
    cout << positivebrute(a ,n ,s) << endl;

    cout << positivebrute2(a ,n ,s) << endl;

    cout << positivebetter(a ,n ,s) << endl;

    cout << positiveoptimal(a ,n ,s) << endl;

}