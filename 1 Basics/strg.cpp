#include<bits/stdc++.h>
using namespace std;

int main(){
    string s = "Monster Verse";
    int len= s.size();
    cout << s[len-1];
    cout << s[0] << endl;

        string f;  //filter
        for(char c : s){
            if(isalnum(c)) {
                f+= tolower(c);
            }
        }
        cout << f ;

    return 0;
}