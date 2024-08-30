#pragma once

#include "../Vehicle.h"

class Bus : public Vehicle {
public:
	Bus(string vehicleCode, int capacity, double ticketPrice);
	Bus();
	~Bus();

	static int getTotalBusCount();

	void save();
	void clean(string VehicleCode);
	void edit(string vehicleCode, int capacity, double ticketPrice, string newVehicleCode, int newCapacity, double newTicketPrice);
	void search(string vehicleCode, int capacity, double ticketPrice);
	void showAll();

	int reloadBusCount();

private:
	static int totalBusCount;
};
