#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int myAtoi(string s) {
        int i = 0, n = s.size();
        while (i < n && s[i] == ' ') i++; 

        int sign = 1;
        if (i < n && (s[i] == '+' || s[i] == '-')) {
            sign = (s[i] == '-') ? -1 : 1;
            i++;
        }

        long result = 0;
        while (i < n && isdigit(s[i])) {
            result = result * 10 + (s[i] - '0');
            if (sign * result >= INT_MAX) return INT_MAX;
            if (sign * result <= INT_MIN) return INT_MIN;
            i++;
        }

        return static_cast<int>(sign * result);
    }
};

int main() {
    Solution sol;

    vector<string> testInputs = {
        "42",
        "   -42",
        "4193 with words",
        "words and 987",
        "-91283472332",
        "+123",
        "76-76",
        "00000-42a1234"
    };

    for (string input : testInputs) {
        cout << "Input: \"" << input << "\" => Output: " << sol.myAtoi(input) << endl;
    }

    return 0;
}
