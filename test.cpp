#include<bits/stdc++.h>
using namespace std;

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
