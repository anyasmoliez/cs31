#include "FrequentFlyerAccount.h"
#include "PlaneFlight.h"
#include <string>
#include <cassert>
#include <iostream>
using namespace std;

//Anya Smolentseva 305503018
int main() {
	//PlaneFlight f("Howard", "LAX", "LAS", 65.00, 285);
	//f.setName("Pixie");
	//f.setFromCity("CHI");
	//f.setToCity("BOS");
	//f.setCost(100);
	//f.setMileage(100);
	//assert(f.getName() == "Pixie");
	//assert(f.getFromCity() == "CHI");
	//assert(f.getToCity() == "BOS");
	//assert(f.getCost() == 100);
	//assert(f.getMileage() == 100);
	//PlaneFlight f("Howard", "LAX", "LAS", 65.00, 285);
	//f.setToCity("LAX");
	//f.setFromCity("LAS");
	//assert(f.getToCity() == "LAS");
	//assert(f.getFromCity() == "LAX");
	//
    PlaneFlight shortleg("Howard", "LAX", "LAS", 49.00, 285);
    PlaneFlight longleg("Howard", "LAS", "NYC", 399.00, 2800);
    PlaneFlight sample("Sample", "Sample", "Sample", 0, 1);
    FrequentFlyerAccount account("Howard");
    //
    assert(shortleg.getFromCity() == "LAX");
    assert(shortleg.getToCity() == "LAS");
    assert(shortleg.getName() == "Howard");
    assert(std::to_string(shortleg.getCost()) == "49.000000");
    assert(std::to_string(shortleg.getMileage()) == "285.000000");

    // account balance starts at zero...
    assert(std::to_string(account.getBalance()) == "0.000000");
    assert(account.getName() == "Howard");
    assert(account.canEarnFreeFlight(3300.00) == false);

    // flights add to an account balance
    assert(account.addFlightToAccount(shortleg) == true);  // returns true because the names match 
    assert(account.addFlightToAccount(longleg) == true);   // returns true because the names match
    assert(std::to_string(account.getBalance()) == "3085.000000");

     //free flights reduce an account balance
    if (account.canEarnFreeFlight(285))
    {
        assert(account.freeFlight("LAS", "LAX", 285, sample) == true);
        // Howard earned a free flight...
        assert(sample.getName() == "Howard");
        assert(std::to_string(sample.getCost()) == "0.000000");
        assert(sample.getFromCity() == "LAS");
        assert(sample.getToCity() == "LAX");
        assert(std::to_string(sample.getMileage()) == "285.000000");
        // account has been reduced for this free flight...
        assert(std::to_string(account.getBalance()) == "2800.000000");
    }
    else
    {
        assert(false);  // there are enough miles in the account...
    }

    // non-matching names are ignored
    //PlaneFlight muffin("Muffin", "LAX", "Doggie Heaven", 500, 500);
    //assert(account.addFlightToAccount(muffin) == false);
    //assert(std::to_string(account.getBalance()) == "2800.000000");
   
/*    PlaneFlight f("Howard", "LAX", "LAS", 65.00, 285);
    FrequentFlyerAccount account("Howard");
    account.addFlightToAccount(f); // balance: 0+285=285
    assert(account.getName() == "Howard");
    assert(std::to_string(account.getBalance()) == "285.000000");
    assert(account.canEarnFreeFlight(285));
    account.freeFlight("LAS", "LAX", 285, f);
    assert(f.getName() == "Howard");
    assert(f.getFromCity() == "LAS");
    assert(f.getToCity() == "LAX");
    assert(f.getCost() == 0);
    assert(f.getMileage() == 285);
    account.addFlightToAccount(f);
    assert(account.getBalance() == 0); */

    PlaneFlight mine("Anya", "ATL", "DTR", 0, 10); //tests that costs of zero, AKA free flights, don't add to balance
    FrequentFlyerAccount mine2("Anya");
    assert(mine2.getName() == "Anya"); //tests that getName works
    assert(mine2.getBalance() == 0); //tests that getBalance works
    mine2.addFlightToAccount(mine);
    assert(mine2.getBalance() == 0);


    PlaneFlight neighbor("Tom", "EUR", "ERO", 125, 98); //tests that non-matching names from PlaneFlight cannot be added to the account
    FrequentFlyerAccount neighbor2("Tom");
    neighbor.setName("Tommy");
    assert(neighbor.getName() == "Tommy");
    assert(neighbor2.addFlightToAccount(neighbor) == false);

    PlaneFlight yours("Annie", "ORG", "CAN", 50000, 25); //tests that toCity and fromCity cannot be the same
    FrequentFlyerAccount yours2("Annie");
    yours.setFromCity("CAN");
    yours.setToCity("CAN");
    assert(yours.getFromCity() == "ORG");
    assert(yours.getToCity() == "CAN");


    PlaneFlight person("Will", "LA", "GTOWN", 2500, 36); //tests that toCity and fromCity cannot be the same
    FrequentFlyerAccount person2("Will");
    person.setFromCity("LA");
    person.setToCity("LA");
    assert(person.getFromCity() == "LA");
    assert(person.getToCity() == "GTOWN");
    
    PlaneFlight p("Ted", "TEX", "CAN", 25, 55); // tests that toCity and fromCity cannot be the same
    FrequentFlyerAccount p2("Ted");
    p.setFromCity("CAN");
    p.setToCity("TEX");
    assert(p.getFromCity() == "TEX");
    assert(p.getToCity() == "CAN");


    PlaneFlight q("Lily", "LON", "ENG", 55, 66); //tests that cities can't be empty strings
    q.setFromCity("LON");
    q.setToCity("");
    assert(q.getFromCity() == "LON");
    assert(q.getToCity() == "ENG");
    q.setFromCity("");
    q.setToCity("BOS");
    assert(q.getFromCity() == "LON"); //tests that cities can't be empty strings
    assert(q.getToCity() == "BOS");


    PlaneFlight t("Jon", "KAN", "TXS", 100, 200); //testing that mileage subtracts correctly when free flight is earned
    FrequentFlyerAccount tA("Jon");
    assert(tA.getBalance() == 0);
    tA.addFlightToAccount(t);
    assert(tA.getBalance() == 200); //tests that balance is updated correctly when addFlight is called
    if (tA.canEarnFreeFlight(100))
    {
        tA.freeFlight("TXS", "KAN", 100, t);
        
        assert(tA.getBalance() == 100);
    }
    PlaneFlight k("Pam", "TDS", "POT", 55, 250);
    FrequentFlyerAccount kA("Pam");
    k.setCost(-400);
    k.setMileage(-2);
    assert(k.getCost() == -1); //tests that costs can't be less than 0
    assert(k.getMileage() == -1); //tests that mileage must be greater than 0
    kA.addFlightToAccount(k);
    assert(kA.getBalance() == 0); //tests that balance will not be updated if cost or mileage less than 0
 
 

    cerr << "all tests passed!" << endl;


    return (0);

}