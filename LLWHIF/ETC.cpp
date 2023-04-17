#include <iostream>
using namespace std;

template<typename T>
class ChainNode{
public:
    T data;
    ChainNode<T>* link;
    ChainNode(){
        link=NULL;
    }
    ChainNode(T element){
        data=element;
        link=NULL;
    }

};

template<typename T>
class CircularLinkedList{
private:
    ChainNode<T>* head;

public:
    CircularLinkedList(){
        head = new ChainNode<T>();
        head->link=head;
    }

    ~CircularLinkedList(){
        ChainNode<T>* curr = head->link;
        while(curr!=head){
            ChainNode<T>* next=curr->link;
            delete curr;
            curr=next;
        }
        delete head;
    }
    void insertFront(const T& item){
        ChainNode<T>* newNode=new ChainNode<T>(item);
        newNode->link = head->link;
        head ->link= newNode;
    }
    void print()const{
        ChainNode<T>* curr=head->link;
        while(curr!=head){
            cout<< curr->data<<" ";
            curr=curr->link;
        }
        cout << endl;
    }
};

int main(){
    CircularLinkedList<int> cList;
    cList.insertFront(10);
    cList.insertFront(20);
    cList.insertFront(30);
    cList.insertFront(70);
    cList.insertFront(13);
    cList.print();
    return 0;
}
