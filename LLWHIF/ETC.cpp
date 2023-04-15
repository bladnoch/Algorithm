#include <iostream>
using namespace std;


template <typename T> class Chain;
template <typename T>

class ChainNode
{
private:
    T data;
    ChainNode<T>* link;
public:
    ChainNode(T element = 0, ChainNode* next = NULL) :data(element), link(next) {}
    friend Chain<T>; //link
//    template <typename T>
    friend ostream& operator<<(ostream& os, Chain<T>& c);
    void printNode() { cout << "Node<"<<data << ">"; }
};

template <typename T>
class Chain
{
private:
    ChainNode<T> *first;
public:
    Chain() {
        first = new ChainNode<T>; // head node
        first->link = first; // When a Chain is created at the first, there's only a head node, and the head node points out itself.
    }
    ~Chain() {
        ChainNode<T>* del = first->link;
        while (del != first) {
            first->link = del->link;
            del->printNode();
            cout << " is deleted" << endl;
            delete del;
            del = first->link;
        }
        cout << endl << "Destructor is executed successfully!" << endl;
    }
    bool isEmpty() {
        return first->link == first;
    }
    int Length() {
        int len = 0;
        ChainNode<T>* cur = first->link;
        while (cur != first) {
            len++;
            cur = cur->link;
        }
        return len;
    }
    int Search(const T& x)const {
        ChainNode<T>* cur = first->link;
        int idx = 1;
        first->data = x;
        while (cur->data != x) {
            cur = cur->link;
            idx++;
        }
        return ((cur == first) ? 0 : idx);
    }

    void InsertFront(const T& item) {
        ChainNode<T>* newNode = new ChainNode<T>(item);
        // (1 - 1) The link of newNode points out the original first node. (10 Points)
        // (1 - 2) The newNode will be a new first node. (10 Points)
    }

    void InsertRear(const T& item) {
        ChainNode<T>* newNode = new ChainNode<T>(item);
        // (2 - 1) The first node is stored at the *cur pointer. (10 Points)
        // (2 - 2) We will find the last node through the while loop, and the last node is stored at the *cur poniter. (20 Points)
        // (2 - 3) The newNode will be inserted after the last node. (10 Points)
        // (2 - 4) The last node should always point out the head node. (10 Points)
    }

    void Delete(int idx) {
        ChainNode<T>* cur = first->link;
        int count = 1;
        ChainNode<T>* del = first->link;
        while (count < idx - 1) {
            del = del->link;
            count++;

        }

        cur = del->link;

        del->link = cur->link;

        delete cur;
    }
//    template <typename T>
    friend ostream& operator<<(ostream& os, Chain<T>& c);
};



template <typename T>
ostream& operator<<(ostream& os, Chain<T>& c)
{
    ChainNode<T>* cur;
    for (cur = c.first->link; cur != c.first; cur = cur->link)
    {
        os << cur->data;
        if (cur->link != c.first)
            os << "->";
        else
            os << " ";
    }
    os << endl;
    return os;
}



int main(void)
{
    Chain<int> *a = new Chain<int>;
    int search, searchIdx;
    cout << "Inserting nodes using operation 'InsertFront':" << endl << endl;
    for (int i = 0; i < 3; i++) {

        a->InsertFront(i + 1);
        cout << *a << endl;
    }

    cout << endl << "Inserting nodes using operation 'InsertRear':" << endl << endl;
    for (int i = 0; i < 3; i++) {

        a->InsertRear((i + 1) * 2);
        cout << *a << endl;
    }


    cout << endl << "Print a Circular Linked List:" << endl << endl;
    cout << *a << endl;
    cout << endl << "Which data is searching for? : ";
    cin >> search;
    searchIdx = a->Search(search);
    cout << endl;
    if(searchIdx == 0) cout << "There's no data you wants to search!" << endl;
    else cout << search << " is at the index " <<searchIdx << endl;
    cout << endl;
    delete a;


    return 0;

}