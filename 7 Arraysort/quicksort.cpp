#include<bits/stdc++.h>
using namespace std;

//pick a pivot & place it in correct position in sorted array
//smaller on the left and larger on the right

int partition(int a[],int low, int high){
    int pivot=a[low];
    int i = low , j= high ;
    while(i<j){
        while((a[i]<=pivot)&&(i<high)){
            i++;
        }
        while((a[j]>pivot)&&(j>low)){
            j--;
        }
        if(i<j)
        swap(a[i],a[j]);
    }
    swap(a[low],a[j]);
    return j;
}

void quicksort(int a[], int low,int high){
    if(low<high){
        int pindex = partition(a,low,high);
        quicksort(a,low,pindex-1);
        quicksort(a,pindex+1,high);
    }
}

int main(){
    int n;
    cin >> n;
    int a[n];
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    int low=0,high=n-1;

    quicksort(a, low, high);

    for(int i=0;i<n;i++){
        cout << a[i] << " " ;
    }
}