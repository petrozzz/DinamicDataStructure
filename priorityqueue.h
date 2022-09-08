#ifndef PRIORITYQUEUE_H
#define PRIORITYQUEUE_H
#include <iostream>
#include "man.h"

template <typename T>
class PriorityQueue{
    T* queue = nullptr;
    int* priority = nullptr;
    int maxCounter = 0;
    int counter = 0;

public:
    PriorityQueue(int counter){
        maxCounter = counter;
        queue = new T[maxCounter];
        priority = new int[maxCounter];
    }

    ~PriorityQueue(){
        if(queue != nullptr)
            delete[] queue;
        if(priority != nullptr)
            delete[] priority;
    }

    PriorityQueue(const PriorityQueue& queue){
        maxCounter = queue.maxCounter;
        counter = queue.counter;
        if(this->queue != nullptr)
            delete[] this->queue;
        if(priority != nullptr)
            delete[] priority;
        this->queue = new T[maxCounter];
        this->priority = new int[maxCounter];
        for(int k = 0; k < counter; k++){
            this->queue[k] = queue.queue[k];
            this->priority[k] = queue.priority[k];
        }
    }

    T& front() const{
        return queue[0];
    }

    T& back() const{       
        return queue[counter - 1];
    }

    T& front(int& priority) const{
        priority = this->priority[0];
        return queue[0];
    }

    T& back(int& priority) const{
        priority = this->priority[counter - 1];
        return queue[counter - 1];
    }

    bool empty(){
        return !counter;
    }

    int size(){
        return counter;
    }

    void push(T& val, int priority = 0){
        if(counter < maxCounter){
            this->priority[counter] = priority;
            queue[counter++] = val;
            int k = counter-1;
            while((k > 0) && (this->priority[k] < this->priority[k-1])){
                swap(queue[k], queue[k-1]);
                swap(this->priority[k], this->priority[k-1]);
                k--;
            }
        } else {
            throw "Error, queue overflow.";
        }
    }

    void push(T&& val, int priority = 0){
        if(counter < maxCounter){
            this->priority[counter] = priority;
            queue[counter++] = val;
            int k = counter-1;
            while((k > 0) && (this->priority[k] < this->priority[k-1])){
                swap(queue[k], queue[k-1]);
                swap(this->priority[k], this->priority[k-1]);
                k--;
            }

        } else {
            throw "Error, queue overflow.";
        }
    }

    void emplace(T& val, int priority = 0){
        if(counter < maxCounter){
            this->priority[counter] = priority;
            queue[counter++] = val;
        } else {
            throw "Error, queue overflow.";
        }
    }

    void pop(){
        if(counter > 0){
            for(int k =0; k < counter; k++){
                swap(queue[k], queue[k+1]);
                swap(priority[k], priority[k+1]);
            }
            counter--;
        }
    }
};

template <typename T>
void showDataStructure(PriorityQueue<T> queue){
    int priority;
    while(!queue.empty()){
        std::cout << queue.front(priority) << "(";
        std::cout << priority << ") ";
        queue.pop();
    }
    cout << std::endl;
}

void testPriorityQueue(){
    std::cout << "Strat testPriorityQueue" << std::endl;

    try{
        PriorityQueue<Man> queue(5);

        Man man1{"Ivan"};
        Man man2{"Alex"};
        Man man3{"Georg"};

        queue.push(man1, 1);
        showDataStructure(queue);
        queue.push(man2, 0);
        showDataStructure(queue);
        queue.push(man3, 1);
        showDataStructure(queue);
        queue.push(man3, 1);
        queue.push(man3, 1);
        queue.push(man3, 1);
        queue.push(man3, 1);
    } catch(const char* exaption){
        cout << exaption << endl;
    }
    std::cout << "End testPriorityQueue" << std::endl;
}
#endif // PRIORITYQUEUE_H
