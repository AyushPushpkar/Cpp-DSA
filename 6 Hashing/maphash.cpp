#include<bits/stdc++.h>
using namespace std;

int main(){
    int a[6]={2,3,2,5,2,7};
     
    map<int,int>mpp;
    for(int i=0;i<6;i++){
        //storing o(logn)
        mpp[a[i]]+=1;
    }
    
    priority_queue<int>pq;
    for(auto it:mpp){
        cout << it.first << "->" << it.second << endl;
        pq.push(it.second);
    }
    for(auto it:mpp){//highest frequency
        if(it.second == pq.top())
        cout << it.first << endl;
    }
    cout << endl; 
     
    //fetch o(logn)
    int q;
    cin >> q;
    while(q--){
        int num;
        cin >> num;

        cout << mpp[num] <<endl;
    } 

    map<char,int>mpp2; 

    unordered_map<int,int>um;
    //storing o(N)   worst case
    //fetching o(N) no of element in the map
    //best,avg case o(1)

    //division method
}