#pragma once
#include "Cars.h"
#include "Drivers.h"

class Order
{
	int id;
	Car car = Car(0, "", "", "");
	Driver driver = Driver(0, "", "");
	int hour;
	int minute;
	int distance;
	string from;
	string to;
	int price;

	const double min_price = 53;
	const double price_per_km = 23;
	
	void calcPrice();

public: 
	Order() {};
	Order(int id,
		string from,
		string to,
		int distance,
		int hour,
		int minute,
		Car car,
		Driver driver);

	string getInfo();	
};

class Orders {
	int size = 0;
	Order* orders = new Order[0];

public:
	Orders();
	void addOrder(Order order);
	void removeOrder(int id);
	string getInfo(int id);
	int getSize();
};