#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
using namespace std;

class Student
{
private:
    string name;
    string group;
    float avMark;
    int* mathMarks = nullptr; // nullpnt or new int[0]
    int sizeMathMarks = 0;

public:
    Student();
    Student(string name, string group, float aver_val);
    Student(const Student& st2); // конструктор копирования

    ~Student();

    void operator = (const Student& st2);

    void setStudent(string name, string group, float aver_val);

    float getAvMark();
    void setAvMark(float val);

    void addMathMark(int val);
    bool changeMathMarks(int id, int val);

    void show();
    void showMathMarks();
};





#endif // STUDENT_H
