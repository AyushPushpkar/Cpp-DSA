#include<bits/stdc++.h>
using namespace std;

void pass2(int* a, int n, int m) {
    // Access elements using a[i * m + j]
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << *(a + i * m + j) << " ";
        }
        cout << endl;
    }
    cout << endl ;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << a[i * m + j] << " ";  // Using array indexing
        }
        cout << endl;
    }
}

void pass(const vector<vector<int>>& v, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int n = 4, m = 4;
    vector<vector<int>> v = {
        {1, 1, 1, 1},
        {1, 0, 0, 1},
        {1, 1, 0, 1},
        {1, 1, 1, 1}
    };

    pass(v, n, m);

    cout << endl ;

    int a[4][4] = {
        {1, 1, 1, 1},
        {1, 0, 0, 1},
        {1, 1, 0, 1},
        {1, 1, 1, 1}
    };

    pass2(&a[0][0], n, m);

    return 0;
}
