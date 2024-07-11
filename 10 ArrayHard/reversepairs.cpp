#include<bits/stdc++.h>
using namespace std ;

// i<j && a[i] > 2*a[j]

void merge(int a[],int low ,int mid , int high){
    vector<int>v; //temp container
    int left =low;
    int right = mid+1;
    while((left<=mid)&&(right<=high)){
        if(a[left]<=a[right]){
            v.push_back(a[left]);
            left++;
        }
        else{
            v.push_back(a[right]);
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
    return ;
}

int cntPairs(int a[] ,int low ,int mid , int high){
    int cnt = 0 ;
    int right = mid+1 ;

    for(int i=low ;i<=mid;i++){
        while(right <=high && a[i] > 2*a[right] ){
            right++ ;
        }
        cnt += (right -(mid+1)) ;
    }
    return cnt ;
}

int mergesort(int a[],int low, int high){
    int cnt = 0 ;
    if(low>=high)return cnt ; //base case
    int mid= (low + high)/2;
    cnt += mergesort(a,low,mid);  //divide
    cnt +=mergesort(a,mid+1,high);
    cnt += cntPairs(a,low,mid,high) ;
    merge(a,low,mid,high); //merge
    return cnt ;
}

int brute(int a[] ,int n){
    int cnt =0 ;

    for(int i=0 ;i<n ;i++){        //tc ~ o(n^2)
        for(int j=i+1 ;j<n ;j++){
            if(a[i] > 2*a[j]){
                cnt++ ;
            }
        }
    }
    return cnt ;
}

int main(){
    int n= 7;
    int a[n] ={40 ,25 ,19 ,12 ,9 ,6  ,2} ;

    cout << brute(a,n) << endl ;

    cout << mergesort(a,0,n-1) << endl ;
}