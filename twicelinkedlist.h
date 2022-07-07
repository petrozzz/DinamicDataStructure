#ifndef TWICELINKEDLIST_H
#define TWICELINKEDLIST_H
#include <iostream>
using namespace std;

template <typename T>
struct NodeTLL{
    T data;
    NodeTLL<T>* next = nullptr;
    NodeTLL<T>* prev = nullptr;
};

template <typename T>
class TwiceLinkedList{
    NodeTLL<T>* head = nullptr;
    NodeTLL<T>* tail = nullptr;
    int size =0;
    void create(T data){
        NodeTLL<T>* node = new NodeTLL<T>{data};
        head = node;
        tail = node;
    }
public:
    TwiceLinkedList() {}
    TwiceLinkedList(T data){
        create(data);
        size++;
    }

    void addToHead(T data){
        if(size){
            NodeTLL<T>* node = new NodeTLL<T>{data, head};
            head->prev = node;
            head = node;
        } else {
            create(data);
        }
        size++;
    }

    void addToTail(T data){
        if(size){
            NodeTLL<T>* node = new NodeTLL<T>{data, nullptr,tail};
            tail->next = node;
            tail = node;
        } else {
            create(data);
        }
        size++;
    }

    void removeFromHead(){
        size--;
    }

    void removeFromTail(){
        size--;
    }

    void printFromHead(){
        NodeTLL<T>* iter = head;
        for(int k = 0; k < size; k++){
            cout << iter->data << " ";
            iter = iter->next;
        }
    }
    void printFromTail(){
        NodeTLL<T>* iter = tail;
        for(int k = 0; k < size; k++){
            cout << iter->data << " ";
            iter = iter->prev;
        }
    }
};

void testTwiceLinkedList(){
    cout << "Start testTwiceLinkedList" << endl;
    TwiceLinkedList<int> list(4);
    list.addToHead(7);
    list.addToHead(8);
    list.printFromHead();
    cout << endl;
    list.addToTail(5);
    list.printFromHead();
    cout << endl;
    list.printFromTail();
    cout << endl;
    cout << "End testTwiceLinkedList" << endl;
}





#endif // TWICELINKEDLIST_H
