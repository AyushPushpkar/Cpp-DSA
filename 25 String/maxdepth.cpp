#include<bits/stdc++.h>
using namespace std ;

class Solution {
public:
    int maxDepth(string s) {
        int depth = 0, maxDepth = 0;
        for (char c : s) {
            if (c == '(') {
                depth++;
                maxDepth = max(maxDepth, depth);
            } else if (c == ')') {
                depth--;
            }
        }
        return maxDepth;
    }
};

int main() {
    Solution sol;
    string input;
    
    cout << "Enter a string with parentheses: ";
    getline(cin, input);  // Use getline to allow spaces and complex inputs

    int result = sol.maxDepth(input);
    cout << "Maximum nesting depth: " << result << endl;

    return 0;
}