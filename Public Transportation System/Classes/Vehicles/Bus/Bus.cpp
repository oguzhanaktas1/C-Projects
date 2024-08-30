#include <iostream>
#include <fstream>
#include <sstream>

#include "Bus.h"

int Bus::totalBusCount = 0;

Bus::Bus(string vehicleCode, int capacity, double ticketPrice)
	: Vehicle(vehicleCode, capacity, ticketPrice) {
}

Bus::Bus() {
}

Bus::~Bus() {
}

void Bus::save() {
	ifstream fileRead;
	fileRead.open("busses.txt", ios::in);
	if (!fileRead.fail()) {
		string tempVehicleCode;
		int tempCapacity;
		double tempTicketPrice;

		string line;
		while (getline(fileRead, line)) {
			stringstream ss(line);

			ss >> tempVehicleCode >> tempCapacity >> tempTicketPrice;

			if (tempVehicleCode == getVehicleCode() && tempCapacity == getCapacity() && tempTicketPrice == getTicketPrice()) {
				fileRead.close();
				cout << "Bus already exists." << endl;
				return;
			}
		}
	}
	fileRead.close();

	ofstream fileWrite;
	fileWrite.open("busses.txt", ios::out | ios::app);
	if (fileWrite.fail()) {
		cout << "Error opening 'busses.txt'" << endl;
		cout << "Bus is not saved." << endl;
		fileWrite.close();
		return;
	}

	fileWrite << getVehicleCode() << "\t" << getCapacity() << "\t" << getTicketPrice() << endl;;
	fileWrite.close();

	Bus::totalBusCount = this->reloadBusCount();
	return;
}

void Bus::clean(string VehicleCode) {
	ifstream fileRead;
	ofstream fileWrite;

	fileRead.open("busses.txt", ios::in);
	if (fileRead.fail()) {
		cout << "Error opening 'busses.txt'" << endl;
		cout << "Bus is not cleaned." << endl;
		fileRead.close();
		return;
	}

	fileWrite.open("tempBusses.txt", ios::out);
	if (fileWrite.fail()) {
		cout << "Error opening 'tempBusses.txt'" << endl;
		cout << "Bus is not cleaned." << endl;
		fileRead.close();
		fileWrite.close();
		return;
	}

	string tempVehicleCode;
	int tempCapacity;
	double tempTicketPrice;

	string line;
	while (getline(fileRead, line)) {
		stringstream ss(line);

		ss >> tempVehicleCode >> tempCapacity >> tempTicketPrice;

		if (tempVehicleCode != VehicleCode) {
			fileWrite << tempVehicleCode << "\t" << tempCapacity << "\t" << tempTicketPrice << endl;
		}
	}

	fileRead.close();
	fileWrite.close();

	remove("busses.txt");
	if (rename("tempBusses.txt", "busses.txt") != 0) {
		cout << "Error renaming 'busses.txt'" << endl;
		cout << "Bus is not cleaned." << endl;
		return;
	}

	Bus::totalBusCount = this->reloadBusCount();
	return;
}

void Bus::edit(string vehicleCode, int capacity, double ticketPrice, string newVehicleCode, int newCapacity, double newTicketPrice) {
	ifstream fileRead;
	ofstream fileWrite;

	fileRead.open("busses.txt", ios::in);
	if (fileRead.fail()) {
		cout << "Error opening 'busses.txt'" << endl;
		cout << "Bus is not updated." << endl;
		fileRead.close();
		return;
	}

	fileWrite.open("tempBusses.txt", ios::out);
	if (fileWrite.fail()) {
		cout << "Error opening 'tempBusses.txt'" << endl;
		cout << "Bus is not updated." << endl;
		fileRead.close();
		fileWrite.close();
		return;
	}

	string tempVehicleCode;
	int tempCapacity;
	double tempTicketPrice;

	bool found = false;
	string line;
	while (getline(fileRead, line)) {
		stringstream ss(line);

		ss >> tempVehicleCode >> tempCapacity >> tempTicketPrice;

		if (!(tempVehicleCode == vehicleCode && tempCapacity == capacity && tempTicketPrice == ticketPrice)) {
			fileWrite << tempVehicleCode << "\t" << tempCapacity << "\t" << tempTicketPrice << endl;
		}
		else {
			fileWrite << newVehicleCode << "\t" << newCapacity << "\t" << newTicketPrice << endl;
			found = true;
		}
	}

	fileRead.close();
	fileWrite.close();

	if (!found) {
		cout << "Bus not found." << endl;
		return;
	}

	remove("busses.txt");
	if (rename("tempBusses.txt", "busses.txt") != 0) {
		cout << "Error updating 'busses.txt'" << endl;
		cout << "Bus is not updated." << endl;
	}

	return;
}

void Bus::search(string vehicleCode, int capacity, double ticketPrice) {
	ifstream fileRead;
	fileRead.open("busses.txt", ios::in);
	if (fileRead.fail()) {
		cout << "Error opening 'busses.txt'" << endl;
		cout << "Bus is not searched." << endl;
		fileRead.close();
		return;
	}

	string tempVehicleCode;
	int tempCapacity;
	double tempTicketPrice;

	bool found = false;
	int number = 1;
	string line;
	while (getline(fileRead, line)) {
		stringstream ss(line);

		ss >> tempVehicleCode >> tempCapacity >> tempTicketPrice;

		if (tempVehicleCode == vehicleCode && tempCapacity == capacity && tempTicketPrice == ticketPrice) {
			cout << "----- Bus " << number << " -----" << endl;
			cout << "Vehicle Code: " << tempVehicleCode << endl;
			cout << "Capacity: " << tempCapacity << endl;
			cout << "Ticket Price: " << tempTicketPrice << endl << endl;

			found = true;
			number++;
		}
	}

	if (!found) {
		cout << "Bus not found." << endl;
	}

	return;
}

void Bus::showAll() {
	ifstream fileRead;
	fileRead.open("busses.txt", ios::in);
	if (fileRead.fail()) {
		cout << "Error opening 'busses.txt'" << endl;
		cout << "Bus is not shown." << endl;
		fileRead.close();
		return;
	}

	string tempVehicleCode;
	int tempCapacity;
	double tempTicketPrice;

	int lineCount = 1;
	string line;
	while (getline(fileRead, line)) {
		stringstream ss(line);

		ss >> tempVehicleCode >> tempCapacity >> tempTicketPrice;

		cout << "----- Bus " << lineCount << " -----" << endl;
		cout << "Vehicle Code: " << tempVehicleCode << endl;
		cout << "Capacity: " << tempCapacity << endl;
		cout << "Ticket Price: " << tempTicketPrice << endl;
		cout << endl;

		lineCount++;
	}

	return;
}


int Bus::reloadBusCount() {
	ifstream fileRead;
	fileRead.open("busses.txt", ios::in);
	if (fileRead.fail()) {
		cout << "Error opening 'busses.txt'" << endl;
		cout << "Bus count is not reloaded." << endl;
		fileRead.close();
		return Bus::totalBusCount;
	}

	string line;
	int lineCount = 0;
	while (getline(fileRead, line)) {
		lineCount++;
	}

	return lineCount;
}


int Bus::getTotalBusCount() {
	return totalBusCount;
}
