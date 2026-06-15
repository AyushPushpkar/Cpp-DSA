#include <bits/stdc++.h>
using namespace std;
/*
Problem:
Sum of beauty of all substrings.
*/

// TC: O(n²) | SC: O(1)
class Solution {
public:
    int beautySum(string s) {
        int totalBeauty = 0;
        int n = s.size();

        for (int i = 0; i < n; ++i) {
            vector<int> freq(26, 0);
            for (int j = i; j < n; ++j) {
                freq[s[j] - 'a']++;

                int maxFreq = 0, minFreq = INT_MAX;
                for (int k = 0; k < 26; ++k) {
                    if (freq[k] > 0) {
                        maxFreq = max(maxFreq, freq[k]);
                        minFreq = min(minFreq, freq[k]);
                    }
                }

                totalBeauty += (maxFreq - minFreq);
            }
        }

        return totalBeauty;
    }
};

int main() {
    Solution sol;
    string input;

    vector<string> testCases = {
        "aabcb",
        "aabcbaa",
        "abcd",
        "aaa",
        "abcabc",
        "leetcode",
        "xxyyzz"
    };

    for (const string& test : testCases) {
        cout << "Input: \"" << test << "\" => Beauty Sum: " << sol.beautySum(test) << endl;
    }
    return 0;
}
