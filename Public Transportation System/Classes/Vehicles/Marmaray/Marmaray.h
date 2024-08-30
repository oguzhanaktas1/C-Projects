#pragma once

#include "../Vehicle.h"

class Marmaray : public Vehicle {
public:
	Marmaray(string vehicleCode, int capacity, double ticketPrice);
	Marmaray();
	~Marmaray();

	static int getTotalMarmarayCount();

	void save();
	void clean(string VehicleCode);
	void edit(string vehicleCode, int capacity, double ticketPrice, string newVehicleCode, int newCapacity, double newTicketPrice);
	void search(string vehicleCode, int capacity, double ticketPrice);
	void showAll();

	int reloadMarmarayCount();

private:
	static int totalMarmarayCount;
};
