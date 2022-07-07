#ifndef GARAGE_H
#define GARAGE_H

#include <QString>
#include <iostream>

using namespace std;

void testGarage();

class Garage
{
    string* numBase = nullptr;
    int size;
    int count;

public:
    Garage(int size){
        this->size = size;
        delete[] numBase;
        numBase = new string[size];
        for(int k =0; k < size; k++){
            numBase[k] = "empty";
        }
        count = 0;
    }

    ~Garage(){
        delete[] numBase;
    }

    friend ostream& operator << (ostream& out, Garage & garage){
        int count = garage.size;
        for(int k = 0; k < count; k++ ){
            out << garage.numBase[k] << " ";
        }
        out << endl;
        return out;
    }

};

class Transport{

};

class Car:public Transport{

};

class Moto{

};

#endif // GARAGE_H
