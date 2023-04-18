#include <iostream>
using namespace std;

template <typename T>

class ChainNode {
public:
    T data;             //data: 데이타
    ChainNode<T>* link; //link: 포인더(주소)
    ChainNode() { link = NULL; }
    ChainNode(T element) { data = element; link = NULL; }

};

template <typename T>

class CircularLinkedList {

private:
    ChainNode<T>* first; //포인터 이름 head

public:
    CircularLinkedList() {  //처음 헤드 만들 때 실행
        first = new ChainNode<T>();
        first->link = first; //head의 링크 다 지정 해준다  head(/head본인의 주소)
    }
    ~CircularLinkedList() {
        ChainNode<T>* current = first->link;
        while (current != first) {
            ChainNode<T>* next = current->link;
            delete current;
            current = next;
        }
        delete first;
    }

    void insertFront(const T& item) {
        ChainNode<T>* newNode = new ChainNode<T>(item); //(10)(10/Null)
        newNode->link = first->link;                     // (10)(10/link=head의 주소)
        first->link = newNode;                           //head(/newNode)
    }

    void print() const {
        ChainNode<T>* current = first->link;
        while (current != first) {
            cout << current->data << " ";
            current = current->link;
        }
        cout << endl;
    }
};

int main() {
    CircularLinkedList<int> cLList;
    cLList.insertFront(10);
    cLList.insertFront(20);
    cLList.insertFront(5);
    cLList.insertFront(40);
    cLList.print();
    return 0;
}
