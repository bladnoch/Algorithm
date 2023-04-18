#include <iostream>
using namespace std;
using std::cin;
using std::cout;


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
        ChainNode<T>* cur = first->link;
        while (cur != first) {
            cout << "Node<"<<cur->data << "> is deleted "<< endl;
            ChainNode<T>* next = cur->link;
            delete cur;
            cur = next;
        }
        delete first;


        cout << "\nDestructor is executed successfully!\n";
    }


    void insertFront(const T& item) {
        ChainNode<T>* newNode = new ChainNode<T>(item); //(10)(10/Null)
        newNode->link = first->link;                     // (10)(10/link=head의 주소)
        first->link = newNode;                           //head(/newNode)
    }


    void insertRear(const T& item) {
        ChainNode<T>* newNode = new ChainNode<T>(item);


        if (first->link == first) { // 리스트가 비어있는 경우
            first->link = newNode;
            newNode->link = first;
        } else {
            ChainNode<T>* cur = first->link;
            while (cur->link != first) { // 마지막 노드 찾기
                cur = cur->link;
            }
            cur->link = newNode; // 마지막 노드 다음에 새로운 노드 삽입
            newNode->link = first; // 새로운 노드가 첫 번째 노드를 가리키도록 설정
        }
    }

    void print() {
        ChainNode<T>* cur = first->link;
        cout << cur->data;
        cur = cur->link;
        while (cur != first) {
            cout << "->";
            cout << cur->data;
            cur = cur->link;
        }
        cout << endl << endl;
    }

    void Search(const T& x)const {
        ChainNode<T>* cur = first->link;
        int idx = 1;
        first->data = x;
        while (cur->data != x) {
            cur = cur->link;
            idx++;
        }
        if (cur==first){
            cout << "There's no Data your wants to search!\n\n";
        }
        else{
            cout << "It is in Node number " << idx << "\n\n";
        }
    }
};

int main() {
    CircularLinkedList<int> cLList;
    cout << "Inserting nodes using operation \"insertFront\":\n\n";
    cLList.insertFront(1);
    cLList.print();
    cLList.insertFront(2);
    cLList.print();
    cLList.insertFront(3);
    cLList.print();
    cout << "\n";

    cout << "Inserting nodes using operation \"insertRear\":\n\n";
    cLList.insertRear(2);
    cLList.print();
    cLList.insertRear(4);
    cLList.print();
    cLList.insertRear(6);
    cLList.print();

    cout << "Print a Circular Linked List:\n\n";
    cLList.print();

    cout << "Which data is searching for?: ";
    int get;
    cin >> get;
    cout << "\n";
    cLList.Search(get);
    return 0;
}
