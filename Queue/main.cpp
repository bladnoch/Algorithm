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
                Node<T>* currNode = front;
                Node<T>* prevNode = NULL;
                while (currNode != NULL) {
                    if (newNode->data > currNode->data) {
                        break;
                    }
                    prevNode = currNode;
                    currNode = currNode->link;
                }
                if (prevNode == NULL) {
                    newNode->link = front;
                    front = newNode;
                }
                else if (currNode == NULL) {
                    rear->link = newNode;
                    rear = newNode;
                }
                else {
                    prevNode->link = newNode;
                    newNode->link = currNode;
                }
            }
        }
        queueSize++;
    }

    T pop()
    {
        Node<T> *popNode;
        T popData;
        // (2-1) Program an operation pop for type1 (10 Points)
        if (type == 1) {
        }
            // (2-2) Program an operation pop for type2 (30 Points)
        else {
            Node<T>* secondNode;
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