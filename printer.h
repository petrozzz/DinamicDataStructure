#ifndef PRINTER_H
#define PRINTER_H
#include "priorityqueue.h"
#include <string>
#include <time.h>
#include <iostream>

using namespace std;

class myPrinter;
class User;
class Doc;

class myTime : private tm{
public:
    myTime() {}
    myTime(int tm_mday, int tm_mon, int tm_year, int tm_hour, int tm_min = 0, int tm_sec = 0) {
        setTime(tm_mday, tm_mon, tm_year, tm_hour, tm_min, tm_sec);
    }

    void setTime(int tm_mday, int tm_mon, int tm_year, int tm_hour, int tm_min = 0, int tm_sec = 0){
        this->tm_mday = tm_mday;
        this->tm_mon = tm_mon;
        this->tm_year = tm_year;
        this->tm_hour = tm_hour;
        this->tm_min = tm_min;
        this->tm_sec = tm_sec;
    }

    friend ostream& operator <<(ostream& out, myTime& mytime){
        out << mytime.tm_mday << "-" << mytime.tm_mon << "-" << mytime.tm_year << " ";
        out << mytime.tm_hour << ":" << mytime.tm_min << ":" << mytime.tm_sec;
        return out;
    }
};

class Doc{
    string title;
    string text;
    User* user = nullptr;
    myTime* time = nullptr;
public:
    Doc() {}
    Doc(User* user, string title = "", string text = ""){
        this->user = user;
        time = new myTime(12, 1, 2022, 11, 34, 12);
        this->text = text;
        this->title = title;
    }

    ~Doc(){
        /*if(user)
            delete user;*/
        /*if(time)
            delete time;*/
    }

    friend ostream& operator <<(ostream& out, Doc& doc){
        out << *doc.time << " " << doc.title;
        return out;
    }

    void showText(ostream& out){
        out << this;
        out << text << endl;
    }
};

class User: Man{
private:
    int prioryty = 0;
    //myPrinter* printer;
public:
    User(/*myPrinter* printer,*/ int prioryty = 0){
        //this->printer = printer;
        this->prioryty = prioryty;
    }

    ~User(){  }

    Doc& createDoc(){
        Doc* doc = new Doc(this, "Doc1.docx", "Text1");
        return *doc;
    }

    void sendToPrint(Doc& doc, PriorityQueue<Doc>* printer){
        printer->push(doc, prioryty);
    }
};

class myPrinter: public PriorityQueue<Doc>{

public:
    myPrinter() : PriorityQueue<Doc>(20){
    }
};

void testPrinter(){
    myPrinter* printer = new myPrinter();
    User usr1(0);
    User usr2(2);
    User usr3(1);
    usr1.sendToPrint(usr1.createDoc(), printer);
    usr2.sendToPrint(usr2.createDoc(), printer);
    usr3.sendToPrint(usr3.createDoc(), printer);
    showDataStructure(PriorityQueue<Doc>(*printer));
}
#endif // PRINTER_H
