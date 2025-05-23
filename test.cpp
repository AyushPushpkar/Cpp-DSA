#include <bits/stdc++.h>
using namespace std;


int main() {
    vector<int> v1(5,20); // size , value
    vector<int> v2(v1);

    //iterator
    vector<int>:: iterator it = v1.begin();
    it++;
    cout << *(it);  
}
