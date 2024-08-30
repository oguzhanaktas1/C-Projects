#include <iostream>
#include <fstream>
#include <sstream>

#include "Marmaray.h"

int Marmaray::totalMarmarayCount = 0;

Marmaray::Marmaray(string vehicleCode, int capacity, double ticketPrice)
	: Vehicle(vehicleCode, capacity, ticketPrice) {
}

Marmaray::Marmaray() {
}

Marmaray::~Marmaray() {
}

void Marmaray::save() {
	ifstream fileRead;
	fileRead.open("marmarays.txt", ios::in);
	if (!fileRead.fail()) {
		string tempVehicleCode;
		int tempCapacity;
		double tempTicketPrice;

		string line;
		while (getline(fileRead, line)) {
			stringstream ss(line);

			ss >> tempVehicleCode >> tempCapacity >> tempTicketPrice;

			if (tempVehicleCode == getVehicleCode() && tempCapacity == getCapacity() && tempTicketPrice == getTicketPrice()) {
				cout << "Marmaray already exists." << endl;
				fileRead.close();
				return;
			}
		}
	}
	fileRead.close();

	ofstream fileWrite;
	fileWrite.open("marmarays.txt", ios::out | ios::app);
	if (fileWrite.fail()) {
		cout << "Error opening 'marmarays.txt'" << endl;
		cout << "Marmaray is not saved." << endl;
		fileWrite.close();
		return;
	}

	fileWrite << getVehicleCode() << "\t" << getCapacity() << "\t" << getTicketPrice() << endl;;
	fileWrite.close();

	Marmaray::totalMarmarayCount = this->reloadMarmarayCount();
	return;
}

void Marmaray::clean(string VehicleCode) {
	ifstream fileRead;
	ofstream fileWrite;

	fileRead.open("marmarays.txt", ios::in);
	if (fileRead.fail()) {
		cout << "Error opening 'marmarays.txt'" << endl;
		cout << "Marmaray is not cleaned." << endl;
		fileRead.close();
		return;
	}

	fileWrite.open("tempMarmarays.txt", ios::out);
	if (fileWrite.fail()) {
		cout << "Error opening 'tempMarmarays.txt'" << endl;
		cout << "Marmaray is not cleaned." << endl;
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

	remove("marmarays.txt");
	if (rename("tempMarmarays.txt", "marmarays.txt") != 0) {
		cout << "Error renaming 'marmarays.txt'" << endl;
		cout << "Marmaray is not cleaned." << endl;
		return;
	}

	Marmaray::totalMarmarayCount = this->reloadMarmarayCount();
	return;
}

void Marmaray::edit(string vehicleCode, int capacity, double ticketPrice, string newVehicleCode, int newCapacity, double newTicketPrice) {
	ifstream fileRead;
	ofstream fileWrite;

	fileRead.open("marmarays.txt", ios::in);
	if (fileRead.fail()) {
		cout << "Error opening 'marmarays.txt'" << endl;
		cout << "Marmaray is not updated." << endl;
		fileRead.close();
		return;
	}

	fileWrite.open("tempMarmarays.txt", ios::out);
	if (fileWrite.fail()) {
		cout << "Error opening 'tempMarmarays.txt'" << endl;
		cout << "Marmaray is not updated." << endl;
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
		cout << "Marmaray not found." << endl;
		return;
	}

	remove("marmarays.txt");
	if (rename("tempMarmarays.txt", "marmarays.txt") != 0) {
		cout << "Error updating 'marmarays.txt'" << endl;
		cout << "Marmaray is not updated." << endl;
	}

	return;
}

void Marmaray::search(string vehicleCode, int capacity, double ticketPrice) {
	ifstream fileRead;
	fileRead.open("marmarays.txt", ios::in);
	if (fileRead.fail()) {
		cout << "Error opening 'marmarays.txt'" << endl;
		cout << "Marmaray is not searched." << endl;
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
			cout << "----- Marmaray " << number << " -----" << endl;
			cout << "Vehicle Code: " << tempVehicleCode << endl;
			cout << "Capacity: " << tempCapacity << endl;
			cout << "Ticket Price: " << tempTicketPrice << endl << endl;

			found = true;
			number++;
		}
	}

	if (!found) {
		cout << "Marmaray not found." << endl;
	}

	return;
}

void Marmaray::showAll() {
	ifstream fileRead;
	fileRead.open("marmarays.txt", ios::in);
	if (fileRead.fail()) {
		cout << "Error opening 'marmarays.txt'" << endl;
		cout << "Marmaray is not shown." << endl;
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

		cout << "----- Marmaray " << number << " -----" << endl;
		cout << "Vehicle Code: " << tempVehicleCode << endl;
		cout << "Capacity: " << tempCapacity << endl;
		cout << "Ticket Price: " << tempTicketPrice << endl;
		cout << endl;

		number++;
	}

	return;
}


int Marmaray::reloadMarmarayCount() {
	ifstream fileRead;
	fileRead.open("marmarays.txt", ios::in);
	if (fileRead.fail()) {
		cout << "Error opening 'marmarays.txt'" << endl;
		cout << "Marmaray count is not reloaded." << endl;
		fileRead.close();
		return Marmaray::totalMarmarayCount;
	}

	string line;
	int lineCount = 0;
	while (getline(fileRead, line)) {
		lineCount++;
	}

	return lineCount;
}

int Marmaray::getTotalMarmarayCount() {
	return totalMarmarayCount;
}
