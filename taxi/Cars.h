#pragma once
#include <iostream>

using namespace std;

class Car{
	int id;
	string number;	
	string color;
	string model;

public:
	Car() {};
	Car(int id, string number, string color, string model);
	string getInfo();
};


class Cars {
	int size = 0;
	Car* cars = nullptr;

public:
	Cars();
	void addCar(Car car);
	void removeCar(int id);
	string getInfo(int id);
	int getSize();
	Car getCar(int id);
};
