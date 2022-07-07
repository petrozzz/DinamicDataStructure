#include "machine.h"

using namespace std;

Machine::Machine(string model, string color){
    this->model = model;
    this->color = color;
}

float Machine::getPrice(){
    return price;
}

void Machine::setPrice(float price){
    this->price = price;
}

void Machine::showInfo(){
    //cout << model << " " << color << " " << price << endl;
}
