#pragma once

#include <iostream>
#include <string>

#include "../Vehicles/Bus/Bus.h"
#include "../Vehicles/Marmaray/Marmaray.h"
#include "../Vehicles/Metrobus/Metrobus.h"
#include "../Stop/Stop.h"

using namespace std;

class Program {
public:
	Program();
	~Program();

	void run();

	int mainMenu();

	bool adminLogin();
	bool adminMenu();

	bool passengerMenu();

private:
	string PASSWORD = "ADMIN";

	bool isMainMenuQuit = false;
	bool isAdminMenuQuit = false;
	bool isPassengerMenuQuit = false;

	Bus bus;
	Marmaray marmaray;
	Metrobus metrobus;
	Stop stop;
};
