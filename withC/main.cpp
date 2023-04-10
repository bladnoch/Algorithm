#include <iostream>

struct Student{
    std::string stdName;
    double gpa;
    bool enrolled=true;
};

int main() {
//    const int SIZE = 4;
//    int diagonal[SIZE][SIZE];
//
//// 대각 요소를 1로, 나머지 요소를 0으로 초기화
//    for (int i = 0; i < SIZE; i++) {
//        for (int j = 0; j < SIZE; j++) {
//            diagonal[i][j] = (i == j) ? 1 : 0;
//        }
//    }
//    for (int i =0;i<SIZE;i++){
//        for(int j=0;j<SIZE;j++){
//            std::cout << diagonal[i][j] << " ";
//        }
//        std::cout<< "\n";
//    }
    Student std1;
    std1.gpa=4.31;
    std::cout<<std1.gpa<<"\n"<<std1.enrolled<<"\n";

    std::string name="Bro";
    int age=29;
    std::string freePizzas[5]={"pizza1","pizza2","pizza3","pizza4","pizza5"};


    std::string *pName=&name;
    int *pAge=&age;
    std::string *pFreePizzas=freePizzas;


    std::cout<<*pName<<"\n";
    std::cout<<*pAge;
    std::cout<<*pFreePizzas;

    return 0;
}
