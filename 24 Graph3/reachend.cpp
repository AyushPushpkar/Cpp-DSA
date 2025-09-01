#include <bits/stdc++.h>
using namespace std;

//! no negative weight
//? tc : o(ElogV)

class Solution
{
public:
    int minimumMultiplications(vector<int> &arr, int start, int end)
    {

        int mod = 100000;

        vector<int> dis(mod, INT_MAX);

        queue<pair<int, int>> q;
        q.push({0, start});
        dis[start] = 0;

        while (!q.empty())
        {
            int node = q.front().second;
            int dist = q.front().first;
            q.pop();

            for (int i = 0; i < arr.size(); i++)
            {
                int adjnode = (node * arr[i]) % mod;
                int wt = dist + 1;
                if (adjnode == end)
                    return wt;
                if (dis[adjnode] > wt)
                {
                    dis[adjnode] = wt;
                    q.push({dis[adjnode], adjnode});
                }
            }
        }

        return -1;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    Solution sol;
    vector<int> arr = {3, 4, 65};
    int start = 7;
    int end = 66175;

    int result = sol.minimumMultiplications(arr, start, end);
    cout << "Minimum multiplications: " << result << endl;

    return 0;
}
