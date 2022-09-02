#include "Orders.h"


Order::Order(int id,
	string from,
	string to,
	int distance,
	int hour,
	int minute, 
	Car car,
	Driver driver) {
	this->id = id;
	this->from = from;
	this->to = to;
	this->distance = distance;
	this->hour = hour;
	this->minute = minute;
	this->car = car;
	this->driver = driver;
	calcPrice();
}


string Order::getInfo() {
    return id + "\t\t"
        + from + "\t\t"
        + to + "\t\t"
        + car.getInfo() + "\t\t"
        + driver.getInfo() + "\t\t"
        + to_string(price) + " rub.";
}

void Order::calcPrice() {
	price = distance * price_per_km;
	if (price < min_price)
		price = min_price;
	double tm = hour + minute / 60.0;
	if ((7.5 <= tm <= 10.5) || (17 <= tm <= 18.5)) {
		price *= 1.4;
	}
}

Orders::Orders()
{
	size = 0;
	orders = nullptr;
}

void Orders::addOrder(Order order){
	if (size > 0) {
		/*
		Order* buff = new Order[size + 1];
		for (int k = 0; k < size; ++k)
			buff[k] = orders[k];
		buff[size] = order;
		delete[] orders;
		orders = buff;
		size++;
		*/
	}
	else {
		/*
		orders = new Order[1];
		orders[0] = order;
		size++;
		*/
	}
}

void Orders::removeOrder(int id)
{
}

string Orders::getInfo(int id)
{
	return orders[id].getInfo();
}


int Orders::getSize()
{
	return size;
}
