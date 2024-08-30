#pragma once

#include <string>

using namespace std;

class Vehicle {
public:
	Vehicle(string vehicleCode, int capacity, double ticketPrice);
	Vehicle();
	virtual ~Vehicle() = 0;

	void addStop(string vehicleType, int stopID, string vehicleCode);
	void removeStop(string vehicleType, int stopID, string vehicleCode);

	string getVehicleCode();
	int getCapacity();
	double getTicketPrice();
	double getTotalProfit();

private:
	string vehicleCode;
	int capacity;
	double ticketPrice;
	double totalProfit;
};
