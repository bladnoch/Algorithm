#include <iostream>

using namespace std;

template typename <T>

upperTriangularMatrix<T>::set

int main() {
    int matrix[4][4] = {{1, 2, 3, 4}, {0, 5, 6, 7}, {0, 0, 8, 9}, {0, 0, 0, 10}};
    for (int i=0; i<4;i++){
        for (int j=0;j<4;j++){
            if (j>=i){
                cout << matrix[i][j] << " ";
                count++;
            }
            else{
                cout << "  ";
            }
        }
        cout <<"\n";
    }
    return 0;
}
