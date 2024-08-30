#include <iostream>
#include <fstream>
#include <sstream>

#include "Vehicle.h"

Vehicle::Vehicle(string vehicleCode, int capacity, double ticketPrice) {
	this->vehicleCode = vehicleCode;
	this->capacity = capacity;
	this->ticketPrice = ticketPrice;
	this->totalProfit = 0;
}

Vehicle::Vehicle() {
}

Vehicle::~Vehicle() {
}

void Vehicle::addStop(string vehicleType, int stopID, string vehicleCode) {
	ifstream fileReadVehiclesStops;
	ofstream fileWriteVehiclesStops;

	ifstream fileReadStop;
	ifstream fileReadVehicle;

	fileReadStop.open("stops.txt", ios::in);
	if (fileReadStop.fail()) {
		cout << "Error opening file stops.txt" << endl;
		cout << "Stop is not added." << endl;
		fileReadStop.close();
		return;
	}

	int tempStopID;
	string tempStopName;

	bool foundStop = false;
	string line;
	while (getline(fileReadStop, line)) {
		istringstream iss(line);
		iss >> tempStopID >> tempStopName;
		if (tempStopID == stopID) {
			foundStop = true;
			break;
		}
	}

	if (!foundStop) {
		cout << "Stop with ID " << stopID << " does not exist." << endl;
		cout << "Stop is not added." << endl;
		fileReadStop.close();
		return;
	}
	fileReadStop.close();

	fileReadVehicle.open(vehicleType + ".txt", ios::in);
	if (fileReadVehicle.fail()) {
		cout << "Error opening file " << vehicleType << ".txt" << endl;
		cout << "Stop is not added." << endl;
		fileReadVehicle.close();
		return;
	}

	string tempVehicleCode;
	int tempCapacity;
	double tempTicketPrice;

	bool foundVehicle = false;
	string line2;
	while (getline(fileReadVehicle, line2)) {
		istringstream iss(line2);
		iss >> tempVehicleCode >> tempCapacity >> tempTicketPrice;
		if (tempVehicleCode == vehicleCode) {
			foundVehicle = true;
			break;
		}
	}

	if (!foundVehicle) {
		cout << "Vehicle with code " << vehicleCode << " does not exist." << endl;
		cout << "Stop is not added." << endl;
		fileReadVehicle.close();
		return;
	}
	fileReadVehicle.close();

	fileReadVehiclesStops.open(vehicleType + "_stops.txt", ios::in);
	if (!fileReadVehiclesStops.fail()) {
		string tempVehicleCode2;
		int tempStopID2;

		string line3;

		while (getline(fileReadVehiclesStops, line3)) {
			stringstream ss(line3);

			ss >> tempVehicleCode2 >> tempStopID2;
			if (tempVehicleCode2 == vehicleCode && tempStopID2 == stopID) {
				cout << "Stop with ID " << stopID << " already exists for vehicle with code " << vehicleCode << endl;
				cout << "Stop is not added." << endl;
				fileReadVehiclesStops.close();
				return;
			}
		}
	}
	fileReadVehiclesStops.close();

	fileWriteVehiclesStops.open(vehicleType + "_stops.txt", ios::out | ios::app);
	if (fileWriteVehiclesStops.fail()) {
		cout << "Error opening file " + vehicleType + "_stops.txt" << endl;
		cout << "Stop is not added." << endl;
		fileWriteVehiclesStops.close();
		return;
	}

	fileWriteVehiclesStops << vehicleCode << "\t" << stopID << endl;
	fileWriteVehiclesStops.close();
	return;
}

void Vehicle::removeStop(string vehicleType, int stopID, string vehicleCode) {
	ifstream fileRead;
	ofstream fileWrite;

	fileRead.open(vehicleType + "_stops.txt", ios::in);
	if (fileRead.fail()) {
		cout << "Error opening file " + vehicleType + "_stops.txt" << endl;
		cout << "Stop is not removed." << endl;
		fileRead.close();
		return;
	}

	fileWrite.open(vehicleType + "_stops_temp.txt", ios::out | ios::app);
	if (fileWrite.fail()) {
		cout << "Error opening file " + vehicleType + "_stops_temp.txt" << endl;
		cout << "Stop is not removed." << endl;
		fileRead.close();
		fileWrite.close();
		return;
	}

	int tempStopID;
	string tempVehicleCode;

	string line;

	while (getline(fileRead, line)) {
		stringstream ss(line);

		ss >> tempVehicleCode >> tempStopID;
		if (!(tempVehicleCode == vehicleCode && tempStopID == stopID)) {
			fileWrite << tempVehicleCode << "\t" << tempStopID << endl;
		}
	}

	fileRead.close();
	fileWrite.close();

	remove((vehicleType + "_stops.txt").c_str());
	if (rename((vehicleType + "_stops_temp.txt").c_str(), (vehicleType + "_stops.txt").c_str()) != 0) {
		cout << "Error renaming file " + vehicleType + "_stops_temp.txt" << endl;
		cout << "Stop is not removed." << endl;
	}

	return;
}


string Vehicle::getVehicleCode() {
	return vehicleCode;
}

int Vehicle::getCapacity() {
	return capacity;
}

double Vehicle::getTicketPrice() {
	return ticketPrice;
}

double Vehicle::getTotalProfit() {
	return totalProfit;
}
