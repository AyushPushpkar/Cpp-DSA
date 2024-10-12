#include <iostream>
#include <vector>
using namespace std;

int main() {
    // Define the sparse matrix (4 x 5)
    int sparseMatrix[4][5] = {
        {0, 0, 3, 0, 4},
        {0, 0, 0, 0, 0},
        {0, 1, 0, 0, 0},
        {2, 0, 0, 0, 5}
    };

    // Vectors to store the triplet form
    vector<int> rowIndex;   // To store row indices
    vector<int> colIndex;   // To store column indices
    vector<int> values;     // To store non-zero values

    // Convert to triplet form
    for (int i = 0; i < 4; ++i) {       // Iterate over rows
        for (int j = 0; j < 5; ++j) {   // Iterate over columns
            if (sparseMatrix[i][j] != 0) {
                rowIndex.push_back(i);     // Store the row index
                colIndex.push_back(j);     // Store the column index
                values.push_back(sparseMatrix[i][j]); // Store the value
            }
        }
    }

    // Output the triplet representation
    cout << "Triplet :" << endl;
    cout << "Row\tCol\tVal" << endl;
    for (size_t i = 0; i < values.size(); i++) {
        cout << rowIndex[i] << "\t" << colIndex[i] << "\t" << values[i] << endl;
    }

    return 0;
}
