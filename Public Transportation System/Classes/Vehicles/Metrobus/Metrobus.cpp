#include <iostream>
#include <fstream>
#include <sstream>

#include "Metrobus.h"

int Metrobus::totalMetrobusCount = 0;

Metrobus::Metrobus(string vehicleCode, int capacity, double ticketPrice)
	: Vehicle(vehicleCode, capacity, ticketPrice) {
}

Metrobus::Metrobus() {
}

Metrobus::~Metrobus() {
}

void Metrobus::save() {
	ifstream fileRead;
	fileRead.open("metrobusses.txt", ios::in);
	if (!fileRead.fail()) {
		string tempVehicleCode;
		int tempCapacity;
		double tempTicketPrice;

		string line;
		while (getline(fileRead, line)) {
			stringstream ss(line);

			ss >> tempVehicleCode >> tempCapacity >> tempTicketPrice;

			if (tempVehicleCode == getVehicleCode() && tempCapacity == getCapacity() && tempTicketPrice == getTicketPrice()) {
				cout << "Metrobus already exists." << endl;
				fileRead.close();
				return;
			}
		}
	}
	fileRead.close();

	ofstream fileWrite;
	fileWrite.open("metrobusses.txt", ios::out | ios::app);
	if (fileWrite.fail()) {
		cout << "Error opening 'metrobusses.txt'" << endl;
		cout << "Metrobus is not saved." << endl;
		fileWrite.close();
		return;
	}

	fileWrite << getVehicleCode() << "\t" << getCapacity() << "\t" << getTicketPrice() << endl;;
	fileWrite.close();

	Metrobus::totalMetrobusCount = this->reloadMetrobusCount();
	return;
}

void Metrobus::clean(string VehicleCode) {
	ifstream fileRead;
	ofstream fileWrite;

	fileRead.open("metrobusses.txt", ios::in);
	if (fileRead.fail()) {
		cout << "Error opening 'metrobusses.txt'" << endl;
		cout << "Metrobus is not cleaned." << endl;
		fileRead.close();
		return;
	}

	fileWrite.open("tempMetrobusses.txt", ios::out);
	if (fileWrite.fail()) {
		cout << "Error opening 'tempMetrobusses.txt'" << endl;
		cout << "Metrobus is not cleaned." << endl;
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

	remove("metrobusses.txt");
	if (rename("tempMetrobusses.txt", "metrobusses.txt") != 0) {
		cout << "Error renaming 'metrobusses.txt'" << endl;
		cout << "Metrobus is not cleaned." << endl;
		return;
	}

	Metrobus::totalMetrobusCount = this->reloadMetrobusCount();
	return;
}

void Metrobus::edit(string vehicleCode, int capacity, double ticketPrice, string newVehicleCode, int newCapacity, double newTicketPrice) {
	ifstream fileRead;
	ofstream fileWrite;

	fileRead.open("metrobusses.txt", ios::in);
	if (fileRead.fail()) {
		cout << "Error opening 'metrobusses.txt'" << endl;
		cout << "Metrobus is not updated." << endl;
		fileRead.close();
		return;
	}

	fileWrite.open("tempMetrobusses.txt", ios::out);
	if (fileWrite.fail()) {
		cout << "Error opening 'tempMetrobusses.txt'" << endl;
		cout << "Metrobus is not updated." << endl;
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
		cout << "Metrobus not found." << endl;
		return;
	}

	remove("metrobusses.txt");
	if (rename("tempMetrobusses.txt", "metrobusses.txt") != 0) {
		cout << "Error updating 'metrobusses.txt'" << endl;
		cout << "Metrobus is not updated." << endl;
	}

	return;
}

void Metrobus::search(string vehicleCode, int capacity, double ticketPrice) {
	ifstream fileRead;
	fileRead.open("metrobusses.txt", ios::in);
	if (fileRead.fail()) {
		cout << "Error opening 'metrobusses.txt'" << endl;
		cout << "Metrobus is not searched." << endl;
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
			cout << "----- Metrobus " << number << " -----" << endl;
			cout << "Vehicle Code: " << tempVehicleCode << endl;
			cout << "Capacity: " << tempCapacity << endl;
			cout << "Ticket Price: " << tempTicketPrice << endl << endl;

			found = true;
			number++;
		}
	}

	if (!found) {
		cout << "Metrobus not found." << endl;
	}

	return;
}

void Metrobus::showAll() {
	ifstream fileRead;
	fileRead.open("metrobusses.txt", ios::in);
	if (fileRead.fail()) {
		cout << "Error opening 'metrobusses.txt'" << endl;
		cout << "Metrobus is not shown." << endl;
		fileRead.close();
		return;
	}

	string tempVehicleCode;
	int tempCapacity;
	double tempTicketPrice;

	int number = 1;
	string line;
	while (getline(fileRead, line)) {
		stringstream ss(line);

		ss >> tempVehicleCode >> tempCapacity >> tempTicketPrice;

		cout << "----- Metrobus " << number << " -----" << endl;
		cout << "Vehicle Code: " << tempVehicleCode << endl;
		cout << "Capacity: " << tempCapacity << endl;
		cout << "Ticket Price: " << tempTicketPrice << endl;
		cout << endl;

		number++;
	}

	return;
}


int Metrobus::reloadMetrobusCount() {
	ifstream fileRead;
	fileRead.open("metrobusses.txt", ios::in);
	if (fileRead.fail()) {
		cout << "Error opening 'metrobusses.txt'" << endl;
		cout << "Metrobus count is not reloaded." << endl;
		fileRead.close();
		return Metrobus::totalMetrobusCount;
	}

	string line;
	int lineCount = 0;
	while (getline(fileRead, line)) {
		lineCount++;
	}

	return lineCount;
}


int Metrobus::getTotalMetrobusCount() {
	return totalMetrobusCount;
}
