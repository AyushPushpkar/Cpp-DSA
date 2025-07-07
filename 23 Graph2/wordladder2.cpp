#include <bits/stdc++.h>
using namespace std;

vector<vector<string>> ladderLength(string beginWord, string endWord, vector<string>& wordList) {
    
    queue<vector<string>> q ;
    q.push({beginWord}) ;
    unordered_set<string> s(wordList.begin(), wordList.end()) ;

    vector<string> usedOnLevel ;
    usedOnLevel.push_back(beginWord) ; 

    vector<vector<string>> ans ;
    int level = 0 ;

    while (!q.empty()){
        vector<string> vec = q.front() ; 
        q.pop() ;
        
        if(vec.size() > level){
            level++ ;
            for(auto it : usedOnLevel){
                s.erase(it) ;
            }
            usedOnLevel.clear();
        }

        string word  = vec.back() ;

        if(word == endWord){
            if(ans.size() == 0){
                ans.push_back(vec) ;
            }
            else if(ans[0].size() == vec.size()){
                ans.push_back(vec) ;
            }
        }

        for(int i=0 ;i<word.size() ;i++){
            char original = word[i] ;

            for(char ch ='a' ;ch <= 'z' ;ch++){
                word[i] = ch ;
                if(s.find(word)!= s.end()){
                    vec.push_back(word) ;
                    q.push(vec) ;
                    usedOnLevel.push_back(word) ;
                    vec.pop_back() ;
                }
            }
            word[i] = original ;
        }
    }
    
    return ans;
}

int main() {
    string beginWord = "hit";
    string endWord = "cog";
    vector<string> wordList = {"hot", "dot", "dog", "lot", "log", "cog"};

    vector<vector<string>> result = ladderLength(beginWord, endWord, wordList);

    for(auto it : result){
        for(auto itt : it){
            if(itt == endWord) cout << itt ;
            else cout << itt <<  " -> " ; 
        }cout << endl ;
    }

    return 0;
}
