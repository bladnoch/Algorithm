#include <iostream>
using namespace std;

const int ARRAY_SIZE = 10;
const int MATRIX_SIZE = 4;

int main() {
    int arr[ARRAY_SIZE]; // 1D array
    int sym_matrix[MATRIX_SIZE][MATRIX_SIZE] = {{2, 4, 6, 0}, {4, 1, 9, 5}, {6, 9, 4, 7}, {0, 5, 7, 0}}; // symmetric matrix

    // input values for 1D array
    cout << "Enter " << ARRAY_SIZE << " values for the 1D array:" << endl;
    for (int i = 0; i < ARRAY_SIZE; i++) {
        cin >> arr[i];
    }

    // output 1D array values
    cout << "1D array values:" << endl;
    for (int i = 0; i < ARRAY_SIZE; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // output symmetric matrix values
    cout << "Symmetric matrix values:" << endl;
    for (int i = 0; i < MATRIX_SIZE; i++) {
        for (int j = 0; j < MATRIX_SIZE; j++) {
            cout << sym_matrix[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
