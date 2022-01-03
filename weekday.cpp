#include <iostream>
#include <string>
using namespace std;
// Anya Smolentseva 305503018

int main()
{
	int monthCode = 0;    //initialzing all variables and asking for the input for month, day, and year
	string month;
	cout << "Provide a month: ";
	getline(cin, month);

	int dayCode = 0;
	int day = 0;
	string weekDay = "s";
	cout << "Provide a day: ";
	cin >> day;

	int year = 0;
	int yearCode = 0;
	int centuryValue = 0;
	int centuryCode = 0;
	bool leapYear = true;
	cout << "Provide a year: ";
	cin >> year;

	if (!(month == "January" || month == "February" || month == "March" || month == "April" || month == "May" || month == "June" || month == "July" || month == "August" || month == "September" || month == "October"
		|| month == "November" || month == "December"))
	{
		cout << "Invalid month!";
		
	}


	else if (day > 31 || day < 1)
	{
		cout << "Invalid day!";
	}

	else if (year < 1 || year>3000)
	{
		cout << "Invalid year!";
	}
	
	else //if inputs do not meet any criteria of the above if statements, run the following code to correctly produce the day of the week
	{
		if (year % 4 == 0 && year % 100 != 0)
		{
			leapYear = true;
		}

		else if (year % 100 == 0 && year % 400 != 0)
		{
			leapYear = false;
		}

		else if (year % 100 == 0 && year % 400 == 0)
		{
			leapYear = true;
		}

		else if (year % 4 != 0)
		{
			leapYear = false;
		}

		// determining if the year is a leap year or not






		yearCode = ((year % 100) / 4) + (year % 100); //determining the year code, which will be used later on
		centuryValue = (year / 100) % 4; //determining the century value, which will be used to find the century code later on

		// determing the month code, each month has a code and the if statements determine that if the month is March for example, then the month code will be 4

		if (month == "January" || month == "October")
		{
			monthCode = 1;
		}
		if (month == "January" && leapYear == true)
		{
			monthCode = monthCode - 1;
		}
		if (month == "February" || month == "March" || month == "November")
		{
			monthCode = 4;
		}
		if (month == "February" && leapYear == true)
		{
			monthCode = monthCode - 1;
		}
		if (month == "April" || month == "July")
		{
			monthCode = 0;
		}
		if (month == "May")
		{
			monthCode = 2;
		}
		if (month == "June")
		{
			monthCode = 5;
		}
		if (month == "August")
		{
			monthCode = 3;
		}
		if (month == "September" || month == "December")
		{
			monthCode = 6;
		}

		// Century Code, using the calculated century values, determine the century code. Ex: if century value is 0, century code is -2.
		if (centuryValue == 0)
		{
			centuryCode = -2;
		}
		if (centuryValue == 1)
		{
			centuryCode = 3;
		}
		if (centuryValue == 2)
		{
			centuryCode = 1;
		}
		if (centuryValue == 3)
		{
			centuryCode = -1;
		}

		dayCode = (centuryCode + day + yearCode + monthCode) % 7;
		// Weekday! Use calculated dayCode (calculated from centuryCode, day, yearCode, and monthCode) to determine the weekday. Ex: If dayCode
		// is 1 or -6, then the weekDay is Monday.

		if (dayCode == 0)
		{
			weekDay = "Sunday";
		}

		if (dayCode == 1 || dayCode == -6)
		{
			weekDay = "Monday";
		}

		if (dayCode == 2 || dayCode == -5)
		{
			weekDay = "Tuesday";
		}
		if (dayCode == 3 || dayCode == -4)
		{
			weekDay = "Wednesday";
		}
		if (dayCode == 4 || dayCode == -3)
		{
			weekDay = "Thursday";
		}
		if (dayCode == 5 || dayCode == -2)
		{
			weekDay = "Friday";
		}
		if (dayCode == 6 || dayCode == -1)
		{
			weekDay = "Saturday";
		}
		// Finally, after calculating the weekDay, output the  following statement in order to tell the user what day of the week the given date is.



		cout << month << " " << day << ", " << year << " was a " << weekDay << "!" << endl;
	}

	
	
		
	
	
	
	
	return(0);
}



