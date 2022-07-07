#ifndef QUEUE_H
#define QUEUE_H
#include <iostream>
#include "man.h"

template <typename T>
class Queue{
    T* queue = nullptr;
    int maxCounter = 0;
    int counter = 0;

public:
    Queue(int counter){
        maxCounter = counter;
        queue = new T[maxCounter];
    }

    ~Queue(){
        if(queue != nullptr)
            delete[] queue;
    }

    Queue(const Queue& queue){
        maxCounter = queue.maxCounter;
        counter = queue.counter;
        if(this->queue != nullptr)
            delete[] this->queue;
        this->queue = new T[maxCounter];
        for(int k = 0; k < maxCounter; k++){
            this->queue[k] = queue.queue[k];
        }
    }

    T& front() const{
        return queue[0];
    }

    T& back() const{
        return queue[counter - 1];
    }

    bool empty(){
        return !counter;
    }

    int size(){
        return counter;
    }

    void push(T& val){
        if(counter < maxCounter){
            queue[counter++] = val;
        } else {
            std::cout << "Error, queue overflow." << std::endl;
        }
    }

    void push(T&& val){
        if(counter < maxCounter){
            queue[counter++] = val;
        } else {
            std::cout << "Error, queue overflow." << std::endl;
        }
    }

    void emplace(T& val){
        if(counter < maxCounter){
            queue[counter++] = val;
        } else {
            std::cout << "Error, queue overflow." << std::endl;
        }
    }

    void pop(){
        if(counter > 0){
            for(int k =0; k < counter; k++){
                swap(queue[k], queue[k+1]);
            }
            counter--;
        }
    }
};

template <typename T>
void showDataStructure(Queue<T> queue){
    while(!queue.empty()){
        std::cout << queue.front() << " ";
        queue.pop();
    }
    cout << std::endl;
}

void testQueue(){
    std::cout << "Strat testQueue" << std::endl;
    Queue<Man> queue(5);

    Man man1{"Ivan"};
    Man man2{"Alex"};
    Man man3{"Georg"};

    queue.push(man1);
    queue.push(man2);
    queue.push(man3);
    showDataStructure(queue);

    std::cout << "End testQueue" << std::endl;
}
#endif // QUEUE_H

