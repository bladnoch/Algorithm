#include <iostream>
#include <time.h>
using namespace std;

#pragma warning (disable:4996)

template <typename T> class Queue;
template <typename T>

class Node
{
private:
    T data;
    Node<T>* link;

public:
    Node(T element = 0, Node* next = NULL) : data(element), link(next) {}
    friend Queue<T>;
};


template <typename T>
class Queue
{
private:
    Node<T>* front;
    Node<T>* rear;
    int queueSize;
    int type;

public:
    Queue(int t)
    {
        type = t;
        queueSize = 0;

        front = NULL;
        rear = NULL;
    }
    bool IsEmpty() { return queueSize == 0; }
    int GetSize() { return queueSize; }

    T ReadFront() {
        if (type == 1) return front->data;
        else return -1; //NULL
    }
    T ReadBack() {
        if (type == 1) return -1; //NULL
        else return rear->data;
    }

    void push(const T& item)
    {
        Node<T>* newNode = new Node<T>(item);

        // (1-1) Program an operation push for type1 (10 Points)
        if (type == 1) {
            if (IsEmpty()) {
                front = newNode;
                rear = newNode;
            }
            else {
                rear->link = newNode;
                rear = newNode;
            }
        }
            // (1-2) Program an operation push for type2 (30 Points)
        else {
            if (IsEmpty()) {
                front = newNode;
                rear = newNode;
            }
            else {
                Node<T>* newNode = new Node<T>(item);
                if (IsEmpty()) {
                    rear = newNode;
                    front = newNode;
                }
                else {
                    rear->link = newNode;
                    rear = newNode;
                }
            }
        }
        queueSize++;
    }


    T pop()
    {
        Node<T>* popNode;
        T popData;

        if (type == 1) {
            // Pop operation for type 1
            if (IsEmpty()) {
                cout << "Queue is empty" << endl;
                return -1; // NULL
            }
            else {
                Node<T>* temp = front;
                T popData = temp->data;
                front = front->link;
                delete temp;
                return popData;
            }
        }
        else {
            if (IsEmpty()) {
                cout << "Queue is empty!" << endl;
                return -1; // 노드가 없는 경우, 에러를 반환
            }
            else {
                Node<T>* temp = front;
                T popData = temp->data;
                if (front == rear) {
                    front = NULL;
                    rear = NULL;
                }
                else {
                    front = front->link;
                }
                delete temp;
                return popData;
            }
        }
        queueSize--;
        return popData;
    }
};


int main(void)
{
    Queue<int>* type1 = new Queue<int>(1);
    Queue<int>* type2 = new Queue<int>(2);

    for (int i = 0; i < 10000; i++) {
        type1->push(i);
    }

    for (int i = 0; i < 10000; i++) {
        type2->push(i);
    }


    // Compare the pop times of type1 and type2 when 10000 nodes are popped.

    clock_t start, end;
    double result;

    start = clock();
    for (int i = 0; i < 10000; i++) {
        type1->pop();
    }
    end = clock();
    result = (double)(end - start);

    cout << "type1 pop time : " << result << "ms" << endl;

    start = clock();
    for (int i = 0; i < 10000; i++) {
        type2->pop();
    }
    end = clock();
    result = (double)(end - start);

    cout << "type2 pop time : " << result << "ms" << endl;

    return 0;
}