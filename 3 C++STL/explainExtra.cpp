#include<bits/stdc++.h>
using namespace std;

void explainExtra1(){
    int a[]={1,7,3,2};
    sort(a,a+4); // o(n log n)
    for(int i=0;i<4;i++)
    cout << a[i] ;
}
void explainExtra2(){
    vector<int>v(2,7);
    v.push_back(2);
    v.emplace_back(1);
    sort(v.begin(),v.end());
    for(auto it:v)
    cout << it ;
}

bool comp(pair<int,int>p1,pair<int,int>p2){
    if(p1.second<p2.second)return true ;
    if(p1.second>p2.second)return false;
    //they are same

    if(p1.first>p2.first)return true;
    return false;
}
void explainExtra(){
    vector<int>v;
    int a,n;
    sort(a+2,a+4);
    sort (a,a+n, greater<int>()); //decreasing order

    pair<int,int> a[3]={{2,1},{3,2},{1,4}};
    sort(a,a+n,comp); //own way
}

void explainExtra4(){
int num=7;
int cnt=__builtin_popcount(num);
long long ll=4567876434578;
int cnt=__builtin_popcountll(ll);
}

void explainExtra3(){
string s="312";
sort(s.begin(),s.end());
do{
    cout << s << endl;
}while(next_permutation(s.begin(),s.end()));

int maxi=*max_element(s.begin(),s.end());
cout << "Max element (ASCII value): " << maxi << endl;
   cout << "Max element (character): " << char(maxi) << endl;
}

int main(){
    explainExtra3(); 
    
}

