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
#include <QString>
#include "phonebook_with_proxy.h"
#include <stdio.h>
#include <sys/types.h>
#include <openssl/md5.h>

#include "taxi/main_taxi.h"
#include "FileClassifier/main_fileclassifier.h"

#include <QString>

using std::cout;
using std::cin;
using std::endl;

void testAll();

void getMD5(){
    QString str = "екатерина андреевна ермолина";
    unsigned char result[MD5_DIGEST_LENGTH];
    MD5((unsigned char*)str.data(), 26, result);
    for(int k = 0; k < MD5_DIGEST_LENGTH; ++k){
        printf("%02x", result[k]);
        if(k == 3 || k == 5 || k == 7  || k == 9)
            printf("%c", '-');

    }
    std::cout << std::endl;
}

#include "ttt.h"

int main(){
    //main_taxi();
    //getMD5();
    //testAll();    

    //testBynaryTree2();

    main_fileclassifier();
    //romb();
    //testArray();
    //showGraph();
    //    testPhoneBookWithProxy1();
    //    phonebook_with_proxy pb;
    //    pb.generate_dbfile(100000);
    //averSix();
    //testFunsString();

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
