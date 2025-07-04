#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> roman = {
            {'I', 1}, {'V', 5}, {'X', 10},
            {'L', 50}, {'C', 100},
            {'D', 500}, {'M', 1000}
        };

        int result = 0;
        for (int i = 0; i < s.size(); i++) {
            if (i + 1 < s.size() && roman[s[i]] < roman[s[i + 1]]) {
                result -= roman[s[i]];
            } else {
                result += roman[s[i]];
            }
        }
        return result;
    }
};

int main() {
    Solution sol;
    string romanNumeral;

    cout << "Enter a Roman numeral (e.g. XIV, MCMXCIV): ";
    cin >> romanNumeral;

    int result = sol.romanToInt(romanNumeral);
    cout << "Integer value: " << result << endl;

    return 0;
}
