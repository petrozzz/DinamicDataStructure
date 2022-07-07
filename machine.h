#ifndef MACHINE_H
#define MACHINE_H
#include <iostream>

using namespace std;

class Machine
{
private:
    string model;
    string color;
    string type;
    float price;
    float power;

public:
    Machine(string model, string color);
    float getPrice();
    void setPrice(float price);
    void showInfo();
};

#endif // MACHINE_H
