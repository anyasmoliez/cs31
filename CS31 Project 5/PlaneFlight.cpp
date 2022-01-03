#include "PlaneFlight.h"
#include <string>
#include <iostream>
using namespace std;

//Anya Smolentseva 305503018
PlaneFlight::PlaneFlight(string passengerName, string fromCity, string toCity, double cost, double mileage) //do we initialize to var names or something else?
{
	if (passengerName != "") //if passenger name is valid, continue 
	mName = passengerName;


	if (!(fromCity == toCity || toCity == "" || fromCity == "")) { //if cities aren't matching/empty, continue

		mFromCity = fromCity;
		mToCity = toCity;
	}
	if (cost < 0) //if cost less than 0, store -1
		mCost = -1;
	else
		mCost = cost;

	if (mileage <= 0) //if mileage 0 of less, store -1
		mMileage = -1;
	else
		mMileage = mileage;
}


double PlaneFlight::getCost() { //returns corresponding cost
	return mCost;
}

void PlaneFlight::setCost(double cost) { //stores -1 for invalid costs
	if (cost < 0)
		mCost = -1;
	else
		mCost = cost;
}


double PlaneFlight::getMileage() { //returns corresponding mileage
	return mMileage;
}

void PlaneFlight::setMileage(double mileage) { //stores -1 for invalid mileage
	if (mileage <= 0)
		mMileage = -1;
	else
		mMileage = mileage;
}

string PlaneFlight::getName() { //returns valid name
	return mName;
}

void PlaneFlight::setName(string passengerName) {
	if (passengerName != "") //ignores empty strings
		mName = passengerName;

}


string PlaneFlight::getFromCity() { //returns valid city
	return mFromCity;
}

string PlaneFlight::getToCity() { //returns valid city
	return mToCity;
}

void PlaneFlight::setFromCity(string fromCity) { //ignores matching names and empty strings
	string temp = fromCity;
	if (mFromCity != mToCity && temp != mToCity && mFromCity != "" && temp!="")
		mFromCity = fromCity;


}

void PlaneFlight::setToCity(string toCity) { //ignores matching names and empty strings
	string temp = toCity;
	
	if (!(mToCity == mFromCity || temp==mFromCity || mToCity == "" || temp==""))
		mToCity = toCity;

}

