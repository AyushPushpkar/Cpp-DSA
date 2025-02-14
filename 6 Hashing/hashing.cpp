#include<bits/stdc++.h>
using namespace std;

 void frequencyCount(vector<int>& arr, int N) {
    // Initialize a hash array to count frequencies from 1 to N
    int hash[N + 1] = {0};

    // Count frequencies of elements from 1 to N in arr
    for (int i = 0; i < N; i++) {
        if (arr[i] >= 1 && arr[i] <= N) {
            hash[arr[i]]++;
        }
    }

    // Update arr to store frequencies of elements from 1 to N
    for (int i = 0; i < N; i++) {
        arr[i] = hash[i + 1]; // i+1 because we are dealing with 1-based index
    }
}

void hashg(int arr[],int l,int n){
    int cnt=0;
    for(int i=0;i<l;i++){ //o(l)
    if(n==arr[i])
    cnt=cnt+1;
    } 
    cout << cnt << endl << '\n'; //o(q*l)
}

int main(){
    int n,l=6;
    cin >> n;
    int arr[l]={1,4,1,2,3,2};
    hashg(arr,l,n);

    int m;
    cin >> m ;
    int a[m];
    for(int i=0;i<m;i++){
        cin >> a[i];
    }

    //precompute
    int hash[13]={0};
    for(int i=0;i<m;i++){
        hash[a[i]]+=1;
    }

    int q;
    cin >> q;
    while(q>0){
        int num;
        cin >> num;
        q--;

        //fetch
        cout << hash[num] << endl;
    }
    return 0;
}