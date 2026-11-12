// reservation.cpp, this file references reservation.h

#include <iostream>
#include <string>
#include <ctime>
#include "reservation.h"

using namespace std;

Reservation::Reservation(int id, int facId, std::time_t start, std::time_t end, std::time_t created)
{
	createdAt = created;
	reservationId = id;
	facilityId = facId;
	startTime = start;
	endTime = end;
	status = "pending";
	approved = false;
}

Reservation::~Reservation()
{
}

//Submit new reservation 
void Reservation::submit()
{
	cout << "To submit a new reservation, you will need to input the desired start and end times for the reservation, the facility ID for the desired facility, and a unique reservation ID.\n Input each value as it is requested.\n";
	std::time_t time(std::time_t * date);
	createdAt = date;

	int id;
	int facId;
	int hour;
	int day;
	int month;
	int year;
	struct tm date;

	cout << "Please input the reservation ID for your reservation as an integer:\n"
	cin >> id;
	reservationId = id;

	cout << "Please input the facility ID for the facility your reservation will be in:\n";
	cin >> facId;
	facilityId = facId;

	cout << "Please input the start time for your reservation:\n";

	cout << "Please input the components of the start time for your reservation:\n";
	cout << "Year:\n";
	cin >> year;
	cout << "Month:\n";
	cin >> month;
	cout << "Day:\n";
	cin >> day;
	cout << "Hour:\n";
	cin >> hour;

	// Time struct definitions
	date.tm_year = year;
	date.tm_mon = month;
	date.tm_mday = day;
	date.tm_hour = hour;
	mktime(&date);
	startTime = date;

	cout << "Please input the end time for your reservation:\n";

	cout << "Please input the components of the end time for your reservation:\n";
	cout << "Year:\n";
	cin >> year;
	cout << "Month:\n";
	cin >> month;
	cout << "Day:\n";
	cin >> day;
	cout << "Hour:\n";
	cin >> hour;

	// Time struct definitions
	date.tm_year = year;
	date.tm_mon = month;
	date.tm_mday = day;
	date.tm_hour = hour;
	mktime(&date);
	endTime = date;

	status = "pending";
	approved = false;
	cout << "Your reservation has been created!\n";
}

//Modify reservation details
void Reservation::modify()
{
	cout << "What reservation would you like to modify? Please enter the reservation ID and the facility ID for your reservation: \n";
	cout << "Reservation ID: " << reservationId << endl;
	cout << "Facility ID: " << facilityId << endl;

	cout << "What would you like to change about your reservation? Please type the number that corresponds to your choice.\n";
	cout << "1. Start time of my reservation.\n";
	cout << "2. End time of my reservation.\n";
	cout << "3. The facility that is attached to my reservation.\n";

	int num;
	int facId;
	int hour;
	int day;
	int month;
	int year;
	struct tm date;

	cin >> num;
	switch (num)
	{
	case 1:
		cout << "Please input the start time for your reservation:\n";

		cout << "Please input the components of the start time for your reservation:\n";
		cout << "Year:\n";
		cin >> year;
		cout << "Month:\n";
		cin >> month;
		cout << "Day:\n";
		cin >> day;
		cout << "Hour:\n";
		cin >> hour;

		// Time struct definitions
		date.tm_year = year;
		date.tm_mon = month;
		date.tm_mday = day;
		date.tm_hour = hour;
		mktime(&date);
		startTime = date;
		break;
	case 2:
		cout << "Please input the end time for your reservation:\n";

		cout << "Please input the components of the end time for your reservation:\n";
		cout << "Year:\n";
		cin >> year;
		cout << "Month:\n";
		cin >> month;
		cout << "Day:\n";
		cin >> day;
		cout << "Hour:\n";
		cin >> hour;

		// Time struct definitions
		date.tm_year = year;
		date.tm_mon = month;
		date.tm_mday = day;
		date.tm_hour = hour;
		mktime(&date);
		endTime = date;
		break;
	case 3:
		cout << "Please input the new facility ID for the facility your reservation will be in:\n";
		cin >> facId;
		facilityId = facId;
		break;
	}

	cout << "Your reservation has been updated.\n";

}

//Cancel reservations
void Reservation::cancel()
{
	cout << "Would you like to cancel your reservation? (y/n)\n";
	char val;
	cin >> val;
	if (val == 'y' || val == 'Y')
	{
		cout << "Are you sure that you would like to cancel? (y/n)\n";
		char check;
		cin >> check;
		if (check == 'y' || check == 'Y'))
		{
			cout << "Okay, your reservation has been cancelled.\n";
			status = "cancelled";
			approved = false;
		}
		else
		{
			cout << "Okay, no update was made to your reservation.\n";
		}
	}
	else
	{
		cout << "Okay, no update was made to your reservation.\n";
	}
}

//Change status of reservation
void Reservation::updateStatus()
{
	cout << "Is this reservation approved? (y/n)\n";
	char val;
	cin >> val;
	if (val == 'y' || val == 'Y')
	{
		cout << "Reservation has been approved!\n";
		status = "approved";
		approved = true;
	}
	else
	{
		cout << "Reservation has been rejected.\n";
		status = "rejected";
		approved = false;
	}
}
