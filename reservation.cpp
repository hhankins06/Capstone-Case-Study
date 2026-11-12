// reservation.cpp, this file references reservation.h

#include <iostream>
#include "reservation.h"
#include <string>
#include <ctime>

using namespace std;

Reservation::Reservation(int id, int facId, std::time_t start, std::time_t end)
{
	createdAt =
	reservationId = id;
	facilityId = facId;
	startTime =
	endTime =
	status = "pending";
	approved = false;
}

Reservation::~Reservation()
{
}

//Submit new reservation 
void Reservation::submit()
{
	cout << "To submit a new reservation, you will need "
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


	cin >> num;
	switch (num)
	{
	case 1:

	case 2:

	case 3:

	}

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
