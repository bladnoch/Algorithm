#include <iostream>
#include <time.h>
using namespace std;
/**
 * make queue with differernt head node
 * @athour Doung uk Kim
 *
 */

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

        // type 1
        if (type == 1) {
            if (front == NULL) {
                front = newNode;
                rear = newNode;
            }
            else {
                rear->link = newNode;
                rear = newNode;
            }
        }
        // type 2
        else {
            if (front == NULL) {
                front = newNode;
                rear = newNode;
            }
            else {
                newNode->link = front;
                front = newNode;
            }
        }
        queueSize++;
    }


    T pop()
    {
        Node<T>* popNode;
        T popData;

        // type 1
        if (type == 1) {
            popNode = front;
            popData = front->data;
            front = front->link;
            delete popNode;
        }

        // type 2
        else {
            T popData = rear->data;
            if (front == rear) {
                delete front;
                front = NULL;
                rear = NULL;
            }
            else {
                Node<T>* secondNode = front;
                while (secondNode->link != rear) {
                    secondNode = secondNode->link;
                }
                rear = secondNode;
                secondNode = secondNode->link;
                delete secondNode;
                rear->link = NULL;
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