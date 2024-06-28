#include<bits/stdc++.h>
using namespace std ;

void arrayf(){
    const int rows = 3;
    const int cols = 4;
    int arr[rows][cols];

     // Take input for the array
    for(int i = 0; i < rows; ++i) {
        for(int j = 0; j < cols; ++j) {
            cin >> arr[i][j];
        }
    }

}

void vectorf(){
    const int rows = 3;
    const int cols = 4;
                                //size , members
    vector<vector<int>> v(rows, vector<int>(cols));

    // Print the array
    for(int i = 0; i < rows; ++i) {
        for(int j = 0; j < cols; ++j) {
            cout << v[i][j] << " ";
        }
        cout << endl;
    }

    vector<vector<int>> v2 ={
        {1,1,1,1},
        {1,0,0,1},
        {1,1,1,1}
    };


    // Size of rows
    int numRows = v2.size();

    // Size of columns (assuming all rows have the same number of columns)
    int numCols = v2.at(0).size();

    cout << "Number of rows: " << numRows << endl;
    cout << "Number of columns: " << numCols << endl;
}

int main() {

    vectorf();

    return 0;
}