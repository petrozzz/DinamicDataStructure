#include <iostream>
#include <fstream>
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
#include "exaptions.h"

#include <QString>
#include "phonebook_with_proxy.h"
#include <stdio.h>
#include <sys/types.h>

#include "taxi/main_taxi.h"
#include "FileClassifier/main_fileclassifier.h"

#include <QString>

using std::cout;
using std::cin;
using std::endl;

void testAll();
void testExaptions();

int main(){
    //main_taxi();
    //getMD5();
    //testAll();
    //testBynaryTree2();
    main_fileclassifier();
    //romb();
    //testArray();
    //showGraph();
    //testPhoneBookWithProxy1();
    //phonebook_with_proxy pb;
    //pb.generate_dbfile(100000);
    //averSix();
    //testFunsString();
}

void testExaptions(){
    testPriorityQueue();
    test_exaption();
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
