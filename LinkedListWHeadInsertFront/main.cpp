#include <iostream>

template <typename T>
class ChainNode {
public:
    T data;
    ChainNode<T>* link;
};

template <typename T>

class CircularLinkedList {
public:
    CircularLinkedList();
    void InsertFront(const T& item);
    void PrintList();
private:
    ChainNode<T>* head;
};

template <typename T>
CircularLinkedList<T>::CircularLinkedList() {
    head = nullptr;
}

template <typename T>
void CircularLinkedList<T>::InsertFront(const T& item) {
    ChainNode<T>* newNode = new ChainNode<T>();
    newNode->data = item;
    if (head == nullptr) {
        newNode->link = newNode;
        head = newNode;
    }
    else {
        newNode->link = head->link;
        head->link = newNode;
    }
}

template <typename T>
void CircularLinkedList<T>::PrintList() {
    if (head == nullptr) {
        std::cout << "List is empty.\n";
        return;
    }
    ChainNode<T>* curr = head->link;
    while (curr != head) {
        std::cout << curr->data << " ";
        curr = curr->link;
    }
    std::cout << curr->data << std::endl;
}

int main() {
    CircularLinkedList<int> list;
    list.InsertFront(1);
    list.InsertFront(2);
    list.InsertFront(3);
    list.PrintList();
    return 0;
}
