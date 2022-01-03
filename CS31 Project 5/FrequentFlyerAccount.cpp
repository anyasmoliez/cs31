#include "PlaneFlight.h"
#include <string>
#include "FrequentFlyerAccount.h"
#include <iostream>
using namespace std;

//Anya Smolentseva 305503018
FrequentFlyerAccount::FrequentFlyerAccount(string name){
	mName = name;
	mBalance = 0.0;
	
}

double FrequentFlyerAccount::getBalance() { //returns correct balance
	return mBalance;
		
}

string FrequentFlyerAccount::getName() { //returns correct name
	return mName;
}


bool FrequentFlyerAccount::addFlightToAccount(PlaneFlight flight) { //only adds PlaneFlight to account if following validation rules are met
	
	if (flight.getMileage()>0 && flight.getName()!="" && mName == flight.getName() && flight.getCost()>0 && flight.getFromCity()!= flight.getToCity() && flight.getFromCity()!="" && flight.getToCity()!="") {
		mBalance +=flight.getMileage(); //increases the balance of the account when validation rules are met
		return true;
	}
	else
		return false;
}
bool FrequentFlyerAccount::canEarnFreeFlight(double mileage) {//able to earn free flights when mileage is positive and not greater than account balance
	if (mileage>0 && mileage<=mBalance)
		return true;
	else
		return false;
}

bool FrequentFlyerAccount::freeFlight(string from, string to, double mileage, PlaneFlight& flight) {//freeFlight when validation rules met
	if (from!=to && from!="" && to!="" && mileage>0 && mileage<=mBalance) {
	//	flight.setFromCity(from);
	//	flight.setToCity(to);
		flight.setCost(0.0); //changes object so its cost is 0 in PlaneFlight class
		mBalance = mBalance - mileage; //subtracts mileage from balance
		flight = PlaneFlight(mName, from, to, 0, mileage); //"stomps" over previous constructor parameters and creates new ones
		//flight.setName(mName);
		
		return true;
	}
	else
		return false;
}




