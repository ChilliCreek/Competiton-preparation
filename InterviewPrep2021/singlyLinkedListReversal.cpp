#include <iostream>

using namespace std;

template<typename T>
class LinkedListNode{
public:
    T data;
    LinkedListNode<T>* next = nullptr;
};

template<typename T>
class LinkedList{
public:
    LinkedListNode<T>* head;
    void print(){
        LinkedListNode<T>* curr = this->head;
        while(curr != nullptr){
            cout << curr->data << " ";
            curr = curr->next;
        }
        cout << endl;
    }
};

int main()
{
    LinkedList<int> ll;
    LinkedListNode<int> nodes[10];
    for(int i = 0; i < 10; ++i){
        nodes[i].data = i;
        if(i < 9){
            nodes[i].next = &nodes[i + 1];
        }
    }
    ll.head = &nodes[0];
    ll.print();
    LinkedListNode<int>* prev = nullptr;
    LinkedListNode<int>* curr = ll.head;
    LinkedListNode<int>* next = nullptr;
    while(curr != nullptr){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    ll.head = prev;
    ll.print();
    
    return 0;
}
