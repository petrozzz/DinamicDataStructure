#ifndef STACK_H
#define STACK_H

#include <iostream>
#include "man.h"

template <typename T>
class Stack
{
    T* stack = nullptr;
    int maxCounter = 0;
    int counter = 0;
public:
    Stack(int counter){
        maxCounter = counter;
        stack = new T[maxCounter];
    }

    ~Stack(){
        if(stack != nullptr)
            delete[] stack;
    }

    Stack(const Stack& stack){
        maxCounter = stack.maxCounter;
        counter = stack.counter;
        this->stack = new T[maxCounter];
        for(int k =0; k < maxCounter; k++)
            this->stack[k] = stack.stack[k];
    }

    T& top() const {
        return stack[counter - 1];
    }

    bool empty(){
        return  !counter;
    }

    int size(){
        return counter;
    }

    void push(T& val){
        if(counter < maxCounter){
            stack[counter++] = val;
        } else {
            std::cout << "error, stack overflow";
        }
    }

    void push(T&& val){
        if(counter < maxCounter){
            stack[counter++] = val;
        } else {
            std::cout << "error, stack overflow";
        }
    }

    void emplace(T& val){
        if(counter < maxCounter){
            stack[counter++] = val;
        } else {
            std::cout << "error, stack overflow";
        }
    }

    void pop(){
        if(counter > 0)
            counter--;
    }    
};

template <typename T>
void showDataStructure(Stack<T> stack){
    while(!stack.empty()){
        std::cout << stack.top() << " ";
        stack.pop();
    }
    cout << std::endl;
}

void testStack(){
    std::cout << "Strat testStack" << std::endl;
    Stack<Man> stack(5);

    Man man1{"Ivan"};
    Man man2{"Alex"};
    Man man3{"Georg"};

    stack.push(man1);
    stack.push(man2);
    stack.push(man3);
    showDataStructure(stack);

    std::cout << "End testStack" << std::endl;
}

#endif // STACK_H
