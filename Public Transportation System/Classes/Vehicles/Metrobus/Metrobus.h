#pragma once

#include "../Vehicle.h"

class Metrobus : public Vehicle {
public:
	Metrobus(string vehicleCode, int capacity, double ticketPrice);
	Metrobus();
	~Metrobus();

	static int getTotalMetrobusCount();

	void save();
	void clean(string VehicleCode);
	void edit(string vehicleCode, int capacity, double ticketPrice, string newVehicleCode, int newCapacity, double newTicketPrice);
	void search(string vehicleCode, int capacity, double ticketPrice);
	void showAll();

	int reloadMetrobusCount();

private:
	static int totalMetrobusCount;
};
