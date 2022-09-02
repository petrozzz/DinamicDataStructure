#pragma once
#include <iostream>
#include "Cars.h"
#include "Drivers.h"
#include "Orders.h"
#include <vector>
using namespace std;

void showTaxiApp();

void main_taxi() {
	Cars cars;
    cars.addCar(Car(0, "223ru77", "Black", "Shkoda"));
    cars.addCar(Car(0, "123ru61", "Red", "Kia  "));
    cars.addCar(Car(0, "123ru61", "White", "Logan"));

	
	cout << "Cars: " << endl;
	for (int k = 0; k < cars.getSize(); ++k) {
		cout << cars.getInfo(k) << endl;
	}

	Drivers drivers;
	drivers.addDriver(Driver(0, "Ivan Semenych", "+79509504265"));
    drivers.addDriver(Driver(0, "Vasya Rymor", "+79889504465"));
	drivers.addDriver(Driver(0, "Ahmed Ramzanovich", "+79281112222"));
	
	cout << "Drivers: " << endl;
	for (int k = 0; k < drivers.getSize(); ++k) {
		cout << drivers.getInfo(k) << endl;
	}	

	std::vector<Order> ords;	
	ords.push_back(Order(0, "Lenina, 21", "Turmalin, 41", 4, 12, 0, cars.getCar(0), drivers.getDriver(0)));
    ords.push_back(Order(0, "Larina, 78", "Voroshilov, 12", 8, 17, 30, cars.getCar(1), drivers.getDriver(1)));
    ords.push_back(Order(0, "2-Krasn, 18", "Orbitalnaya, 13", 18, 6, 15, cars.getCar(2), drivers.getDriver(2)));
	
	cout << "Orders: " << endl;
	for (int k = 0; k < 3; ++k) {
		cout << ords[k].getInfo() << endl;
	}
}


void showTaxiApp() {
	cout << "     TAXI    " << endl;
	cout << "     Enter mode:      " << endl;
	cout << "     1 - Operator     " << endl;
	cout << "     2 - Administrator" << endl;
	int mode;
	cin >> mode;

	if (mode == 1) {

	}
	else {
		cout << "Enter password " << endl;
		int pass;
		cin >> pass;
		if (pass * 13 == 26) {

		}
	}
}
