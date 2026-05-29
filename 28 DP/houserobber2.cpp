#include <bits/stdc++.h>
using namespace std;
/*
Problem:
House robber 2 - max sum of non-adjacent elements in circular array.
*/

// TC: O(n) | SC: O(1)
/*
Problem:
You are given an array `money` where money[i] represents the amount of money
in the i-th house. The houses are arranged in a circle.

Rules:
- You cannot rob two adjacent houses (security system constraint).
- The first house and the last house are adjacent.

Task:
Return the maximum amount of money that can be robbed without
robbing any two adjacent houses.
*/

//? max sum of non adjacent nodes
long long houseRobberOptimal(vector<int> &money)
{

    int n = money.size();

    int prev1 = money[0];
    int prev2 = 0;

    long long curr = LLONG_MIN;

    for (int i = 1; i < n; i++)
    {
        long long skip = prev1;
        long long take = money[i] + prev2;

        curr = max(skip, take);
        prev2 = prev1;
        prev1 = curr;
    }

    return prev1;
}

long long houseRobber2(vector<int> &money)
{
    int n = money.size();
    if (n == 1)
        return money[0];
    if (n == 2)
        return max(money[0], money[1]);

    vector<int> temp1, temp2;

    for (int i = 0; i < n; i++)
    {
        if (i == 0)
        {
            temp1.push_back(money[i]);
            continue;
        }
        if (i == n - 1)
        {
            temp2.push_back(money[i]);
            continue;
        }
        temp1.push_back(money[i]);
        temp2.push_back(money[i]);
    }

    return max(houseRobberOptimal(temp1), houseRobberOptimal(temp2));
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> nums = {2, 1, 4, 9};

    cout << houseRobber2(nums) << "\n";

    return 0;
}
