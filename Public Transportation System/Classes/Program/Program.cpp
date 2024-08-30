#include <iostream>
#include <sstream>

#include "Program.h"

using namespace std;

Program::Program() {
}

Program::~Program() {
}

void Program::run() {
	string temp;
	while (!this->isMainMenuQuit) {
		int mainM = mainMenu();
		switch (mainM) {
		case 1: {
			if (adminLogin()) {
				while (!this->isAdminMenuQuit) {
					bool adminM = adminMenu();
					if (!adminM) {
						cout << "Invalid input!" << endl;
					}
					cout << "Press anything to continue..." << endl;
					getline(cin, temp);
					continue;
				}
			}
			break;
		}

		case 2: {
			while (!this->isPassengerMenuQuit) {
				bool passengerM = passengerMenu();
				if (!passengerM) {
					cout << "Invalid input" << endl;
				}
				cout << "Press anything to continue..." << endl;
				getline(cin, temp);
				continue;
			}
			break;
		}

		case -1: {
			cout << "Invalid input!" << endl;
			cout << "Press anything to continue..." << endl;
			getline(cin, temp);
			break;
		}

		case 0: {
			cout << "Thanks for using the Public Transportation System!";
			isMainMenuQuit = true;
			break;
		}

		default: {
			cout << "Critical error occured.";
			isMainMenuQuit = true;
			break;
		}
		}
	}
}

int Program::mainMenu() {
	system("CLS");
	cout << "Welcome to the Public Transportation System by Enes Can Ozsoy and Oguzhan Aktas!" << endl;
	cout << "1 - Admin" << endl;
	cout << "2 - Passenger" << endl;
	cout << "0 - Quit" << endl;
	cout << "Enter your choice: ";
	string choice;
	getline(cin, choice);

	int choiceInt;
	istringstream iss(choice);
	if (!(iss >> choiceInt)) {
		return -1;
	}
	return choiceInt;
}

bool Program::adminLogin() {
	system("CLS");
	string password;

	cout << "Enter the password: ";
	getline(cin, password);

	return (password == PASSWORD);
}

bool Program::adminMenu() {
	system("CLS");;

	cout << "1 - Add bus" << endl;
	cout << "2 - Delete bus" << endl;
	cout << "3 - Update bus" << endl;
	cout << "4 - Search bus" << endl;
	cout << "5 - Display all buses" << endl << endl;

	cout << "6 - Add metrobus" << endl;
	cout << "7 - Delete metrobus" << endl;
	cout << "8 - Update metrobus" << endl;
	cout << "9 - Search metrobus" << endl;
	cout << "10 - Display all metrobuses" << endl << endl;

	cout << "11 - Add marmaray" << endl;
	cout << "12 - Delete marmaray" << endl;
	cout << "13 - Update marmaray" << endl;
	cout << "14 - Search marmaray" << endl;
	cout << "15 - Display all marmarays" << endl << endl;

	cout << "16 - Add stop" << endl;
	cout << "17 - Delete stop" << endl;
	cout << "18 - Update stop" << endl;
	cout << "19 - Search stop" << endl;
	cout << "20 - Display all stops" << endl << endl;

	cout << "21 - Add stop to a vehicle" << endl;
	cout << "22 - Delete stop from a vehicle" << endl << endl;

	cout << "0 - Quit" << endl;

	cout << "Enter your choice: ";
	string choice;
	getline(cin, choice);
	int menuSelection;
	stringstream iss(choice);
	if (!(iss >> menuSelection)) {
		return false;
	}

	string vehicleCode;
	string capacity;
	string ticketPrice;
	string totalProfit;

	string stopID;
	string stopName;

	switch (menuSelection) {
	case 1:
	case 6:
	case 11: {
		cout << "Enter the vehicle code: ";
		getline(cin, vehicleCode);

		cout << "Enter the capacity: ";
		getline(cin, capacity);
		istringstream iss1(capacity);
		int capacityInt;
		if (!(iss1 >> capacityInt)) {
			return false;
		}

		cout << "Enter the ticket price: ";
		getline(cin, ticketPrice);
		istringstream iss2(ticketPrice);
		double ticketPriceDouble;
		if (!(iss2 >> ticketPriceDouble)) {
			return false;
		}

		if (menuSelection == 1) {
			bus = Bus(vehicleCode, capacityInt, ticketPriceDouble);
			bus.save();
		}
		else if (menuSelection == 6) {
			metrobus = Metrobus(vehicleCode, capacityInt, ticketPriceDouble);
			metrobus.save();
		}
		else if (menuSelection == 11) {
			marmaray = Marmaray(vehicleCode, capacityInt, ticketPriceDouble);
			marmaray.save();
		}
		break;
	}

	case 2:
	case 7:
	case 12: {
		cout << "Enter the vehicle code: ";
		getline(cin, vehicleCode);

		if (menuSelection == 2) {
			bus = Bus();
			bus.clean(vehicleCode);
		}
		else if (menuSelection == 7) {
			metrobus = Metrobus();
			metrobus.clean(vehicleCode);
		}
		else if (menuSelection == 12) {
			marmaray = Marmaray();
			marmaray.clean(vehicleCode);
		}
		break;
	}

	case 3:
	case 8:
	case 13: {
		cout << "Enter the vehicle code: ";
		getline(cin, vehicleCode);

		cout << "Enter the capacity: ";
		getline(cin, capacity);
		istringstream iss1(capacity);
		int capacityInt;
		if (!(iss1 >> capacityInt)) {
			return false;
		}

		cout << "Enter the ticket price: ";
		getline(cin, ticketPrice);
		istringstream iss2(ticketPrice);
		double ticketPriceDouble;
		if (!(iss2 >> ticketPriceDouble)) {
			return false;
		}

		string newVehicleCode;
		string newCapacity;
		string newTicketPrice;

		cout << "Enter the new vehicle code: ";
		getline(cin, newVehicleCode);

		cout << "Enter the new capacity: ";
		getline(cin, newCapacity);
		istringstream iss3(newCapacity);
		int newCapacityInt;
		if (!(iss3 >> newCapacityInt)) {
			cout << "Invalid input" << endl;
			return false;
		}

		cout << "Enter the new ticket price: ";
		getline(cin, newTicketPrice);
		istringstream iss4(newTicketPrice);
		double newTicketPriceDouble;
		if (!(iss4 >> newTicketPriceDouble)) {
			cout << "Invalid input" << endl;
			return false;
		}

		if (menuSelection == 3) {
			bus = Bus();
			bus.edit(vehicleCode, capacityInt, ticketPriceDouble, newVehicleCode, newCapacityInt, newTicketPriceDouble);
		}
		else if (menuSelection == 8) {
			metrobus = Metrobus();
			metrobus.edit(vehicleCode, capacityInt, ticketPriceDouble, newVehicleCode, newCapacityInt, newTicketPriceDouble);
		}
		else if (menuSelection == 13) {
			marmaray = Marmaray();
			marmaray.edit(vehicleCode, capacityInt, ticketPriceDouble, newVehicleCode, newCapacityInt, newTicketPriceDouble);
		}
		break;
	}

	case 4:
	case 9:
	case 14: {
		cout << "Enter the vehicle code: ";
		getline(cin, vehicleCode);

		cout << "Enter the capacity: ";
		getline(cin, capacity);
		istringstream iss1(capacity);
		int capacityInt;
		if (!(iss1 >> capacityInt)) {
			return false;
		}

		cout << "Enter the ticket price: ";
		getline(cin, ticketPrice);
		istringstream iss2(ticketPrice);
		double ticketPriceDouble;
		if (!(iss2 >> ticketPriceDouble)) {
			return false;
		}

		if (menuSelection == 4) {
			bus = Bus();
			bus.search(vehicleCode, capacityInt, ticketPriceDouble);
		}
		else if (menuSelection == 9) {
			metrobus = Metrobus();
			metrobus.search(vehicleCode, capacityInt, ticketPriceDouble);
		}
		else if (menuSelection == 14) {
			marmaray = Marmaray();
			marmaray.search(vehicleCode, capacityInt, ticketPriceDouble);
		}
		break;
	}

	case 5:
	case 10:
	case 15: {
		if (menuSelection == 5) {
			bus = Bus();
			bus.showAll();
		}
		else if (menuSelection == 10) {
			metrobus = Metrobus();
			metrobus.showAll();
		}
		else if (menuSelection == 15) {
			marmaray = Marmaray();
			marmaray.showAll();
		}
		break;
	}

	case 16: {
		cout << "Enter the stop ID: ";
		getline(cin, stopID);
		istringstream iss(stopID);
		int stopIDInt;
		if (!(iss >> stopIDInt)) {
			return false;
		}

		cout << "Enter the stop name: ";
		getline(cin, stopName);

		stop = Stop(stopIDInt, stopName);
		stop.save();
		break;
	}

	case 17: {
		cout << "Enter the stop ID: ";
		getline(cin, stopID);
		istringstream iss(stopID);
		int stopIDInt;
		if (!(iss >> stopIDInt)) {
			return false;
		}

		stop = Stop();
		stop.clean(stopIDInt);
		break;
	}

	case 18: {
		cout << "Enter the stop ID: ";
		getline(cin, stopID);
		istringstream iss1(stopID);
		int stopIDInt;
		if (!(iss1 >> stopIDInt)) {
			return false;
		}

		cout << "Enter the stop name: ";
		getline(cin, stopName);

		string newStopID;
		string newStopName;

		cout << "Enter the new stop ID: ";
		getline(cin, newStopID);
		istringstream iss2(newStopID);
		int newStopIDInt;
		if (!(iss2 >> newStopIDInt)) {
			return false;
		}

		cout << "Enter the new stop name: ";
		getline(cin, newStopName);

		stop = Stop();
		stop.edit(stopIDInt, stopName, newStopIDInt, newStopName);
		break;
	}

	case 19: {
		cout << "Enter the stop ID: ";
		getline(cin, stopID);
		istringstream iss3(stopID);
		int stopIDInt;

		if (!(iss3 >> stopIDInt)) {
			return false;
		}

		cout << "Enter the stop name: ";
		getline(cin, stopName);

		stop = Stop();
		stop.search(stopIDInt, stopName);
		break;
	}

	case 20: {
		stop = Stop();
		stop.showAll();
		break;
	}

	case 21: {
		cout << "Which vehicle do you want to add stop to?" << endl;
		cout << "1 - Bus" << endl;
		cout << "2 - Metrobus" << endl;
		cout << "3 - Marmaray" << endl;

		cout << "Enter your choice: ";
		string vehicleType;
		getline(cin, vehicleType);
		istringstream iss1(vehicleType);
		int vehicleTypeInt;
		if (!(iss1 >> vehicleTypeInt)) {
			return false;
		}
		if (vehicleTypeInt < 1 || vehicleTypeInt > 3) {
			return false;
		}

		cout << "Enter the stop ID: ";
		getline(cin, stopID);
		istringstream iss2(stopID);
		int stopIDInt;
		if (!(iss2 >> stopIDInt)) {
			return false;
		}

		cout << "Enter the vehicle code: ";
		getline(cin, vehicleCode);

		if (vehicleTypeInt == 1) {
			bus = Bus();
			bus.addStop("busses", stopIDInt, vehicleCode);
		}
		else if (vehicleTypeInt == 2) {
			metrobus = Metrobus();
			metrobus.addStop("metrobusses", stopIDInt, vehicleCode);
		}
		else if (vehicleTypeInt == 3) {
			marmaray = Marmaray();
			marmaray.addStop("marmarays", stopIDInt, vehicleCode);
		}
		break;
	}

	case 22: {
		cout << "Which vehicle do you want to delete stop from?" << endl;
		cout << "1 - Bus" << endl;
		cout << "2 - Metrobus" << endl;
		cout << "3 - Marmaray" << endl;

		cout << "Enter your choice: ";
		string vehicleType;
		getline(cin, vehicleType);
		istringstream iss1(vehicleType);
		int vehicleTypeInt;
		if (!(iss1 >> vehicleTypeInt)) {
			return false;
		}
		if (vehicleTypeInt < 1 || vehicleTypeInt > 3) {
			return false;
		}

		cout << "Enter the stop ID: ";

		getline(cin, stopID);
		istringstream iss2(stopID);
		int stopIDInt;
		if (!(iss2 >> stopIDInt)) {
			return false;
		}

		cout << "Enter the vehicle code: ";
		getline(cin, vehicleCode);

		if (vehicleTypeInt == 1) {
			bus = Bus();
			bus.removeStop("busses", stopIDInt, vehicleCode);
		}
		else if (vehicleTypeInt == 2) {
			metrobus = Metrobus();
			metrobus.removeStop("metrobusses", stopIDInt, vehicleCode);
		}
		else if (vehicleTypeInt == 3) {
			marmaray = Marmaray();
			marmaray.removeStop("marmarays", stopIDInt, vehicleCode);
		}
		break;
	}

	case 0: {
		this->isAdminMenuQuit = true;
		cout << "Thanks for using our Public Transportation System!" << endl;
		exit(0);
		break;
	}

	default: {
		cout << "Critical error occured." << endl;
		return false;
	}
	}

	return true;
}

bool Program::passengerMenu() {
	system("CLS");;

	cout << "1 - Display all buses" << endl;
	cout << "2 - Display all metrobuses" << endl;
	cout << "3 - Display all marmarays" << endl;
	cout << "4 - Display all stops" << endl << endl;

	cout << "0 - Quit" << endl;

	cout << "Enter your choice: ";
	string choice;
	getline(cin, choice);
	int menuSelection;
	stringstream iss(choice);
	if (!(iss >> menuSelection)) {
		return false;
	}
	if (menuSelection < 0 && menuSelection > 4) {
		return false;
	}

	switch (menuSelection) {
	case 1: {
		bus = Bus();
		bus.showAll();
		break;
	}

	case 2: {
		metrobus = Metrobus();
		metrobus.showAll();
		break;
	}

	case 3: {
		marmaray = Marmaray();
		marmaray.showAll();
		break;
	}

	case 4: {
		stop = Stop();
		stop.showAll();
		break;
	}

	case 0: {
		this->isPassengerMenuQuit = true;
		cout << "Thanks for using our Public Transportation System!" << endl;
		exit(0);
		break;
	}

	default: {
		cout << "Critical error occured." << endl;
		return false;
	}
	}
}
