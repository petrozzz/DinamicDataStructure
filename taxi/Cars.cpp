#include "Cars.h"

Car::Car(int id, string number, string color, string model) {
	this->id = id;
	this->number = number;
	this->color = color;
	this->model = model;
}

string Car::getInfo(){
	return color + " " + model + " number " + number;
}

Cars::Cars(){
	size = 0;
	cars = nullptr;
}

void Cars::addCar(Car car){
	if (size > 0) {
		Car* buff = new Car[size+1];
		for (int k = 0; k < size; ++k)
			buff[k] = cars[k];
		buff[size] = car;
		delete[] cars;
		cars = buff;
		size++;
	}
	else {
		cars = new Car[1];
		cars[0] = car;
		size++;
	}
}

void Cars::removeCar(int id){

}

string Cars::getInfo(int id){	
	return cars[id].getInfo();
}

int Cars::getSize()
{
	return size;
}

Car Cars::getCar(int id)
{
	return cars[id];
}
