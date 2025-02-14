#include<bits/stdc++.h>
using namespace std;

void explainSet() {
    set<int> st;
    // Stores unique elements in **sorted order** (Ascending)

    st.insert(2);    // O(log n)
    st.emplace(4);   // O(log n)

    auto it = st.find(3); // O(log n) → Returns iterator to `3` if found, else `st.end()`

    st.erase(2); // O(log n) → Removes element `2`

    int cnt = st.count(3); // O(log n) → Returns `1` if `3` exists, else `0`

    auto it1 = st.find(2);
    auto it2 = st.find(4);
    st.erase(it1, it2); // O(log n) → Erases elements in range `[it1, it2)`

    auto lb = st.lower_bound(2); // O(log n) → First element **>= 2**
    auto ub = st.upper_bound(4); // O(log n) → First element **> 4**
}

void multiSet() {
    multiset<int> ms;
    // Allows **duplicate elements** and stores in sorted order

    ms.insert(4);  // O(log n)

    ms.erase(1);   // O(log n) → Removes **all** occurrences of `1`

    auto cnt = ms.count(4); // O(log n) → Returns count of `4`

    ms.erase(ms.find(1)); // O(log n) → Removes **one occurrence** of `1`

    ms.erase(ms.find(3), next(ms.find(3), 2)); // O(log n) 
}

void Uset() {
    unordered_set<int> us;
    // Stores **unique elements** but **not sorted**
    // **O(1)** average time complexity, but **O(n) worst case**

    us.insert(3); // O(1)
    us.emplace(5); // O(1)
    us.erase(2); // O(1)
}

void explainMap() {
    map<int, int> mpp;
    map<int, pair<int, int>> mpp1;
    // Stores **unique keys** in **sorted order**

    mpp[1] = 3;  // O(log n) → Inserts {1, 3}
    mpp.emplace(3, 1); // O(log n)
    mpp.insert({2, 4}); // O(log n)

    for (auto it : mpp) {
        cout << it.first << " " << it.second << endl;
    }

    auto it = mpp.find(2); // O(log n) → Returns iterator to key `2`
    cout << (*it).second;
}

void Multimap() {
    multimap<int, int> mmp;
    // Allows **duplicate keys**, stores in **sorted order**

    mmp.insert({1, 2}); // O(log n)
    mmp.insert({1, 3}); // O(log n)
}

void Unorderedmap() {
    unordered_map<int, int> ump;
    // Stores **unique keys**, **not sorted**
    // **O(1)** average, **O(n)** worst case

    ump.insert({3, 2}); // O(1)
    ump.emplace(5, 7);  // O(1)
    ump.erase(3);       // O(1)
}





