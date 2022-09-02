#include "Drivers.h"

Driver::Driver(int id, string name, string phone) {
	this->id = id;
	this->name = name;
	this->phone = phone;
}

string Driver::getInfo() {
	return name + " " + phone;
}

Drivers::Drivers()
{
	size = 0;
	drivers = nullptr;
}

void Drivers::addDriver(Driver driver)
{
	if (size > 0) {
		Driver* buff = new Driver[size + 1];
		for (int k = 0; k < size; ++k)
			buff[k] = drivers[k];
		buff[size] = driver;
		delete[] drivers;
		drivers = buff;
		size++;
	}
	else {
		drivers = new Driver[1];
		drivers[0] = driver;
		size++;
	}
}

string Drivers::getInfo(int id)
{
	return drivers[id].getInfo();
}

int Drivers::getSize()
{
	return size;
}

Driver Drivers::getDriver(int id)
{
	return drivers[id];
}
