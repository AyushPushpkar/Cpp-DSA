#include<bits/stdc++.h>
using namespace std;

int main(){
    string s = "Monster Verse";
    int len= s.size();
    cout << s[len-1];
    cout << s[0] << endl;

        string f;  //filter
        for(char c : s){
            if(isalnum(c)) { //Checks if c is an alphanumeric character (i.e., a letter or digit)
                f+= tolower(c);
            }
        }
        cout << f ;

    return 0;
}