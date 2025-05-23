#include<bits/stdc++.h>
using namespace std ;

int merge(int a[],int low ,int mid , int high){
    vector<int>v; //temp container           //sc o (n)
    int left =low;
    int right = mid+1;
    int cnt= 0 ;
    while((left<=mid)&&(right<=high)){      // o(nlogn)
        if(a[left]<=a[right]){
            v.push_back(a[left]);
            left++;
        }
        else{
            v.push_back(a[right]);
            cnt += (mid - left +1) ;   // sorted arrays
            right++;
        }
    }
    while(left<=mid){
        v.push_back(a[left]);
        left++;
    }
    while(right<=high){
        v.push_back(a[right]);
        right++;
    }
    for(int i=low;i<=high;i++){
        a[i]=v[i-low];
    }
    return cnt ;
}

int mergesort(int a[],int low, int high){
    int cnt = 0 ;
    if(low>=high)return cnt ; //base case
    int mid= (low + high)/2;
    cnt += mergesort(a,low,mid);  //divide
    cnt +=mergesort(a,mid+1,high);
    cnt += merge(a,low,mid,high); //merge
    return cnt ;
}

int brute(int a[] ,int n){
    int cnt = 0 ;

    for(int i=0;i<n ;i++){          //tc : o(n^2)
        for(int j=i+1 ;j<n;j++){
            if(a[j] < a[i]){
                cnt++ ;
            }
        }
    }
    return cnt  ;
}

int main(){
    int n =5 ;
    int a[n] = {5,3,2,4,1} ;

    cout << brute(a,n) << endl;

    cout << mergesort(a,0,n-1) << endl;
    
}