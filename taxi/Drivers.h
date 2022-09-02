#pragma once
#include <iostream>

using namespace std;

class Driver
{
	int id;
	string name;
	string phone;

public:
	Driver() {};
	Driver(int id, string name, string phone);
	string getInfo();
};

class Drivers {
	int size = 0;
	Driver* drivers = nullptr;

public:
	Drivers();
	void addDriver(Driver driver);
	void removeDriver(int id);
	string getInfo(int id);
	int getSize();
	Driver getDriver(int id);
};