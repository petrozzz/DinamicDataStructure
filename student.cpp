#include "student.h"
#include <iostream>

using namespace std;

#define SHOWCOSTRUCTORS 0

Student::Student(string name, string group, float aver_val){
    this->name = name;
    this->group = group;
    this->avMark = aver_val;
    //cout << "create obj. " << name.data() << endl;
}

Student::Student() {
    if(SHOWCOSTRUCTORS) cout << "create obj. " << name.data() << endl;
}

Student::~Student() {
    if(SHOWCOSTRUCTORS) cout << "delete obj. " << name.data() << endl;
    delete[] mathMarks;
}

Student::Student(const Student &st2) {
    if(SHOWCOSTRUCTORS) cout << "copy constructor" << endl;
    this->name = st2.name;
    this->group = st2.group;
    this->avMark = st2.avMark;
    this->sizeMathMarks = st2.sizeMathMarks;
    delete[] mathMarks;
    mathMarks = new int[sizeMathMarks];
    for (int k = 0; k < sizeMathMarks; k++) {
        mathMarks[k] = st2.mathMarks[k];
    }
}

void Student::operator =(const Student &st2) {
    if(SHOWCOSTRUCTORS) cout << "operator \"=\" " << endl;
    this->name = st2.name;
    this->group = st2.group;
    this->avMark = st2.avMark;
    this->sizeMathMarks = st2.sizeMathMarks;
    delete[] mathMarks;
    mathMarks = new int[sizeMathMarks];
    for (int k = 0; k < sizeMathMarks; k++) {
        mathMarks[k] = st2.mathMarks[k];
    }
}

void Student::addMathMark(int val) {
    int* buffer = new int[sizeMathMarks + 1];
    for (int k = 0; k < sizeMathMarks; k++) {
        buffer[k] = mathMarks[k];
    }
    buffer[sizeMathMarks] = val;
    sizeMathMarks++;
    delete [] mathMarks;
    mathMarks = buffer;
}

void Student::setStudent(string name, string group, float aver_val) {
    this->name = name;
    this->group = group;
    this->avMark = aver_val;
}

void Student::show() {
    cout << name.data() << " " << group.data() << " " << avMark << endl;
}

void Student::showMathMarks() {
    cout << "Math: ";
    for (int k = 0; k < sizeMathMarks; k++) {
        cout << mathMarks[k] << " ";
    }
    cout << endl;
}

float Student::getAvMark() {
    return avMark;
}

void Student::setAvMark(float val) {
    this->avMark = val;
}

bool Student::changeMathMarks(int id, int val) {
    if (id >= 0 && id < sizeMathMarks) {
        mathMarks[id] = val;
        return 1;
    }
    return 0;
}
#undef SHOWCOSTRUCTORS
