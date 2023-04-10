#include <iostream>



int main() {
    const int SIZE = 4;
    int diagonal[SIZE][SIZE];

// 대각 요소를 1로, 나머지 요소를 0으로 초기화
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            diagonal[i][j] = (i == j) ? 1 : 0;
        }
    }
    for (int i =0;i<SIZE;i++){
        for(int j=0;j<SIZE;j++){
            std::cout << diagonal[i][j] << " ";
        }
        std::cout<< "\n";
    }

    return 0;
}
