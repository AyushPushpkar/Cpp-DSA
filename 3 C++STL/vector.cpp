#include<bits/stdc++.h>
using namespace std;

void expvector(){
    vector<int> v;

    v.push_back(1);
    v.emplace_back(2);

    vector<int> v1(5,20);
    vector<int> v2(v1);

    //iterator
    vector<int>:: iterator it = v.begin();
    it++;
    cout << *(it);  

    vector<int>::iterator it=v.end();

    sort(v.begin(),v.end());
    
    cout << v.back();

    for(vector<int>::iterator it=v.begin();it!= v.end();it++){
        cout << *(it) ;
    }
    for(auto it=v.begin();it!= v.end();it++){
        cout << *(it) ;
    }
    for(auto it:v){
        cout << it ;
    }
    
    v.erase(v.begin()+1);
    //(st,end)
    v.erase(v.begin()+1,v.begin()+3);

    v.insert(v.begin()+1,200);
    v.insert(v.begin()+1,2 ,300);

    v.size();
    v.pop_back();
    v.swap(v2);

    v.clear();

    cout <<v.empty();
}