#pragma once

#include <string>

using namespace std;

class Stop {
public:
	Stop(int stopID, string stopName);
	Stop();
	~Stop();

	void save();
	void clean(int stopID);
	void edit(int stopID, string stopName, int StopID, string StopName);
	void search(int stopID, string stopName);
	void showAll();

	int reloadStopCount();

	int getStopID();
	string getStopName();

private:
	static int totalStopCount;

	int stopID;
	string stopName;
};
