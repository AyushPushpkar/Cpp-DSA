#include<bits/stdc++.h>
using namespace std;

//brings minimun to front by swap 
void selsort(int a[], int n){ 
    for(int i=0;i<=n-2;i++){  //o(n^2)
        int min=i;
        for(int j=i;j<=n-1;j++){
            if(a[j]<a[min])
            min=j;
        }
        //swap
        int temp = a[min];
        a[min]=a[i];
        a[i]=temp;
    }

}

//push the max to last by adjacent swaps
void bubsort(int a[], int n){
    for(int i=0;i<n-1;i++){
        int didswap =0 ; 
        for(int j=0;j<n-1-i;j++){ //o(n^2) worst ,avg
            if(a[j]>a[j+1]){      
                 //swap
                int temp=a[j+1];
                a[j+1]=a[j];
                a[j]=temp;  

                didswap=1;
            } 
        }
        if(didswap == 0){
            break;
        } //o(n) best 
        cout << "runs\n" ;
    }
}

//place element in its correct order
void insort(int a[],int n){
    for(int i=0;i<n;i++){     //o(n^2) worst,best
        int j=i;
        while(j>0 && a[j-1]>a[j]){
            int temp= a[j-1];
            a[j-1]=a[j];
            a[j]=temp;
            j--;
            cout << "runs" ; //o(n)
        }
    }
} 
void insort2(int a[],int n){
    for(int i=0;i<n;i++){
        for(int j=i ; j>0;j--){
            if(a[j-1]>a[j]){
                swap(a[j],a[j-1]);
            }
        }
    }
}

int main(){
    int n;
    cin >> n;
    int a[n];
    for(int i =0;i<n;i++){
        cin >> a[i];
    }

    insort2(a,n);

    for(int i=0;i<n;i++){
        cout << a[i] << " ";
    }
    return 0;
}