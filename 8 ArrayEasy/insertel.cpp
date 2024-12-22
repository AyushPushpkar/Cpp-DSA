#include <iostream>
using namespace std;

void insertElement(int arr[], int& n, int pos, int value) {
    
    if (pos < 1 || pos > n + 1) {
        cout << pos << " Invalid position!" << endl;
        return ;
    }
    // Shift elements to the right to create space
    for (int i = n; i >= pos; i--) {
        arr[i] = arr[i - 1];
    }

    arr[pos - 1] = value;

    for (int i = 0; i < n+1; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    n++;
    cout << "curSize : " <<  n+1 << endl;

}

int main() {
    int n = 10, pos, value;

    // extra space for the new element
    int arr[n + 1] = { 2 ,3 ,5 ,8,10,22,69 , 92 ,101 , 133};

    insertElement(arr, n, pos = 3, value = 37);
    insertElement(arr, n, pos = 3, value = 71);
    insertElement(arr, n, pos = 14, value = 13);

    return 0;
}
