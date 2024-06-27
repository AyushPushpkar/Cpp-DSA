#include<bits/stdc++.h>
using namespace std;

void divisors(int n){
    int i ,cnt=0;
    for(i=1;i<=n;i++){
        if(n%i==0){
        cout << i << " "; // o(n)
        cnt+=1;
        }
    }cout << endl;
    if(cnt==2)
    cout << "prime" << endl;
    else cout << "not prime" << endl;
}

void divisors2(int n){
    int i;
    vector<int>v;
    //strt : mathematical function takes time
    for(i=1;i<=sqrt(n);i++) // o(sqrtn)
    {
        if(n%i==0){
            v.push_back(i);
            if(i!=n/i)
            v.push_back(n/i);
        }
    }
    // o(n logn) n = no.of factors
    // internal sorting
    sort(v.begin(),v.end(),greater<int>()); 
    for(auto it:v)  // o(n) n = factors
    cout << it << " ";
    cout << endl ;
}

void divisors3(int n){
    int i ,p;
    set<int>st;
    for(i=1;i*i<=n;i++) 
    {
        if(n%i==0){
            st.insert(i);
            if(i!=n/i)
            st.insert(n/i);
        }
    }
    for(auto it:st)
    cout << it << " ";
    cout << endl ;
    p=st.size(); //prime
    if (p==2) // o(sqrtn)
    cout << "prime" << endl;
    else cout << "not prime" << endl ;
}

int main(){
    int n;
    cin >> n;
    divisors(n);
    divisors2(n);
    divisors3(n);
    return 0;
}