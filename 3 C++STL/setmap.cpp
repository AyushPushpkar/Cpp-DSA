#include<bits/stdc++.h>
using namespace std;

void explainSet(){
    set<int>st;
    //sorted and unique
    st.insert(2);
    st.emplace(4);

    auto it=st.find(3); //st.end()

    st.erase(2); //logn

    int cnt=st.count(3); //0

    auto it1=st.find(2);
    auto it2=st.find(4);
    st.erase(it1,it2);

    auto it=st.lower_bound(2); //pending
    auto it=st.upper_bound(4);

}

void multiSet(){
    multiset<int> ms;
    //sorted
    ms.insert(4);
    
    ms.erase(1);
    auto it=ms.count(4);

    ms.erase(ms.find(1));
    ms.erase(ms.find(3), next(ms.find(3), 2));
}

void Uset(){
    unordered_set<int> us;
    //o(1)
    //unique
    //lowerbound/upperbound doesn't work
}

void explainMap(){
   map<int,int>mpp;
   map<int,pair<int,int>>mpp1;
   

   //unique key in sorted order

   mpp[1]=3;
   mpp.emplace(3,1);
   mpp.insert({2,4});
   
   for(auto it :mpp){
    cout << it.first << it.second << endl ;
   }

   auto it=mpp.find(2);
   cout << (*it).second ;
}

void Multimap(){
    //duplicate keys
    //sorted
}

void Unorderedmap(){
    // o(1)
    //unique keys , not sorted
}





