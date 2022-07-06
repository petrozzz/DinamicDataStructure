#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <iostream>
#include "man.h"

using namespace std;

template <typename T>
struct Node {
    T value;
    Node* next = nullptr;
};

template <typename T>
class LinkedList{
    Node<T>* head = nullptr;
    int counter = 0;
public:
    LinkedList() {}
    LinkedList(T& object) {
        Node<T> *buff = new Node<T>{object};
        head = buff;
        counter++;
    }

    void addToHead(T& object){
        Node<T>* buff = new Node<T>{object, head};
        head = buff;
        counter++;
    }

    void addToTail(T& object){
        Node<T>* buff = head;
        while(buff->next != nullptr){
            buff = buff->next;
        }
        buff->next = new Node<T>{object};
        counter++;
    }

    void addToPos(T& object, int pos){
        if(counter > pos){
            Node<T>* buff = head;
            for(int k = 0; k < pos-1; k++){
                buff = buff->next;
            }            
            buff->next = new Node<T>{object, buff->next};
            counter++;
        }
    }

    void deleteFromHead(){
        if(counter){
            Node<T>* buff = head;
            head = head->next;
            delete buff;
            counter--;
        }
    }

    void deleteFromTail(){
        if(counter){
            Node<T>* buff = head;
            while(buff->next->next != nullptr){
                buff = buff->next;
            }
            delete buff->next;
            buff->next = nullptr;
            counter--;
        }
    }

    void deleteFromPos(int pos){
        if(counter > pos){
            Node<T>* buff = head;
            for(int k = 0; k < pos-1; k++){
                buff = buff->next;
            }
            Node<T>* buff2 = buff->next->next;
            delete buff->next;
            buff->next = buff2;
            counter--;
        }

    }

    void clear(){
        while(counter--)
            deleteFromHead();
    }

    void show(){
        if(counter){
            Node<T>* buff = head;
            while(buff->next != nullptr){
                cout << buff->value << " ";
                buff = buff->next;
            }
            cout << buff->value << endl;
        }
    }
};

void testLinkedList(){
    Man man1("Ivan1");
    Man man2("Ivan2");
    Man man3("Ivan3");
    Man man4("Ivan4");
    Man man5("Ivan5");

    LinkedList<Man> list(man1);
    list.addToHead(man2);
    list.addToHead(man3);
    list.show();
    list.addToTail(man4);
    list.show();
    list.addToPos(man5,1);
    list.show();
    list.deleteFromPos(0);
    list.show();
    list.deleteFromHead();
    list.show();
    list.deleteFromTail();
    list.show();
}
#endif // LINKEDLIST_H
