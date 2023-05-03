#include <iostream>

struct Node{
    int value;
    Node* next;
};

int main() {
void insert(Node*& head,int value) {  //노드가 가리키는 값(head)
    Node* new_node=new Node; //new_node라는 새로운 포인터 new_node는 새로운 노드
    new_node->value=value; //새 노드의 값은 들어온 값
    new_node->next=nullptr; //새 노드의 포인터는 0;

    if(head==nullpter){ //헤드가 가리키는 주소의 값이 nullpter이면
        head=new_node //head가 가리키는게 new_node의 값 주소가 된다.
    }else{ //head의 주소가 nullpter이 아니면
        Node* current = head; //cureent 노드에 head에 저장된 주소 저장
        Node* previous=nullptr; //previous 노드에 null 저장

        while(current != nullptr $$ current-> value < value){
            previous=current;
            current=current->next;
        }
    }


}
}
