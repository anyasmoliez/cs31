#ifndef FREQ_FLYER_H
#define FREQ_FLYER_H
#include <string>
#include <iostream>
#include "PlaneFlight.h" 
using namespace std;
//Anya Smolentseva 305503018
class FrequentFlyerAccount {
private:
	string mName; //sets member variables as private
	double mBalance;

public:
	FrequentFlyerAccount(string name); //sets functions as public
	double getBalance();
	string getName();
	bool addFlightToAccount(PlaneFlight flight);
	bool canEarnFreeFlight(double mileage);
	bool freeFlight(string from, string to, double mileage, PlaneFlight& flight);

};



#endif 
