#include<bits/stdc++.h>
using namespace std;

//divide  and merge

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

void mergesort(int a[],int low, int high){
    if(low>=high)return ; //base case
    int mid= (low + high)/2;
    mergesort(a,low,mid);  //divide
    mergesort(a,mid+1,high);
    merge(a,low,mid,high); //merge

    //tc o(n*log2(n))
    //sc o(n)
}

int main(){
    int n;
    cin >> n;
    int a[n];
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    int low=0,high=n-1;

    mergesort(a,low,high);

    for(int i=0;i<n;i++){
        cout << a[i] << " ";
    }
    return 0;
}