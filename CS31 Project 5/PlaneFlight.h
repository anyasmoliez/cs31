#ifndef PLANE_FLIGHT_H
#define PLANE_FLIGHT_H
#include <string>
using namespace std;

//Anya Smolentseva 305503018
class PlaneFlight {
private:
	double mCost; //sets member variables as private
	string mFromCity;
	string mToCity;
	string mName;
	double mMileage;

public:
	PlaneFlight(string passengerName, string fromCity, string toCity, double cost, double mileage);
	
	
	double getCost(); //setting functions as public
	void setCost(double cost);

	double getMileage();
	void setMileage(double mileage);

	string getName();
	void setName(string name);

	string getFromCity();
	void setFromCity(string from);

	string getToCity();
	void setToCity(string to);

}; 





#endif
