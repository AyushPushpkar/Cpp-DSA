#include<bits/stdc++.h>
using namespace std ;

string frequencySort(string s) {

    unordered_map<char, int> freq;

    for (char c : s) {
        freq[c]++;
    }

    vector<pair<char, int>> chars(freq.begin(), freq.end());

    sort(chars.begin(), chars.end(), [](auto &a, auto &b) {
        return a.second > b.second;
    });

    string result;
        for (auto &p : chars) {
        char ch = p.first;
        int count = p.second;
        result.append(count, ch);
    }

    return result;
}

int main() {
    string input = "tree";
    string output = frequencySort(input);
    cout << "Sorted by frequency: " << output << endl;

    return 0;
}