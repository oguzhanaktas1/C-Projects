#include <iostream>
#include <fstream>
#include <sstream>

#include "Stop.h"

int Stop::totalStopCount = 0;

Stop::Stop(int stopID, string stopName)
	: stopID(stopID), stopName(stopName) {
}

Stop::Stop() {
}

Stop::~Stop() {
}

void Stop::save() {
	ifstream fileRead;
	fileRead.open("stops.txt", ios::in);
	if (!fileRead.fail()) {
		int tempStopID;
		string tempStopName;

		string line;
		while (getline(fileRead, line)) {
			stringstream ss(line);

			ss >> tempStopID >> tempStopName;

			if (tempStopID == this->stopID && tempStopName == this->stopName) {
				cout << "Stop already exists." << endl;
				fileRead.close();
				return;
			}
		}
	}
	fileRead.close();

	ofstream fileWrite;
	fileWrite.open("stops.txt", ios::out | ios::app);
	if (fileWrite.fail()) {
		cout << "Error opening 'stops.txt' file" << endl;
		cout << "Stop is not saved." << endl;
		fileRead.close();
		return;
	}

	fileWrite << this->stopID << "\t" << this->stopName << endl;
	fileWrite.close();

	Stop::totalStopCount = this->reloadStopCount();
	return;
}

void Stop::clean(int stopID) {
	ifstream fileRead;
	ofstream fileWrite;

	fileRead.open("stops.txt", ios::in);
	if (fileRead.fail()) {
		cout << "Error opening 'stops.txt' file" << endl;
		cout << "Stop is not cleaned." << endl;
		fileRead.close();
		return;
	}

	fileWrite.open("tempStops.txt", ios::out | ios::app);
	if (fileWrite.fail()) {
		cout << "Error opening 'tempStops.txt' file" << endl;
		cout << "Stop is not cleaned." << endl;
		fileRead.close();
		fileWrite.close();
		return;
	}

	int tempStopID;
	string tempStopName;

	string line;
	while (getline(fileRead, line)) {
		stringstream ss(line);

		ss >> tempStopID >> tempStopName;

		if (tempStopID != stopID) {
			fileWrite << tempStopID << "\t" << tempStopName << endl;
		}
	}

	fileRead.close();
	fileWrite.close();

	remove("stops.txt");
	if (rename("tempStops.txt", "stops.txt") != 0) {
		cout << "Error renaming 'tempStops.txt' file" << endl;
		cout << "Stop is not cleaned." << endl;
	}

	return;
}

void Stop::edit(int stopID, string stopName, int StopID, string StopName) {
	ifstream fileRead;
	ofstream fileWrite;

	fileRead.open("stops.txt", ios::in);
	if (fileRead.fail()) {
		cout << "Error opening 'stops.txt' file" << endl;
		cout << "Stop is not edited." << endl;
		fileRead.close();
		return;
	}

	fileWrite.open("tempStops.txt", ios::out | ios::app);
	if (fileWrite.fail()) {
		cout << "Error opening 'tempStops.txt' file" << endl;
		cout << "Stop is not edited." << endl;
		fileRead.close();
		fileWrite.close();
		return;
	}

	int tempStopID;
	string tempStopName;

	string line;
	while (getline(fileRead, line)) {
		stringstream ss(line);

		ss >> tempStopID >> tempStopName;

		if (tempStopID == stopID && tempStopName == stopName) {
			fileWrite << StopID << "\t" << StopName << endl;
		}
		else {
			fileWrite << tempStopID << "\t" << tempStopName << endl;
		}
	}

	fileRead.close();
	fileWrite.close();

	remove("stops.txt");
	if (rename("tempStops.txt", "stops.txt") != 0) {
		cout << "Error renaming 'tempStops.txt' file" << endl;
		cout << "Stop is not edited." << endl;
	}

	return;
}


void Stop::search(int stopID, string stopName) {
	ifstream fileRead;
	fileRead.open("stops.txt", ios::in);
	if (fileRead.fail()) {
		cout << "Error opening 'stops.txt' file" << endl;
		cout << "Stop is not shown." << endl;
		fileRead.close();
		return;
	}

	int tempStopID;
	string tempStopName;

	string line;
	while (getline(fileRead, line)) {
		stringstream ss(line);

		ss >> tempStopID >> tempStopName;

		if (tempStopID == stopID && tempStopName == stopName) {
			cout << "Stop ID: " << tempStopID << endl;
			cout << "Stop Name: " << tempStopName << endl;
			fileRead.close();
			return;
		}
	}

	cout << "Stop not found." << endl;
	fileRead.close();
	return;
}

void Stop::showAll() {
	ifstream fileRead;
	fileRead.open("stops.txt", ios::in);
	if (fileRead.fail()) {
		cout << "Error opening 'stops.txt' file" << endl;
		cout << "Stops are not shown." << endl;
		fileRead.close();
		return;
	}

	int tempStopID;
	string tempStopName;

	int lineCount = 1;
	string line;
	while (getline(fileRead, line)) {
		stringstream ss(line);

		ss >> tempStopID >> tempStopName;

		cout << "----- Stop " << lineCount << " -----" << endl;
		cout << "Stop ID: " << tempStopID << endl;
		cout << "Stop Name: " << tempStopName << endl << endl;

		lineCount++;
	}

	fileRead.close();
	return;
}


int Stop::reloadStopCount() {
	ifstream fileRead;

	fileRead.open("stops.txt", ios::in);
	if (fileRead.fail()) {
		cout << "Error opening 'stops.txt' file" << endl;
		cout << "Stop count is not reloaded." << endl;
		return Stop::totalStopCount;
	}

	string line;
	int lineCount = 0;
	while (getline(fileRead, line)) {
		lineCount++;
	}

	return lineCount;
}



int Stop::getStopID() {
	return this->stopID;
}

string Stop::getStopName() {
	return this->stopName;
}
