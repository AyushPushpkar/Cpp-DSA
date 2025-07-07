#include <bits/stdc++.h>
using namespace std;

int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
    
    queue<pair<string, int>> q ;
    q.push({beginWord,1}) ;
    unordered_set<string> s(wordList.begin(), wordList.end()) ;
    s.erase(beginWord) ;

    while (!q.empty()){
        string word = q.front().first ; 
        int steps = q.front().second ;
        q.pop() ;
        if(word == endWord) return steps ;

        for(int i=0 ;i<word.size() ;i++){
            char original = word[i] ;

            for(char ch ='a' ;ch <= 'z' ;ch++){
                word[i] = ch ;
                if(s.find(word)!= s.end()){
                    s.erase(word) ;
                    q.push({word , steps+1}) ;
                }
            }
            word[i] = original ;
        }
    }
    
    return 0;
}

int main() {
    string beginWord = "hit";
    string endWord = "cog";
    vector<string> wordList = {"hot", "dot", "dog", "lot", "log", "cog"};

    int result = ladderLength(beginWord, endWord, wordList);
    cout << "Shortest transformation sequence length: " << result << endl;

    return 0;
}
