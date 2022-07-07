#include <iostream>
#include <string>

#include "linkedlist.h"
#include "priorityqueue.h"
#include "printer.h"
#include "twicelinkedlist.h"
#include "bynarytree.h"
#include "realstudent.h"
#include "stack.h"
#include "queue.h"
#include "bracketbalancer.h"
#include "busstation.h"
#include "anysome.h"

using std::cout;
using std::cin;
using std::endl;

void testAll();

int main(){
    testAll();
}

void testAll(){
    testStack();                               cout << endl;
    testQueue();                               cout << endl;
    testLinkedList();                          cout << endl;
    testPriorityQueue();                       cout << endl;
    testTwiceLinkedList();                     cout << endl;
    testBynaryTree();                          cout << endl;
    testMarksBook();                           cout << endl;
    BracketBalacner::testBracketBalacner();    cout << endl;
    testBusStation();                          cout << endl;
    testPrinter();                             cout << endl;
}
